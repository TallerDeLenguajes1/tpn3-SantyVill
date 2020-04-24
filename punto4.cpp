#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct{
    int productoID,cantidad;
    char *tipoProductos;
    float precioUnitario;
} producto;
typedef struct{
    int clienteId,cantidadProductosAPedir;
    char *nombreCliente;
    producto *productos;
} clientes;
void cargarCliente(clientes *cliente,int n);
float costoTotal(producto prod);

int main(){
    srand (time(NULL));
    int n,i,j;
    float total;
    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d",&n);
    getchar();
    clientes *cliente=(clientes *)malloc(sizeof(clientes)*n);
    cargarCliente(cliente,n);
    for (i = 0; i < n; i++)
    {
        total=0;
        printf("\n\n\n============Cliente %d============",(cliente+i)->clienteId);
        printf("\nNombre del cliente: %s",(cliente+i)->nombreCliente);
        printf("\nProductos: ");
        for (j = 0; j < (cliente+i)->cantidadProductosAPedir; j++)
        {
            printf("\n\nID del producto: %d",(cliente+i)->productos->productoID);
            printf("\nCantidad: %d",(cliente+i)->productos->cantidad);
            printf("\nPrecio unitario: %f",(cliente+i)->productos->precioUnitario);
            printf("\nTipo de producto: %s",(cliente+i)->productos->tipoProductos);
            total=total+costoTotal(*(cliente+i)->productos);
        }
        printf("\n\nTotal a pagar: %f",total);
        

    }
    getchar();
    
    free(cliente);
    return 0;
}

void cargarCliente(clientes *cliente,int n){
    int i,j,id=1;
    char nomCliente[50];
    for (i = 0; i < n; i++)
    {
        printf("\nIngrese los datos del cliente %d.",i+1);
        printf("\nNombre: ");
        gets(nomCliente);
        (cliente+i)->nombreCliente=(char*) malloc(sizeof(nomCliente)*strlen(nomCliente));
        strcpy((cliente+i)->nombreCliente,nomCliente);
        (cliente+i)->clienteId=i+1;
        (cliente+i)->cantidadProductosAPedir=rand()%5+1;
        (cliente+i)->productos= (producto *)malloc(sizeof(producto)*(cliente+i)->cantidadProductosAPedir);
        for ( j = 0; j < (cliente+i)->cantidadProductosAPedir; j++)
        {
            (cliente+i)->productos->productoID = id;
            (cliente+i)->productos->cantidad= rand()%10+1;
            (cliente+i)->productos->tipoProductos= tiposProductos[j];
            (cliente+i)->productos->precioUnitario= rand()%91+10;
            id++;
        }
        
    }
}

float costoTotal(producto prod){
    return (prod.precioUnitario*prod.cantidad);
}