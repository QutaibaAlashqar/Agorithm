

/// QUTAIBA ALASHQAR, 20290036.
/// Alg.3, odev


#include<iostream>
#include <chrono>


using namespace std;
///
///
///
///
///
void mergee(int dizi_1[], int sol, int orta, int sag){

    int array_one = (orta - sol + 1);
    int array_tow = (sag - orta);

    int main_index = sol;
    int index_one = 0;
    int index_tow = 0;

    int *soldizi = new int[array_one];
    int *sagdizi = new int[array_tow];

    for(int i = 0; i < array_one; i++){

        soldizi[i] = dizi_1[sol + i];
    }
    for(int j = 0; j < array_tow; j++){

        sagdizi[j] = dizi_1[orta + 1 + j];
    }

    while((index_one < array_one) && (index_tow < array_tow)){

        if(soldizi[index_one] <= sagdizi[index_tow]){

            dizi_1[main_index] = soldizi[index_one];
            index_one++;
        }

        else{

            dizi_1[main_index] = sagdizi[index_tow];
            index_tow++;
        }
        main_index++;
    }

    while (index_one < array_one){

        dizi_1[main_index] = soldizi[index_one];
        index_one++;
        main_index++;
    }

    while (index_tow < array_tow) {
        dizi_1[main_index] = sagdizi[index_tow];
        index_tow++;
        main_index++;
    }
}


int merge_sort(int arrayy[], int beginn, int endd){

    if (beginn >= endd){
        return (0);
    }

    else{
        int mid = (beginn + (endd - beginn) / 2);
        merge_sort(arrayy, beginn, mid);
        merge_sort(arrayy, mid + 1, endd);
        mergee(arrayy, beginn, mid, endd);
    }

    return (1);
}


int* mergeSort(int* dizi, int boyut){

    int flag_m = merge_sort(dizi, 0, boyut - 1);
    return (dizi);
}
///
///
///
///
///
int partitionn(int dizi_2[], int start, int endd){

    int counter = 0;
    int pivot = dizi_2[start];

    for (int i = start + 1; i <= endd; i++) {
        if (dizi_2[i] <= pivot){
            counter++;
        }
    }
    int pivot_number = start + counter;

    swap(dizi_2[pivot_number], dizi_2[start]);

    int i = start;
    int j = endd;

    while ((i < pivot_number) && (j > pivot_number)) {

        while (dizi_2[i] <= pivot) {
            i++;
        }

        while (dizi_2[j] > pivot) {
            j--;
        }

        if ((i < pivot_number) && (j > pivot_number)){

            swap(dizi_2[i++], dizi_2[j--]);
        }
    }

    return (pivot_number);
}


int quick_sort(int arrayy[], int start, int endd){

    if (start >= endd){
        return (0);
    }

    else{
        int result_of_partition = partitionn(arrayy, start, endd);
        quick_sort(arrayy, start, (result_of_partition - 1));
        quick_sort(arrayy, (result_of_partition + 1), endd);
    }

    return (1);
}


int* quickSort(int* dizi, int boyut){

    int flag_q = quick_sort(dizi, 0, (boyut - 1));
    return (dizi);
}
///
///
///
///
///
bool diziSiraliMi(int * dizi, int boyut){

    if ((boyut == 0) || (boyut == 1)){
        return (true);
    }

    for (int i = 1; i < boyut; i++){

        if (dizi[i - 1] > dizi[i]){
            return (false);
        }
    }

    return (true);
}
///
///
///
///
///
void enHizliAlg(auto sure_mer, auto sure_qui){

	if(sure_mer==sure_qui)
		cout<<"Sureler esit!";
	else if(sure_qui<sure_mer)
		cout<<"En hizli Quick Sort!";
	else
		cout<<"En hizli Merge Sort!";
}
///
///
///
///
///
///
int main(){

	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

	int boyut;
	cin>> boyut; //BOYUT BİLGİSİ GİRİLİR
	int* dizi = new int[boyut];
	int* sirali_dizi_ins = new int[boyut];
	int* sirali_dizi_mer = new int[boyut];
	int* sirali_dizi_qui = new int[boyut];

	for (int i = 0; i < boyut; i++) // input.txt dosyasından alınız.
		cin>> dizi[i];

	auto t1 = high_resolution_clock::now();
	sirali_dizi_qui = quickSort(dizi, boyut);
	auto t2 = high_resolution_clock::now();

	auto t3 = high_resolution_clock::now();
	sirali_dizi_mer = mergeSort(dizi, boyut);
	auto t4 = high_resolution_clock::now();

	auto sure_qui = duration_cast <milliseconds> (t2 - t1);
	auto sure_mer = duration_cast <milliseconds> (t4 - t3);

	if(diziSiraliMi(sirali_dizi_mer, boyut) && diziSiraliMi(sirali_dizi_qui, boyut)){

		cout<< "Diziler Sirali!\n";
	}

	else{

		cout<< "Diziler Sirali Degil!\n";
	}

	enHizliAlg(sure_mer, sure_qui);
}
