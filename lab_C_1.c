#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int main()
{   int sizem, i, numbers, j, tmp, k=0,  steps, diag[15], other[49],n=2, posled_diag, posled_other, sort_1=0, max=0, min=1000;
    char way[20];
    posled_diag = 0;
    posled_other=0;
    printf("Hello username!\n");
    printf("What size matrix do you want to create, form 1 to 8? "); //Запрос размеров квадратной матрицы
    scanf("%d", &sizem);
    printf("\n");
    int ** matrix = malloc(sizeof(int*)*sizem); // создание целочисленной квадратной матрицы
    for( i = 0; i < sizem; ++i)
        matrix[i] = malloc(sizeof(int)*sizem);
    again:
    printf("Choose a solution path:\n");
    printf("Write 1 if you made matrix by yourself, or 2 for random: "); // выбор пути заполнения
    scanf("%s", &way);
    printf("\n");

    if (way == "1"){ // ручное заполнение матрицы

        printf("Write here your matrix: \n");
        for (i = 0; i < sizem; i ++){
            for (j=0; j<sizem; j++){
                scanf("%d", &matrix[i][j]);
            }

        }

    }else if (way == "2"){ // заполнение матрицы генератором
        for (i =0; i<sizem; i++)
            for (j=0; j<sizem; j++)
                matrix[i][j]=10 + rand()%90;



    } else { // если указаны некоректные символы

        printf("Uncorrect number, please try again. \n");
        goto again;
    }
    printf("\nYour matrix: \n"); // вывод изначальной матрицы
    for (i = 0; i < sizem; i++, putchar('\n'))
        for (j = 0; j < sizem; j++)
                if (j==0){
                    printf("| %d ", matrix[i][j]);
                } else if (j == sizem-1){
                    printf("%d ", matrix[i][j]);
                    printf("|");
                } else{
                    printf("%d ", matrix[i][j]);
                }

    for (i = 0; i<sizem; i++) // выборка ступеньки и лишних элементов в два массива для их послед обработки
        for (j=0; j<sizem; j++)
            if (j == i || j-1 == i){
                diag[posled_diag]=matrix[i][j];
                posled_diag++;
            }
            else{
                other[posled_other]=matrix[i][j];
                posled_other++;
            }

    while(n>1){ // сортировка пузырьком ступеньки
        k=0;
        for (i=1; i<posled_diag; ++i)
            if (diag[i]<diag[i-1]){
                tmp = diag[i-1];
                diag[i-1]=diag[i];
                diag[i]=tmp;
                k=i;
            }
        n=k;
        }

    for (i=0; i<sizem; i++) // перемещение чисел после сортировки
        for (j=0; j<sizem;j++)
        if (j == i || j-1 == i){
            matrix[i][j] = diag[sort_1];
            sort_1++;
        }
    for (i=0; i<posled_other; i++) // Поиск максимального числа из несортируемых
        if (other[i] > max){
                max = other[i];
        }
    printf("Sorted matrix:\n"); // вывод матрицы после сортировки
    for (i = 0; i < sizem; i++, putchar('\n'))
        for (j = 0; j < sizem; j++)
            if (j==0){
                printf("| %d ", matrix[i][j]);
            } else if (j == sizem-1){
                printf("%d ", matrix[i][j]);
                printf("|");
            } else{
                printf("%d ", matrix[i][j]);
            }
    printf("Max in no sorted is: %d", max); // вывод максимального числа
    return 0;
}
