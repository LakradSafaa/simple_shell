#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exitShell() {
    printf("Exiting the shell...\n");
    exit(0);
}

int main() {
    char input[256]; // Définir une taille maximale pour l'entrée du shell

   // while (1) {
            debut:
        printf("Shell> ");
        fgets(input, sizeof(input), stdin);

        // Supprimer le saut de ligne (\n) de l'entrée
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            exitShell(); // Appel de la fonction exitShell si l'utilisateur entre "exit"
        } else {
            // Traitement des autres commandes du shell ici...
            printf("Commande non reconnue : %s\n", input);
        }
   // }
   goto debut;

    return 0;
}

