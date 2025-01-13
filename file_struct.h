# ifndef FILE_STRUCT_H
# define FILE_STRUCT_H

#include "experiment.h"

/* La définition de la structure */
//#include "experiment.h"
typedef experiment_t struct_t;

//typedef int struct_t;
/* Définition de la file*/
typedef struct e_file_s
{
  struct_t * data ;
  struct e_file_s * precedent ;
} Elem_FileStruct ;

/* Une file est un pointeur vers son premier element et son dernier élément*/
typedef struct 
{
  Elem_FileStruct * debut;
  Elem_FileStruct * fin;
} QueueS ;

/* créer une file vide */
QueueS * creerFileStruct();

/* Teste si la file est vide */
int estFileStructVide ( QueueS p ) ;

/* Ajoute l'element donnée en fin de la file */

void enfileStruct ( QueueS * p , struct_t* data ) ;

/* Supprime et retourne le premier element de la file et retourne NULL si
   la file est vide */
struct_t* defileStruct ( QueueS * p ) ;

/* Retourne la valeur du premier element de la file sans le supprimer
assertio est fausse si la file est vide */
struct_t teteFileStruct ( QueueS p ) ;

/* Affiche la file en entier pour les tests*/
void afficheFileStruct ( QueueS p , void (*f)(struct_t*) ) ;

/* Libère la mémoire */
void freeFileStruct( QueueS *p );

# endif