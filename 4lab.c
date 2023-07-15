

/// Qutaiba ALASHQAR, 20290036;
/// 4.LAB, 1.SORU;


#include <stdio.h>
#include <stdlib.h>


int function_1(int size, int mat[]);


int function_1(int size, int mat[]){

    int counter = 0;
    int results[size];
    int result = 0;
    int count = 1;

    for (int i = 0; i < size; i++){

        if (i == 0){

            continue;
        }

        else{

            if (i == size - 1){

                if (mat[i] > mat[i - 1]){

                    count += 1;
                }
                results[counter] = count;
                counter += 1;
            }

            else if ((i == 1) && (mat[i] > mat[i - 1])){

                count += 1;
            }

            else if (mat[i] > mat[i - 1]){

                count += 1;
            }

            else{

                results[counter] = count;
                counter += 1;
                count = 1;
            }
        }
    }

    int min = -99999;
    for (int i = 0; i < counter; i++){

        if (min < results[i]){

            min = results[i];
        }
    }
    result = min;

    return (result);
}


int main(){

    int size;
    scanf("%d", &size);
    int matrix_A[size];
    int index;
    int matrix_B[size - 1];
    int varible = 0;

    for (int i = 0; i < size; i++){

        scanf("%d", &index);
        matrix_A[i] = index;
        index = 0;
    }

    for (int i = 0; i < size - 1; i++){

        varible = matrix_A[i + 1] - matrix_A[i];
        matrix_B[i] = varible;
        varible = 0;
    }

    int result;
    result = function_1((size - 1), matrix_B);
    printf("%d", result);

    return (0);
}
