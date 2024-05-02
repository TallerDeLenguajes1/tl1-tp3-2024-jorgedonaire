#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

    struct Producto {
        int ProductoID; //Numerado en ciclo iterativo
        int Cantidad; // entre 1 y 10
        char *TipoProducto; // Algún valor del arreglo TiposProductos
        float PrecioUnitario; // entre 10 - 100
    };
    typedef struct Producto Producto;

    struct Cliente {
        int ClienteID; // Numerado en el ciclo iterativo
        char *NombreCliente; // Ingresado por usuario
        int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
        Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
    };
    typedef struct Cliente Cliente;

float costoTotalProducto(Producto productoRecibido);

int main(){
    srand (time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    char *Buff;
    char *nombreCliente;
    int cantidadClientes;
    float totalAPagarCliente;
    printf("Ingrese la cantidad de clientes que va visitar: ");
    scanf("%d", &cantidadClientes);

    // Cliente *listaDeClientes[cantidadClientes];
    // Cliente *listaDeClientes;
    Cliente *listaDeClientes = (Cliente *) malloc (cantidadClientes * sizeof (Cliente));

    //Carga de clientes
    for (int i = 0; i < cantidadClientes; i++)
    {   
        //Carga de ID
        listaDeClientes[i].ClienteID = i;
        //Carga de cantidad de productos
        listaDeClientes[i].CantidadProductosAPedir = 1 + rand()%(5-1+1);
        //Carga de nombre de cliente
        Buff = (char *) malloc((100 * sizeof(char)));
        printf("Ingrese el nombre del cliente %d:", i);
        fflush(stdin);
        gets(Buff);
        nombreCliente = (char *) malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombreCliente,Buff);
        free(Buff);
        listaDeClientes[i].NombreCliente = nombreCliente;
        //Carga de productos
        listaDeClientes[i].Productos = (Producto *) malloc(listaDeClientes[i].CantidadProductosAPedir *sizeof(Producto));
        for (int j = 0; j < listaDeClientes[i].CantidadProductosAPedir; j++)
        {
            listaDeClientes[i].Productos[j].ProductoID = j;
            listaDeClientes[i].Productos[j].Cantidad = 1 + rand()%(10-1+1);
            listaDeClientes[i].Productos[j].TipoProducto = TiposProductos[1 + rand()%(5-1+1)];
            listaDeClientes[i].Productos[j].PrecioUnitario = 100 + rand()%(100-10+1);
        }
    }
    
    //Muestra por pantalla toda la informacion
    printf("**************************************\n");
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("\n--- Cliente %d ---\n",listaDeClientes[i].ClienteID);
        printf("Nombre: %s\n", listaDeClientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n", listaDeClientes[i].CantidadProductosAPedir);
        printf("*** Información sobre los productos ***\n");
        totalAPagarCliente = 0;
        for (int j = 0; j < listaDeClientes[i].CantidadProductosAPedir; j++)
        {
            printf("ID de producto: %d \n", listaDeClientes[i].Productos[j].ProductoID);
            printf("Cantidad de productos: %d \n", listaDeClientes[i].Productos[j].Cantidad);
            printf("Tipo de producto: %s\n", listaDeClientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %f\n",listaDeClientes[i].Productos[j].PrecioUnitario);
            totalAPagarCliente += costoTotalProducto(listaDeClientes->Productos[j]);
        }
    
        printf("Total a pagar por el cliente: %f", totalAPagarCliente);        
    }
    return 0;
}

float costoTotalProducto(Producto productoRecibido){
    return productoRecibido.Cantidad * productoRecibido.PrecioUnitario;
}