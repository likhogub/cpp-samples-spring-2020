#include <iostream>
using namespace std;



int main() {

	int inf = 999999;
	int W[5][5] = { {0, inf, 1, inf, inf},
						{inf, 0, inf, inf, 1},
						{inf, inf, 0, 1, inf},
						{inf, 1, inf, 0, inf},
						{inf, inf, inf, inf, 0} };

	int H[5];

	for (int i = 0; i < 5; i++) H[i] = 0 + i;



	int L[5] = { 0, inf, 1, inf, inf };

	for (int k = 0; k < 5; k++){
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
			{
				if (L[i] + W[i][j] < L[j]) {
					L[j] = L[i] + W[i][j];
					H[j] = H[i] * 10 + j;
				}
			}
			for (int i = 0; i < 5; i++) cout << H[i] << "_" << L[i] << "|";
			cout << endl;
		}
	}
	cout << L[4] << endl;
	cout << H[4] << endl;


	return 0;
}
