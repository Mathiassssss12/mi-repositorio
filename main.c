#include <stdio.h>
#include <string.h>

int main() {
    int id, stock, cantidad, opcion;
    float precio, total_ganancias = 0;
    char nombre[30];

    // Registro del producto
    printf("Ingrese el ID del producto: \n");
    scanf("%d", &id);

    getchar();
    
    printf("Ingrese el nombre del producto: \n");
    fgets(nombre, 30, stdin);
    
    printf("Ingrese la cantidad inicial en stock: \n");
    scanf("%d", &stock);
    
    printf("Ingrese el precio unitario del producto: \n");
    scanf("%f", &precio);

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer producto\n");
        printf("3. Mostrar informacion del producto\n");
        printf("4. Mostrar total de ganancias\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                do {
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if(cantidad <= 0){
                        printf("La cantidad ingresada no es valida. Intente nuevamente.\n");
                    }
                }while(cantidad <= 0);
                
                if (cantidad > stock) {
                    printf("No hay suficiente stock para realizar la venta.\n");
                    break;
                }else{
                    stock-=cantidad;
                    total_ganancias += cantidad * precio;
                }
                break;

            case 2:
                do{
                    printf("Ingrese la cantidad a agregar al stock: ");
                    scanf("%d", &cantidad);
                    if(cantidad <= 0){
                        printf("La cantidad ingresada no es valida. Intente nuevamente.\n");
                    }

                }while(cantidad <= 0);
                stock+=cantidad;
                
                break;

            case 3:
                printf("\nInformacion del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 4:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}