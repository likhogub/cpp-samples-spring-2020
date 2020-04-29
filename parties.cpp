#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct party {
	string name;
	int votesCount = -1;
};

party parties[20];

int main() {
	map <string, int> dict;
	ifstream file("task1.txt");
	
	while (!file.eof()) {
		string partyName;
		getline(file, partyName);
		dict[partyName]++;
	}

	file.close();

	map <string, int> :: iterator it = dict.begin();

	int partiesCount = 0;
	while (it != dict.end()) {

		party newParty;
		newParty.name = it->first;
		newParty.votesCount = it->second;
		parties[partiesCount] = newParty;
		partiesCount++;

		it++;
	}

	for (int i = 0; i < partiesCount; i++) cout << parties[i].name << " " << parties[i].votesCount << endl;
	cout << endl;

	party tmp;
	for (int i = 0; i < partiesCount; i++)
		for (int j = 0; j < partiesCount; j++) {
			if (i > j && parties[i].votesCount > parties[j].votesCount) {
				tmp = parties[i];
				parties[i] = parties[j];
				parties[j] = tmp;
			}
		}

	for (int i = 0; i < partiesCount; i++) cout << parties[i].name << " " << parties[i].votesCount << endl;

	ofstream output("task1answer.txt", ios::app);
	for (int i = 0; i < partiesCount; i++) output << parties[i].name << "\n";

	return 0;
}
