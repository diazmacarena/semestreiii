#include <iostream>
#include <bitset>
#include <iomanip>

const int MAX_BITS = 32;

void BoothAlgorithm(std::bitset<MAX_BITS>& A, std::bitset<MAX_BITS>& Q, std::bitset<MAX_BITS> M, std::bitset<MAX_BITS> minusM, int bitQnt);
void arithmeticShift(std::bitset<MAX_BITS>& A, std::bitset<MAX_BITS>& Q, int& Q1, int bitQnt);
void plus(std::bitset<MAX_BITS>& A, std::bitset<MAX_BITS> B, int bitQnt);
void printCicles(std::bitset<MAX_BITS> A, std::bitset<MAX_BITS> Q, int Q1, std::bitset<MAX_BITS> M, int bitQnt);

int main() {
    int m, q, bitQnt;
    std::cout << "Ingresar cantidad de bits a usar: ";
    std::cin >> bitQnt;

    std::bitset<MAX_BITS> M, minusM, Q, A;

    std::cout << "Ingresar multiplicando(M): ";
    std::cin >> m;
    std::cout << "Ingresar multiplicador(Q): ";
    std::cin >> q;

    M = std::bitset<MAX_BITS>(m);
    Q = std::bitset<MAX_BITS>(q);
    minusM = std::bitset<MAX_BITS>(~M.to_ulong() + 1); // complemento a 2

    BoothAlgorithm(A, Q, M, minusM, bitQnt);

    return 0;
}

void BoothAlgorithm(std::bitset<MAX_BITS>& A, std::bitset<MAX_BITS>& Q, std::bitset<MAX_BITS> M, std::bitset<MAX_BITS> minusM, int bitQnt) {
    int Q1 = 0;
    int count = bitQnt;
    int width = bitQnt + 2;

    std::cout << "\n" << std::setw(width) << "A" << std::setw(width) << "Q" << std::setw(5) << "Q-1" << std::setw(width) << "M\n";
    std::cout << "-------------------------------------------------------\n";

    while (count--) {
        printCicles(A, Q, Q1, M, bitQnt);
        if (Q1 == Q[0]) {
            std::cout << "   Arith shift\n";
        } else if (Q1 < Q[0]) {
            std::cout << "   A = A - M\n";
            plus(A, minusM, bitQnt);
            printCicles(A, Q, Q1, M, bitQnt);
            std::cout << "   Arith shift\n";
        } else {
            std::cout << "   A = A + M\n";
            plus(A, M, bitQnt);
            printCicles(A, Q, Q1, M, bitQnt);
            std::cout << "   Arith shift\n";
        }
        arithmeticShift(A, Q, Q1, bitQnt);
    }

    std::cout << "\nResultado final:\n";
    printCicles(A, Q, Q1, M, bitQnt);
    std::cout << "\n";
}

void plus(std::bitset<MAX_BITS>& A, std::bitset<MAX_BITS> B, int bitQnt) {
    int carry = 0;
    for (int i = 0; i < bitQnt; i++) {
        int sum = A[i] + B[i] + carry;
        A[i] = sum % 2;
        carry = sum / 2;
    }
}

void arithmeticShift(std::bitset<MAX_BITS>& A, std::bitset<MAX_BITS>& Q, int& Q1, int bitQnt) {
    Q1 = Q[0];
    int lastA = A[bitQnt - 1];
    for (int i = 0; i < bitQnt - 1; i++) {
        Q[i] = Q[i + 1];
        A[i] = A[i + 1];
    }
    Q[bitQnt - 1] = A[0];
    A[bitQnt - 1] = lastA;
}

void printCicles(std::bitset<MAX_BITS> A, std::bitset<MAX_BITS> Q, int Q1, std::bitset<MAX_BITS> M, int bitQnt) {
    for (int i = bitQnt - 1; i >= 0; i--) std::cout << A[i];
    std::cout << "  ";
    for (int i = bitQnt - 1; i >= 0; i--) std::cout << Q[i];
    std::cout << std::setw(5) << Q1 << "  ";
    for (int i = bitQnt - 1; i >= 0; i--) std::cout << M[i];
    std::cout << "\n";
}