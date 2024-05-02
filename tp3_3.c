#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char **Buffer;
    Buffer = (char**) malloc(5 * sizeof(char *));

    char* Buff;
    char* Nombre;

    Buff = (char*) malloc(100 * sizeof(char));
    printf("Ingrese el nombre: ");
    gets(Buff);

    strcpy(Nombre,Buff);
    puts(Nombre);

    free(Buff);
    free(Nombre);
    return 0;
}