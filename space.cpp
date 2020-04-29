#include <iostream>
#include <fstream>
using namespace std;

double arr[50];

int main() {

	ifstream file("text2.txt");

	for (int i = 0; i < 50; i++) arr[i] = 0;

	int c = 0;

	while (!file.eof()) {
		file >> arr[c];
		c++;
	}

	for (int i = 0; i < c; i++) cout << arr[i] << " ";
	cout << endl;

	double production = 1;
	double max = 0;
	for (int i = 0; i < c; i++) {
		max = max < arr[i] ? arr[i]:max;
		if (arr[i] >= 1) production *= arr[i];
	}

	if (max >= 1) cout << production << endl;
	else cout << max << endl;
	
	return 0;
}
