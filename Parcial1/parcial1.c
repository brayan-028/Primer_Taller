#include <stdio.h>


typedef struct {
    int codi; 
    int nota;
}estud;

int nota_maxima(estud lista[], int n, int *codigo_max);
float promedio_curso(estud lista[], int n);


int main() {
    
    estud list_estud[] = {
        {codi: 123, nota: 90},
        {codi: 321, nota: 100},
        {codi: 456, nota: 56},
        {codi: 654, nota: 60},
        {codi: 789, nota: 70},
        {codi: 987, nota: 75}
    };
    int list_estudiantes = sizeof(list_estud) / sizeof(list_estud[0]);
    int opcion;
    

    do {
        printf("\n----- MENU -----\n");
        printf("1. Buscar la Nota Maxima del Curso\n");
        printf("2. Calcular el Promedio del Curso\n");
        printf("3. Ordenar Codigos de Estudiantes (Selection Sort ascendente)\n");
        printf("4. Salir\n");
        printf("Seleccione una Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                int codigo_m;
                int max_nota = nota_maxima(list_estud, list_estudiantes, &codigo_m);
                printf("La nota maxima es %d y el codigo del estudiante es: %d\n", max_nota, codigo_m);
                break;
            }
            case 2: {
                float promedio = promedio_curso(list_estud, list_estudiantes);
                printf("El promedio del curso es: %.2f\n", promedio);
                
                break;
            }
                
            case 3: 
                
                break;
            
            case 4:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 4);

    return 0;
}


int nota_maxima(estud lista[], int n, int *codigo_max) {
    if (n == 1) {
        *codigo_max = lista[0].codi;
        return lista[0].nota;
       } else {
         int codigo_temp;
         int maxima_not = nota_maxima(lista, n - 1, &codigo_temp);
         if (lista[n - 1].nota > maxima_not) {
            *codigo_max = lista[n - 1].codi;
            return lista[n - 1].nota;
         } else {
            *codigo_max = codigo_temp;
            return maxima_not;
         }
       }



}


float suma_notas(estud lista[], int n){
    if (n == 0){
        return 0;
        } else {
            return lista[n - 1].nota + suma_notas(lista, n - 1);
        }

   }


   float promedio_curso(estud lista[], int n){
    int suma = suma_notas(lista, n);
    return (float) suma / n;

   }







