#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_struct.h"
#include "experiment.h"

QueueS * creerFileStruct(){
    QueueS* file_creer=malloc(sizeof(QueueS));
    //file_creer->debut=malloc(sizeof(Elem_FileStruct));
    //file_creer->fin=malloc(sizeof(Elem_FileStruct));
    //file_creer->fin->data=malloc(sizeof(experiment_t));
    //file_creer->debut->data=malloc(sizeof(experiment_t));
    file_creer->fin=NULL;
    file_creer->debut=NULL;
    return file_creer;
    
}


int estFileStructVide ( QueueS p ) {

    if (!(p.debut)){

        return 1;
    }
    return 0;



}

void enfileStruct ( QueueS * p , struct_t* data ) {
    Elem_FileStruct* new_element=malloc(sizeof(Elem_FileStruct));
    new_element->data=malloc(sizeof(struct_t));
    strcpy(new_element->data->name,data->name);
    new_element->data->time=data->time;
    new_element->precedent=NULL;
    printf("enfileStruct\n");
    
    if (!(p->debut)){
        printf("!(p->debut)\n");
        p->debut=new_element;
        p->fin=p->debut;
    }
    else if (p->fin==p->debut){
        printf("p->fin==p->debut\n");
        p->fin=new_element;
        p->debut->precedent= p->fin;
    }
    else{
        printf("normal\n");
       p->fin->precedent=new_element;
       
       p->fin=new_element;
    }
}

struct_t* defileStruct ( QueueS * p ){
    experiment_t* elem_suppr_data=malloc(sizeof(experiment_t));
    
    Elem_FileStruct* elem_file_suppr=p->debut;
    if (estFileStructVide(*p)){
        return NULL;
    }
    else{
        strcpy(elem_suppr_data->name,p->debut->data->name);
        elem_suppr_data->time=p->debut->data->time;
        printf("defileStruct\n");
        if (p->debut->precedent==p->fin){
            printf("p->debut->precedent==p->fin\n");
            
            p->debut=p->fin;
            free(elem_file_suppr->data);
            free(elem_file_suppr);
            return elem_suppr_data;
            
        }
        else if(p->debut==p->fin){
            printf("p->debut==p->fin\n");
            //free(p->debut->data);
            free(elem_file_suppr->data);
            free(p->debut);
            p->debut=NULL;
            p->fin=NULL;
            return NULL;
        }
        else{
            printf("normal\n");
            p->debut=p->debut->precedent;
            free(elem_file_suppr->data);
            free(elem_file_suppr);

            
            return elem_suppr_data;
        }  
        
    }

}

struct_t teteFileStruct ( QueueS p ){
    if (estFileStructVide(p)){
        struct_t data_temp;
        data_temp.name[0]='0';
        data_temp.time=0;
        return data_temp;

    }
    else{
        return *(p.debut->data);
    }

}


void afficheFileStruct ( QueueS p , void (*f)(struct_t*) ){
    Elem_FileStruct* elem_iter=p.debut;
    //int i=0;
    while (elem_iter){
        (*f)(elem_iter->data);
        elem_iter=elem_iter->precedent;
        //printf("%d\n",i);
        //i++;
    }

}
void freeFileStruct( QueueS *p ){
    while (defileStruct(p));
}