#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float notas[5][3];
    float promedio[5];
    float promedioa[3];
    float cALTAes = 0;
    float cALTAasig = 0;
    float cBAJAes = 10;
    float cBAJAasig = 10;
    float abrobar = 0;
    float altaEstudiante[5], bajaEstudiante[5];
    float altaAsignatura[3], bajaAsignatura[3];
    int aprobadosPorAsignatura[3] = {0, 0, 0};
    int reprobadosPorAsignatura[3] = {0, 0, 0};
    int opc = 0;
    int opc2 = 0;
    int opc3 = 0;
    int opc4 = 0;
    int opc5 = 1;
    char estudiantes[5][30];
    char asig[3][30];
    int cont = 0;
    int cont2 = 0;
    int len = 0;

    do
    {
        printf("Ingrese un opcion: \n");
        printf("1. Ingresar estudiantes: \n");
        printf("2. Ingrese la asignaturas: \n");
        printf("3. Ingresar notas: \n");
        printf("4.Mostrar promedios: \n");
        printf("5.Mostrar notas: \n");
        printf("6.Mostrar nota mas alta y mas baja\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:

            do
            {
                printf("Ingrese el nombre del estudiante: \n");
                fflush(stdin);
                fgets(estudiantes[cont], 30, stdin);
                len = strlen(estudiantes[cont]) - 1;
                estudiantes[cont][len] = '\0';
                cont++;
                printf("Desea ingresar otro estudiante? (1: Si, 2: No): \n");
                scanf("%d", &opc2);
                if (opc2 != 1 && opc2 != 2)
                {
                    printf("Opcion invalida. Ingrese nuevamente: \n");
                }
                if (cont >= 5)
                {
                    printf("Limite de estudiantes alcanzado.\n");
                    opc2 = 2;
                }
            } while (opc2 == 1);

            break;

        case 2:
            opc2 = 1;
            cont2 = 0;
            do
            {
                do
                {
                    printf("Ingrese el nombre de la asignatura: \n");
                    fgets(asig[cont2], 30, stdin);
                    len = strlen(asig[cont2]) - 1;
                    if (len > 0 && asig[cont2][len] == '\n')
                    {
                        asig[cont2][len] = '\0';
                    }
                    cont2++;
                    printf("Desea ingresar otra asignatura? (1: Si, 2: No): \n");
                    scanf("%d", &opc2);
                    if (opc2 != 1 && opc2 != 2)
                    {
                        printf("Opcion invalida. Ingrese nuevamente: \n");
                    }
                    if (cont2 >= 3)
                    {
                        printf("Limite de asignaturas alcanzado.\n");
                        opc2 = 2;
                    }
                } while (opc2 == 1);
                break;
            case 3:
                do
                {
                    printf("Ingrese las notas de los alumnos:\n");
                    printf("#\t\tNombre\n");
                    for (int i = 0; i < cont; i++)
                    {
                        printf("%d\t\t%s\n", i + 1, estudiantes[i]);
                    }
                    printf("Ingrese el numero del estudiante: \n");
                    scanf("%d", &opc3);
                    opc3--;
                    printf("#\t\tAsignatura\n");
                    fflush(stdin);
                    for (int i = 0; i < cont2; i++)
                    {
                        printf("%d\t\t%s\n", i + 1, asig[i]);
                    }
                    printf("Ingrese el numero de la asignatura: \n");
                    scanf("%d", &opc4);
                    opc4--;
                    printf("Ingrese la nota a ingresar: \n");
                    fflush(stdin);
                    do
                    {
                        scanf("%f", &notas[opc3][opc4]);
                        if (notas[opc3][opc4] < 0 || notas[opc3][opc4] > 10)
                        {
                            printf("Nota invalida. Ingrese nuevamente: ");
                        }

                    } while (notas[opc3][opc4] < 0 || notas[opc3][opc4] > 10);

                    printf("Desea ingresar otra nota? (1: Si, 2: No): \n");
                    scanf("%d", &opc5);
                } while (opc5 == 1);

                break;
            case 4:
                printf("Promedios de los alumnos:\n");
                printf("#\t\tNombre\n");
                for (int i = 0; i < cont; i++)
                {
                    printf("%d\t\t%s\n", i + 1, estudiantes[i]);
                }

                for (int i = 0; i < cont; i++)
                {
                    promedio[i] = 0;
                    for (int j = 0; j < cont2; j++)
                    {
                        promedio[i] += notas[i][j];
                        if (notas[i][j] > altaAsignatura[j])
                        {
                            altaAsignatura[j] = notas[i][j];
                        }
                        if (notas[i][j] < bajaAsignatura[j])
                        {
                            bajaAsignatura[j] = notas[i][j];
                        }
                    }
                    promedio[i] /= cont2;
                    printf("%s %d: %.2f\n", estudiantes[i], i + 1, promedio[i]);
                }
                break;

            case 5:
                printf("Notas de los alumnos:\n");
                printf("#\t\tNombre\n");
                for (int i = 0; i < cont; i++)
                {
                    printf("%d\t\t%s\n", i + 1, estudiantes[i]);
                }

                for (int i = 0; i < cont; i++)
                {
                    for (int j = 0; j < cont2; j++)
                    {
                        printf("El estudiante %s en la materia %s obtuvo una nota de: %.2f\n", estudiantes[i], asig[j], notas[i][j]);
                    }
                }

                break;
            case 6:
                printf("Notas mas altas y mas bajas por estudiante:\n");
                for (int i = 0; i < cont; i++)
                {
                    float CAltaes = -1, CBajaes = 11;
                    for (int j = 0; j < cont2; j++)
                    {
                        if (notas[i][j] > CAltaes)
                        {
                            CAltaes = notas[i][j];
                        }
                        if (notas[i][j] < CBajaes)
                        {
                            CBajaes = notas[i][j];
                        }
                    }
                    printf("%s su nota mas alta es: %.2f, su nota mas baja es: %.2f\n", estudiantes[i], CAltaes, CBajaes);
                }

                printf("\nNotas mas altas y mas bajas por asignatura:\n");
                for (int j = 0; j < cont2; j++)
                {

                    float CAltaasig = -1, CBajaasig = 11;
                    for (int i = 0; i < cont; i++)
                    {
                        if (notas[i][j] > CAltaasig)
                        {
                            CAltaasig = notas[i][j];
                        }
                        if (notas[i][j] < CBajaasig)
                        {
                            CBajaasig = notas[i][j];
                        }
                    }
                    printf("%s la nota mas alta es: %.2f, la mas baja: %.2f\n", asig[j], CAltaasig, CBajaasig);
                }
                break;
            case 7:

            defualt:
                break;
            }
        }
        while (opc != 6)
            ;

        return 0;
    }
}
