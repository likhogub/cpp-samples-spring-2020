#include <iostream>
using namespace std;





int main() {

	int inf = 999999;

	int W[5][5] = { {0, 8, 1, 3, inf},
					{8, 0, inf, 10, 1},
					{1, inf, 0, 1, 6},
					{3, 10, 1, 0, 4},
					{inf, 1, 6, 4, 0} };


	int S[5][5];

	for (int row = 0; row < 5; row++) {



		int L[5];

		for (int i = 0; i < 5; i++) L[i] = W[row][i];

		int H[5];

		for (int i = 0; i < 5; i++) H[i] = i;

		for (int k = 0; k < 5; k++) {
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++) {

					if (L[i] + W[i][j] < L[j]) {
						L[j] = L[i] + W[i][j];
						H[j] = H[i] * 10 + j;
					}

				}
			for (int i = 0; i < 5; i++) cout << row << H[i] << "_" << L[i] << "|";
			cout << endl;
		}
		for (int i = 0; i < 5; i++) S[row][i] = L[i];

	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cout << S[i][j] << " ";
		cout << endl;
	}
	return 0;
}
