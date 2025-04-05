#include <iostream>
#include <array>
using namespace std;

int main() {
    int * p; // puntero a entero array de enteros
    p = new int[4];
    p[2] = 7;
    *(p+2) = 7;

    delete p;

    int* * q; // almacena direcciones de variable de tipo entero
    q = new int*[4];

    int** * m;
    m = new int**[4];

}