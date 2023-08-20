#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <string.h>


//#define MAX_COMMAND_LENGTH 100

int main() {
    char cmmndline[100];
    char *prompt = "$ :";
    pid_t ps;

    while (1)

{
        printf("%s", prompt);
        if (fgets(cmmndline, sizeof(cmmndline), stdin) == NULL) {
            if (feof(stdin)) {
                printf("\n Ctrl+D pressed.\n");
                break;
            } else {
                perror("No such file or directory ");
                exit(EXIT_FAILURE);
            }
        }

        // Remove the trailing newline character
        cmmndline[strcspn(cmmndline, "\n")] = '\0';

        if (strlen(cmmndline) == 0) {
            continue; // Empty command, display prompt again
        }

        // Fork a child process to execute the command
        ps = fork();


        if (ps < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (ps == 0) { // Child process
            // Execute the command in the child process
            execlp(cmmndline, cmmndline, (char *)NULL);
            // If exec fails, print an error message
            fprintf(stderr, "Command not found: %s\n", cmmndline);
            exit(EXIT_FAILURE);
        } else { // Parent process
            // Wait for the child process to complete
            int status;
           waitpid(ps, &status, 0);
        }
    }

    return 0;
}
