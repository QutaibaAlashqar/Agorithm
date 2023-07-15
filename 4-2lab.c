

/// Qutaiba ALASHQAR, 20290036;
/// 4.LAB, 2.SORU;


#include <stdio.h>
#include <stdlib.h>


int function_1(int mat[], int count_index, int mat_of_equ[]);


int size;
int counter_of_recercive = 0;
int result_of_loop = 1;
int index_of_matrix = 0;
int pozition_varible = 0;
int counter_as_round = 0;


int function_1(int mat[], int count_index, int mat_of_equ[]){

    if (counter_of_recercive == size){

        return (result_of_loop);
    }

    else{

        int flag = 1;
        int new_index = count_index;

        for (int i = 0; i < index_of_matrix; i++){

            if (mat_of_equ[i] == mat[new_index]){
                flag = 0;
                count_index = pozition_varible;
                pozition_varible += 1;
            }
        }

        if (flag == 0){

            if (counter_as_round > 0){
                result_of_loop += 1;
                counter_as_round = 0;
            }

            return (function_1(mat, count_index, mat_of_equ));
        }

        else{

            counter_as_round += 1;
            mat_of_equ[index_of_matrix] = mat[new_index];
            index_of_matrix += 1;
            counter_of_recercive += 1;
            return (function_1(mat, (mat[new_index] - 1), mat_of_equ));
        }
    }
}


int main(){

    scanf("%d", &size);
    int matrix[size];

    for (int i = 0; i < size; i++){
        scanf("%d", &matrix[i]);
    }

    int matrix_of_equ[size];
    int count = 0;
    int result = function_1(matrix, count, matrix_of_equ);
    printf("%d", result);

    return 0;
}
