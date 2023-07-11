#include <stdio.h>

int main() {
    char clases[4][20] = {"TopRide", "Zumba", "Entrenamiento", "Abdominales"};
    int cupo[4] = {10, 10, 10, 10};
    int asistencia[4][5] = {0};

    int horario, clase;
    int total_asist = 0;
    int ganancia_total = 0;

    // Registro de asistencia
    for (horario = 0; horario < 5; horario++) {
        int hay_clase = 0; // Variable para verificar si hay alguna clase en este horario

        printf("Horario %d:\n", horario + 1);

        for (clase = 0; clase < 4; clase++) {
            char nombre[20];
            int asistentes;

            printf("Ingrese el nombre de la clase: ");
            scanf("%s", nombre);

            printf("Ingrese la cantidad de asistentes: ");
            scanf("%d", &asistentes);

            // Verificar si hay cupo en la clase
            if (asistentes <= cupo[clase]) {
                asistencia[clase][horario] = asistentes;
                cupo[clase] -= asistentes;
                total_asist += asistentes;
                hay_clase = 1;

                if (horario == 2) {
                    ganancia_total += asistentes * 700;
                } else if (horario < 2) {
                    ganancia_total += asistentes * 700 * 0.8;
                } else {
                    ganancia_total += asistentes * 700 * 1.15;
                }
            } else {
                printf("No hay cupo suficiente para la clase '%s' en este horario.\n", nombre);
            }
        }

        if (!hay_clase) {
            printf("No se dicta ninguna clase en el horario %d.\n", horario + 1);
        }
    }

    // Informe de asistencia por clase
    printf("\nInforme de asistencia por clase:\n");
    for (clase = 0; clase < 4; clase++) {
        printf("Clase '%s': %d personas\n", clases[clase], total_asist);
    }

  printf("Cantidad de personas que asistieron a cada clase:\n");
  for (clase = 0; clase < 4; clase++) {
      int total_asist_clase = 0;
      for (horario = 0; horario < 5; horario++) {
          total_asist_clase += asistencia[clase][horario];
      }
      printf("- %s: %d\n", clases[clase], total_asist_clase);
  }



    // Informe de horarios sin clases
    printf("\nHorarios sin clases:\n");
    for (horario = 0; horario < 5; horario++) {
        int clasesTotal = 0;

        for (clase = 0; clase < 4; clase++) {
            clasesTotal += asistencia[clase][horario];
        }

        if (clasesTotal == 0) {
            printf("Horario %d\n", horario + 1);
        }
    }

    // Informe de ganancias
    printf("\nGanancia total: $%d\n", ganancia_total);

    return 0;
}
