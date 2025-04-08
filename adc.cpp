#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void toBinary(int num, vector<int>& bin);
void printBinary(const vector<int>& bin);
void nor(vector<int>& bin);
void plus1(vector<int>& bin);
void plusAwithM(vector<int>& bin1, const vector<int>& bin2);
void fillA(vector<int>& bin);
void BoothAlgorithm(vector<int>& binA, vector<int>& binQ, const vector<int>& binM, const vector<int>& binMinusM);
void printCicles(const vector<int>& binA, const vector<int>& binQ, int Q1, const vector<int>& binM);
void arithmeticShift(vector<int>& binA, vector<int>& binQ, int& Q1);
void copyM(const vector<int>& binM1, vector<int>& binM2);

int bitQnt;

void toBinary(int num, vector<int>& bin){
	for(int i = bitQnt - 1; i >= 0; i--){
		bin[i] = num % 2;
		num = num / 2;
	}
}

void printBinary(const vector<int>& bin){
	for(int b : bin){
		cout << b;
	}
}

void nor(vector<int>& bin){
	for(int i = 0; i < bitQnt; i++){
		bin[i] = bin[i] ^ 1;
	}
}

void plus1(vector<int>& bin){
	vector<int> bit1(bitQnt, 0);
	bit1[bitQnt - 1] = 1;
	int c1 = 0, add;
	for(int i = bitQnt - 1; i >= 0; i--){
		add = ((bin[i] ^ c1) ^ bit1[i]);
		c1 = ((bin[i] & bit1[i]) | (bin[i] & c1) | (bit1[i] & c1));
		bin[i] = add;
	}
}

void plusAwithM(vector<int>& bin1, const vector<int>& bin2){
	int c1 = 0, add;
	for(int i = bitQnt - 1; i >= 0; i--){
		add = ((bin1[i] ^ c1) ^ bin2[i]);
		c1 = ((bin1[i] & bin2[i]) | (bin1[i] & c1) | (bin2[i] & c1));
		bin1[i] = add;
	}
}

void fillA(vector<int>& bin){
	for(int i = 0; i < bitQnt; i++){
		bin[i] = 0;
	}
}

void BoothAlgorithm(vector<int>& binA, vector<int>& binQ, const vector<int>& binM, const vector<int>& binMinusM){
	int Q1 = 0;
	int count = bitQnt;
	int width = bitQnt + 2;

	cout << "\n" << std::setw(width) << "A" << std::setw(width) << "Q"
			  << std::setw(5) << "Q-1" << std::setw(width) << "M\n";
	cout << "-------------------------------------------------------\n";

	while(count != 0){
		printCicles(binA, binQ, Q1, binM);
		if(Q1 == binQ[bitQnt - 1]){
			cout << "   Arith shift\n";
		}else if(Q1 < binQ[bitQnt - 1]){
			cout << "   A = A - M\n";
			plusAwithM(binA, binMinusM);
			printCicles(binA, binQ, Q1, binM);
			cout << "   Arith shift\n";
		}else{
			cout << "   A = A + M\n";
			plusAwithM(binA, binM);
			printCicles(binA, binQ, Q1, binM);
			cout << "   Arith shift\n";
		}
		arithmeticShift(binA, binQ, Q1);
		count--;
	}
	printCicles(binA, binQ, Q1, binM);
}

void printCicles(const vector<int>& binA, const vector<int>& binQ, int Q1, const vector<int>& binM){
	int width = bitQnt + 2;
	cout << "  ";
	printBinary(binA);
	cout << "  ";
	printBinary(binQ);
	cout << std::setw(5) << Q1 << "  ";
	printBinary(binM);
	cout << "\n";
}

void arithmeticShift(vector<int>& binA, vector<int>& binQ, int& Q1){
	Q1 = binQ[bitQnt - 1];
	int tmp1 = binA[bitQnt - 1];
	int tmp2 = binA[0];
	for(int i = bitQnt - 1; i > 0; i--){
		binQ[i] = binQ[i - 1];
		binA[i] = binA[i - 1];
	}
	binQ[0] = tmp1;
	binA[0] = tmp2;
}

void copyM(const vector<int>& binM1, vector<int>& binM2){
	for(int i = 0; i < bitQnt; i++){
		binM2[i] = binM1[i];
	}
}

int main(){
	int m, q;

	cout << "Ingresar cantidad de bits a usar: ";
	cin >> bitQnt;

	vector<int> binaryM(bitQnt);
	vector<int> binaryMinusM(bitQnt);
	vector<int> binaryQ(bitQnt);
	vector<int> binaryA(bitQnt);

	fillA(binaryA);

	cout << "Ingresar multiplicando(M): ";
	cin >> m;
	cout << "Ingresar multiplicador(Q): ";
	cin >> q;

	toBinary(m, binaryM);
	toBinary(q, binaryQ);

	copyM(binaryM, binaryMinusM);
	nor(binaryMinusM);
	plus1(binaryMinusM);

	BoothAlgorithm(binaryA, binaryQ, binaryM, binaryMinusM);

	cout << "\n";

	return 0;
}
