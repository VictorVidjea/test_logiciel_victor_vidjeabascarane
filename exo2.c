#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <stdlib.h>
#include "file_struct.h"
#include "experiment.h"

// Prototypes des fonctions à tester

// Test de la fonction `enfileStruct`
void test_enfileStruct() {
    QueueS* file = creerFileStruct();
    struct_t data1 = {100,"Element1"};
    struct_t data2 = {200,"Element2"};

    enfileStruct(file, &data1);
    CU_ASSERT_FALSE(estFileStructVide(*file));
    CU_ASSERT_STRING_EQUAL(file->debut->data->name, "Element1");
    CU_ASSERT_EQUAL(file->debut->data->time, 100);

    enfileStruct(file, &data2);
    CU_ASSERT_STRING_EQUAL(file->fin->data->name, "Element2");
    CU_ASSERT_EQUAL(file->fin->data->time, 200);

    freeFileStruct(file);
    free(file);
}

// Test de la fonction `defileStruct`
void test_defileStruct() {
    QueueS* file = creerFileStruct();
    struct_t data1 = {100,"Element1"};
    struct_t data2 = {200,"Element2"};

    enfileStruct(file, &data1);
    enfileStruct(file, &data2);

    struct_t* defile1 = defileStruct(file);
    CU_ASSERT_STRING_EQUAL(defile1->name, "Element1");
    CU_ASSERT_EQUAL(defile1->time, 100);
    free(defile1);

    

    CU_ASSERT_TRUE(estFileStructVide(*file));

    freeFileStruct(file);
    free(file);
}

// Fonction principale pour exécuter les tests
int main() {
    // Initialisation du registre CUnit
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Création d'une suite de tests
    CU_pSuite suite = CU_add_suite("Tests enfileStruct et defileStruct", 0, 0);
    if (!suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Ajout des tests à la suite
    if (!CU_add_test(suite, "Test enfileStruct", test_enfileStruct) ||
        !CU_add_test(suite, "Test defileStruct", test_defileStruct)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Exécution des tests en mode basique
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Nettoyage du registre
    CU_cleanup_registry();
    return 0;
}
