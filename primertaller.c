#include <stdio.h>

void registrar(int vector[10], int n);
void mostrar(int vector[10], int n);
void selectionSortAsc(int arr[10], int n);
void insertionSortDesc(int arr[10], int n);

int main() {
    int arreglo[10], opcion, copia[10];
    int datosIngresados = 0;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Registrar\n");
        printf("2. Mostrar arreglo original\n");
        printf("3. Ordenar (Selection Sort ascendente)\n");
        printf("4. Ordenar (Insertion Sort descendente)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registrar(arreglo, 10);
                datosIngresados = 1;
                break;
            case 2:
                if (!datosIngresados) printf("Debe registrar primero los datos.\n");
                else mostrar(arreglo, 10);
                break;
            case 3:
                if (!datosIngresados) printf("Debe registrar primero los datos.\n");
                else {
                    for(int i = 0; i < 10; i++) copia[i] = arreglo[i];
                    selectionSortAsc(copia, 10);
                }
                break;
            case 4:
                if (!datosIngresados) printf("Debe registrar primero los datos.\n");
                else {
                    for(int i = 0; i < 10; i++) copia[i] = arreglo[i];
                    insertionSortDesc(copia, 10);
                }
                break;
            case 5:
                printf("Programa finalizado\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 5);

    return 0;
}


void registrar(int vector[10], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        do {
            printf("Digite un tiempo positivo para la posicion %d: ", i+1);
            if (scanf("%d", &temp) != 1 || temp <= 0) {
                printf("Entrada invalida. Intente de nuevo.\n");           

            } else {
                vector[i] = temp;
                break;
            }
        } while (1);
    }
}


void mostrar(int vector[10], int n) {
    for (int i = 0; i < n; i++)
        printf("El tiempo en la posicion %d es %d\n", i+1, vector[i]);
}


void selectionSortAsc(int arr[10], int n) {
    printf("Selection Sort Ascendente:\n");
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        
        printf("Paso %d: [", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d", arr[k]);
            if (k < n - 1) printf(", ");
        }
        printf("]\n");
    }
}


void insertionSortDesc(int arr[10], int n) {
    printf("Insertion Sort Descendente:\n");
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < clave) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = clave;

        printf("Paso %d: [", i);
        for (int k = 0; k < n; k++) {
            printf("%d", arr[k]);
            if (k < n - 1) printf(", ");
        }
        printf("]\n");
    }
}
