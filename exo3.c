#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

//code permettant de renvoyer le format ieee binaire d'un flotant 

int which_bit(int a, int num_bit) {
    if (num_bit >= 0 && num_bit < (sizeof(a) * 8)) {
        return ((a >> num_bit) & 1);
    }
    return 0;
}

char* visualisation(float nombre_floatant) {
    // Union pour interpréter le float comme un int
    union CaseMagique {
        int entier;
        float reel;
    } une_case;

    une_case.reel = nombre_floatant;
    int b = une_case.entier;

    // Tampon pour stocker la chaîne de résultat
    char* buffer = malloc(1000); // Taille suffisante pour stocker le résultat
    if (!buffer) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    char temp[10]; // Tampon temporaire pour construire chaque segment
    buffer[0] = '\0'; // Initialise la chaîne vide

    // Ajouter le bit de signe
    sprintf(temp, "%d", which_bit(b, 31));
    strcat(buffer, temp);

    strcat(buffer, " - ");

    // Ajouter les bits de l'exposant
    for (int i = 1; i < 9; i++) {
        sprintf(temp, "%d", which_bit(b, 31 - i));
        strcat(buffer, temp);
    }

    strcat(buffer, " - ");

    // Ajouter les bits de la mantisse
    for (int j = 9; j < 32; j++) {
        sprintf(temp, "%d", which_bit(b, 31 - j));
        strcat(buffer, temp);
    }

    return buffer; // Retourne la chaîne de caractères
}
void test_visualisation() {
    // Nombre à tester
    float test_value = 123.234432;

    // Résultat attendu (IEEE 754 formaté)
    const char* expected_output = "0 - 10000101 - 11101101111001101110100";

    // Appel de la fonction visualisation
    char* result = visualisation(test_value);
    printf("%s",result);

    // Vérification que le résultat n'est pas NULL
    CU_ASSERT_PTR_NOT_NULL(result);

    // Vérification que le résultat correspond à l'attendu
    if (result != NULL) {
        CU_ASSERT_STRING_EQUAL(result, expected_output);
    }

    // Libération de la mémoire
    free(result);
}

int main() {
    // Initialisation du registre CUnit
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Création d'une suite de tests
    CU_pSuite suite = CU_add_suite("Test de la fonction visualisation", 0, 0);
    if (!suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Ajout du test à la suite
    if (!CU_add_test(suite, "Test visualisation", test_visualisation)) {
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
