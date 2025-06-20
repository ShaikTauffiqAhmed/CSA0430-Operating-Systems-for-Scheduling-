#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    char message[100] = "Hello from child process via simulated shared memory!";
    char buffer[100];
    fp = fopen("shared_memory.txt", "w");
    if (fp == NULL) {
        printf("File creation failed.\n");
        return 1;
    }
    fprintf(fp, "%s", message);
    fclose(fp);
    printf("Child: Message written to file (simulated shared memory).\n");
    fp = fopen("shared_memory.txt", "r");
    if (fp == NULL) {
        printf("File open failed.\n");
        return 1;
    }
    fgets(buffer, 100, fp);
    fclose(fp);
    printf("Parent: Message read from file: \"%s\"\n", buffer);
    return 0;
}
