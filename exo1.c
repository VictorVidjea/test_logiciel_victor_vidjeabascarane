#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <stdio.h>
#include <stdlib.h>

void trois_plus_grandes_valeurs(int* tableau, int taille, int* result) {
    

    result[0] = -1;
    result[1] = -1;
    result[2] = -1;
}

int est_premier(int n) {
    
    return -1; // Premier
}


void test_trois_plus_grandes_valeurs() {
    int tableau1[] = {10, 4, 7, 3, 12, 5};
    int result[3];
    trois_plus_grandes_valeurs(tableau1, 6, result);
    CU_ASSERT_EQUAL(result[0], 12);
    CU_ASSERT_EQUAL(result[1], 10);
    CU_ASSERT_EQUAL(result[2], 7);

    int tableau2[] = {1, 2, 3};
    trois_plus_grandes_valeurs(tableau2, 3, result);
    CU_ASSERT_EQUAL(result[0], 3);
    CU_ASSERT_EQUAL(result[1], 2);
    CU_ASSERT_EQUAL(result[2], 1);
}

void test_est_premier() {
    CU_ASSERT_TRUE(est_premier(2));
    CU_ASSERT_TRUE(est_premier(17));
    CU_ASSERT_FALSE(est_premier(1));
    CU_ASSERT_FALSE(est_premier(0));
    CU_ASSERT_FALSE(est_premier(-5));
    CU_ASSERT_FALSE(est_premier(18));
    CU_ASSERT_TRUE(est_premier(29));
}


int main() {
    // Initialisation du registre de tests
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Ajout d'une suite de tests
    CU_pSuite suite = CU_add_suite("Tests des fonctions", 0, 0);
    if (!suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Ajout des tests à la suite
    if (!CU_add_test(suite, "Test trois_plus_grandes_valeurs", test_trois_plus_grandes_valeurs) ||
        !CU_add_test(suite, "Test est_premier", test_est_premier)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Exécution des tests en mode basique
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Nettoyage du registre
    CU_cleanup_registry();
    return CU_get_error();
}
