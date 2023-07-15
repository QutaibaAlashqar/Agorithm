

/// Qutaiba ALASHQAR, 20290036.
/// LAB_6, 2.SORU, Böl Yönet


#include <stdio.h>
#include <stdlib.h>


int counter = 0;
int function_1(int num, int uss_of_cube);


int function_1(int num, int uss_of_cube){

    int temp = 1;
    if (uss_of_cube == 0){

        return (1);
    }
    temp = function_1(num, uss_of_cube / 2);
    counter += 1;
    if (uss_of_cube % 2 == 0){

        return (temp * temp);
    }
    else{

        return (num * temp * temp);
    }
}


int main(){

    int number;
    int uss;
    int result;
    scanf("%d%d", &number, &uss);

    result = function_1(number, uss);
    printf("%d\n", result);
    printf("%d", counter);

    return 0;
}
