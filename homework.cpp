#include <iostream>
using namespace std;

void customSort(int*, int*);

int main() {
    int arr[] = {2, 4, 12, 10, 6, 4, 24, 32, 5, 7, 35, 71, 7, 91, 35, 33};
    int* p = arr;
    int* q = &arr[8]; // Apunta a la mitad del arreglo

    customSort(p, q);

    for (int i = 0; i < 16; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

void customSort(int* p, int* q) {
    int* fin = p + (q - p) * 2; 

    for (int* i = p + 1; i < fin; i++) {
        int key = *i;
        int* j = i - 1;

     
        while (j >= p && *j > key) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key; 
    }
}
void mergeC(int *p, int *q) {
    int* fin = p + (q - p) * 2;
    while ((p < q) && (q < fin)) {
        if (*p <= *q) {
            p++;
        }
        else {
            for (int* r = p; r < q; r++) {
                swap(*r, *q);
                q++;
                p++;
            }
        }
    }
}
