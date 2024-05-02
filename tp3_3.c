#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *V[5];
    char **Buffer;
    // Buffer = (char**) malloc(5 * sizeof(char *));

    char* Buff;
    char* Nombre;

    // Nombre = (char*) malloc(100 * sizeof(char));
    //Ingresa los nombres por pantalla
    for (int i = 0; i < 5; i++)
    {
        Buff = (char*) malloc(100 * sizeof(char));
        printf("Ingrese el nombre: ");
        gets(Buff);
        V[i] = (char *) malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(V[i],Buff);
        free(Buff);
    }

    //Muestra los nombres por pantalla
    for (int i = 0; i < 5; i++)
    {
        puts(V[i]);
        printf("\n");
        free(V[i]);
    }
    
    return 0;
}