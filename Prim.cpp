#include <iostream>
using namespace std;





int main() {

	int inf = 999999;

	int W[5][5] = { {inf, 8, 1, 3, inf},
					{8, inf, inf, 10, 1},
					{1, inf, inf, 1, 6},
					{3, 10, 1, inf, 4},
					{inf, 1, 6, 4, inf} };

	int R[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			R[i][j] = inf;


	bool U[5] = { 1, 0, 0, 0, 0 };

	for (int i = 0; i < 5; i++) {

		int min_length = inf;
		int next_vertice = -1;

		for (int j = 0; j < 5; j++) {
			if (W[i][j] < min_length && !U[j]) {
				min_length = W[i][j];
				next_vertice = j;
			}
		}

		if (next_vertice != -1 && min_length < R[i][next_vertice]) {

			R[i][next_vertice] = min_length;
			R[next_vertice][i] = min_length;
			U[i] = true;
		}
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cout << R[i][j] << " ";
		cout << endl;
	}

	return 0;
}
