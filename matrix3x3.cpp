#include <iostream>
#include <array>
using namespace std;

int main() {
    int** * w;
    w = new int**[4];
    for (int i = 0; i < 4; ++i) {
        w[i] = new int*[4];
        for (int j = 0; j < 4; ++j) {
            w[i][j] = new int[4];
        }
    }
    w[3][2][1] = 0;
}