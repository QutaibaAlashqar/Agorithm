

/// Qutaiba ALASHQAR, 20290036.
/// LAB_6, 1.SORU, Kaba kuvvet.


#include <stdio.h>
#include <stdlib.h>


int main(){

    int number;
    int uss;
    scanf("%d%d", &number, &uss);

    int result_of_cube = 1;
    int count_result_of_repetasrion = 0;

    for (int i = 0; i < uss; i++){
        result_of_cube *= number;
        count_result_of_repetasrion++;
    }

    printf("%d\n", result_of_cube);
    printf("%d", count_result_of_repetasrion);

    return 0;
}
