#include <iostream>
#include <array>
using namespace std;

int main() {
    int * p;
    p = new int[4];
    *(p+2) = 2; // contenido 
    p[2] = 7;
    void * n; // puntero a tipo indefinido

    int* * m;
    m = new int*[4];

    for (int i = 0; i < 4; ++i) 
        m[i] = new int[4];

    *(*(m+2)+1) = 8;
    m[2][1] = 8;

    for (int i = 0; i < 4; ++i) {
        for (int j =  0; i < 4; ++j) {
            *(*(m+i)+j) = rand() % 100;
        }
    }
    cout << m;

    /*for (int i = 0; i < 4; ++i)
        delete m[i];

    delete m;*/
    
}