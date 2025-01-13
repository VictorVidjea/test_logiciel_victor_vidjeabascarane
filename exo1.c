#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <stdio.h>
#include <stdlib.h>

void trois_plus_grandes_valeurs(int* tableau, int taille, int* result) {
    if (taille < 3) {
        fprintf(stderr, "Erreur : Le tableau doit contenir au moins 3 éléments.\n");
        exit(EXIT_FAILURE);
    }

    int max1 = -2147483648, max2 = -2147483648, max3 = -2147483648;

    for (int i = 0; i < taille; i++) {
        if (tableau[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = tableau[i];
        } else if (tableau[i] > max2) {
            max3 = max2;
            max2 = tableau[i];
        } else if (tableau[i] > max3) {
            max3 = tableau[i];
        }
    }

    result[0] = max1;
    result[1] = max2;
    result[2] = max3;
}

// Fonction pour vérifier si un nombre est premier
int est_premier(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
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
