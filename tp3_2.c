#include <stdio.h>
#include <time.h>

void cargarMatriz(int matriz[5][12]);
void mostrarMatriz(int matriz[5][12]);
void promedioGananciasPorAnio(int matriz[5][12]);
void mostrarMaximo(int matriz[5][12]);
void mostrarMinimo(int matriz[5][12]);

int main(){
    //Notacion subindexada
    srand (time(NULL));
    int matriz[5][12];

    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    promedioGananciasPorAnio(matriz);
    mostrarMaximo(matriz);
    mostrarMinimo(matriz);
    
    //Notacion indexada
    // int* puntero;
    // int matriz[5][12];
    // puntero = matriz;

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 12; j++)
    //     {
    //         *(puntero + (i * 12 + j)) = 10000 + rand()%(50000 - 10000 + 1);
    //     }
    // }
    
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 12; j++)
    //     {
    //         printf("%d  ", *(puntero + (i * 12 + j)));
    //     }
    //     printf("\n");
    // }

   return 0;
}

void cargarMatriz(int matriz[5][12]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j]=10000 + rand()%(50000-10000+1);
        }
    }
}

void mostrarMatriz(int matriz[5][12]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%d  ",matriz[i][j]);
        }
        printf("\n");
    }

}

void promedioGananciasPorAnio(int matriz[5][12]){
    for (int i = 0; i < 5; i++)
    {
        int sumador = 0;
        for (int j = 0; j < 12; j++)
        {
            sumador += matriz[i][j];
        }
        printf("Promedio del anio %d: %d \n", i, sumador/12);
    }
}

void mostrarMaximo(int matriz[5][12]){
    int comparador = 0, anio,mes;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (comparador < matriz[i][j])
            {
                comparador = matriz[i][j];
                anio = i;
                mes = j;
            }            
        }
    }
    printf("El valor maximo es: %d - Ocurrio en el mes/anio: %d/%d\n", comparador, mes, anio);
}

void mostrarMinimo(int matriz[5][12]){
    int comparador = 50000, anio,mes;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (comparador > matriz[i][j])
            {
                comparador = matriz[i][j];
                anio = i;
                mes = j;
            }            
        }
    }
    printf("El valor minimo es: %d - Ocurrio en el mes/anio: %d/%d\n", comparador, mes, anio);
}