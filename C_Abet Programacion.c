#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define NUM_A 5
#define NUM_MATERIAS 7
#define NUM_SEMESTRES 2

const char *NM[NUM_MATERIAS] = {
    "Ingenieria de Software",
    "Administracion",
    "Economia",
    "Relaciones Internacionales",
    "Matematicas",
    "Contabilidad",
    "Ingenieria Industrial"
};

void Menu(int *flag, int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]);
void ImprimirMatriz(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]);
void Opcion1(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]);
void Opcion2(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]);
void Opcion3(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]);

int main() {
    setlocale(LC_ALL, "");
    int flag = 1;
    int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES];

    srand(time(NULL));

    // Generar valores aleatorios para los alumnos matriculados
    for (int i = 0; i < NUM_A; i++) {
        for (int j = 0; j < NUM_MATERIAS; j++) {
            for (int k = 0; k < NUM_SEMESTRES; k++) {
                Am[i][j][k] = rand() % 101;
            }
        }
    }

    ImprimirMatriz(Am);

    while (flag) {
        Menu(&flag, Am);
    }

    return 0;
}

void Menu(int *flag, int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]) {
    int menu, resultado;

    printf("Programa:\n");
    printf("Por favor, seleccione una opción:\n 1. Ver el A en el que se recibió la mayor cantidad de alumnos.\n 2. Ver la carrera que recibió la mayor cantidad de alumnos en el último A.\n 3. Ver el A que recibió la mayor cantidad de alumnos en Ingeniería de Software.\n 4. Salir.\n");
    resultado = scanf("%d", &menu);

    while (resultado != 1) {
        while (getchar() != '\n'); // Limpiar el buffer de entrada

        printf("\nNo ha ingresado una opción válida. Por favor, intente de nuevo: ");
        resultado = scanf("%d", &menu);
    }

    switch (menu) {
        case 1:
            system("cls");
            Opcion1(Am);
            break;
        case 2:
            system("cls");
            Opcion2(Am);
            break;
        case 3:
            system("cls");
            Opcion3(Am);
            break;
        case 4:
            system("cls");
            *flag = 0;
            break;
        default:
            printf("\nNo ha ingresado una opción válida. Por favor, intente de nuevo.\n");
            break;
    }
}

void ImprimirMatriz(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]) {
    printf("Matriz de alumnos matriculados:\n");
    for (int i = 0; i < NUM_A; i++) {
        printf("A%d:\n", i + 1);
        for (int j = 0; j < NUM_MATERIAS; j++) {
            printf("%s: ", NM[j]);
            for (int k = 0; k < NUM_SEMESTRES; k++) {
                printf("%d ", Am[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}

void Opcion1(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]) {
    int maxA = 0;
    int maxAlumnos = 0;
    int totalAlumnos;

    for (int i = 0; i < NUM_A; i++) {
        totalAlumnos = 0;
        for (int j = 0; j < NUM_MATERIAS; j++) {
            for (int k = 0; k < NUM_SEMESTRES; k++) {
                totalAlumnos += Am[i][j][k];
            }
        }
        if (totalAlumnos > maxAlumnos) {
            maxAlumnos = totalAlumnos;
            maxA = i;
        }
    }

    printf("El A en el que se recibió la mayor cantidad de alumnos fue el %d, con %d alumnos.\n\n", maxA + 1, maxAlumnos);
}

void Opcion2(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]) {
    int maxMateria = 0;
    int maxAlumnos = 0;
    int totalAlumnos;

    for (int i = 0; i < NUM_MATERIAS; i++) {
        totalAlumnos = 0;
        for (int j = 0; j < NUM_A; j++) {
            for (int k = 0; k < NUM_SEMESTRES; k++) {
                totalAlumnos += Am[j][i][k];
            }
        }
        if (totalAlumnos > maxAlumnos) {
            maxAlumnos = totalAlumnos;
            maxMateria = i;
        }
    }

    printf("La carrera que recibió la mayor cantidad de alumnos en el último A es %s, con %d alumnos inscritos.\n\n", NM[maxMateria], maxAlumnos);
}

void Opcion3(int Am[NUM_A][NUM_MATERIAS][NUM_SEMESTRES]) {
    int maxA = 0;
    int maxAlumnos = 0;
    int totalAlumnos;

    for (int i = 0; i < NUM_A; i++) {
        totalAlumnos = 0;
        for (int j = 0; j < NUM_SEMESTRES; j++) {
            totalAlumnos += Am[i][0][j];
        }
        if (totalAlumnos > maxAlumnos) {
            maxAlumnos = totalAlumnos;
            maxA = i;
        }
    }

    printf("El A que recibió la mayor cantidad de alumnos en Ingeniería de Software fue el %d, con %d alumnos inscritos.\n\n", maxA + 1, maxAlumnos);
}