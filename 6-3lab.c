

/// Qutaiba ALASHQAR, 20290036.
/// LAB_6, 3.SORU, Yarıya kadar Azalt-Yönet


#include <stdio.h>
#include <stdlib.h>


int counter = 0;
int function_1(int num, int uss_of_cube);


int function_1(int num, int uss_of_cube){

    if (uss_of_cube == 0){

        return (1);
    }
    else{

        counter += 1;
        return (function_1(num, (uss_of_cube - 1)) * (num));
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
