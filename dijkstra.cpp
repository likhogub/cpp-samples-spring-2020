#include <iostream>
using namespace std;

int C[50][50];
int D[50];

int main() {

	int size = 25;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cin >> C[i][j];

	for (int i = 0; i < size; i++) D[i] = C[0][i];

	for (int w = 0; w < size; w++)
		for (int v = 0; v < size; v++) 
			D[v] = D[v] < D[w] + C[w][v] ? D[v] : D[w] + C[w][v];

	cout << D[size] << endl;

	return 0;
}
