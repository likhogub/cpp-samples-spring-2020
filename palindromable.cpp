#include <iostream>
#include <fstream>
using namespace std;


char arr[100];

char abc[27] = "abcdefghijklmnopqrstuvwxyz";

int letters[26];

int ord(char letter) {
	for (int i = 0; i < 26; i++) if (abc[i] == letter) return i;
	return -1;
}

char chr(int index) {
	return abc[index];
}

int main() {

	ifstream file("text1.txt");

	for (int i = 0; i < 26; i++) letters[i] = 0;

	char tmp;
	int c = 0;

	while (!file.eof()) {
		char tmp;
		file >> tmp;
		if (tmp == ' ' || tmp == '.' || tmp == ',' || tmp == '!') continue;
		arr[c] = tmp;
		c++;
	}
	
	for (int i = 0; i < c-1; i++) letters[ord(arr[i])]++;

	bool polinomable = true;

	int stringLength = c - 1;


	int odd = 0;
	for (int i = 0; i < 26; i++) if (letters[i] % 2 == 1) odd++;

	if (stringLength % 2 == 1) { if (odd > 1) polinomable = false; }
	else { if (odd > 0) polinomable = false; }

	if (polinomable) cout << "Yes" << endl;
	else cout << "No" << endl;

	ofstream output("answer1.txt");
	output << polinomable;
}
