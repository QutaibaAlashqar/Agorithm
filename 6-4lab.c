

/// Qutaiba ALASHQAR, 20290036.
/// LAB_6, 4.SORU, Dönüştür-Yönet


#include <stdio.h>
#include <stdlib.h>


int binaryNum[32];
int count = 0;
int decToBinary(int n);
int value_of_binary[32];
int result_sumation_of_binarys = 0;

int function_1(int num);
int final_sonuc = 1;
int final_counter = 0;


int decToBinary(int n){

    int number_value_of_binary = 1;
    while (n > 0) {

        binaryNum[count] = n % 2;
        n = n / 2;
        count++;
    }

    int ii = 0;
    for (int i = 0; i < count; i++){

        if (binaryNum[i] == 1){

            value_of_binary[ii] = number_value_of_binary;
            ii++;
            number_value_of_binary *= 2;
        }
        else{

            number_value_of_binary *= 2;
        }
    }

    for (int j = 0; j < count; j++){

        result_sumation_of_binarys += value_of_binary[j];
    }
}


int function_1(int num){

    for (int i = 0; i < result_sumation_of_binarys; i++){

        final_sonuc *= num;
        final_counter += 1;
    }
}


int main(){

    int number;
    int uss;
    scanf("%d%d", &number, &uss);

    decToBinary(uss);
    function_1(number);

    printf("%d\n%d", final_sonuc, final_counter);

    return 0;
}
