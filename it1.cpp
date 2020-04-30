#include <iostream>
#include <set>
using namespace std;


set <int> unity;

int main() {
	int tmp;
	for (int i = 0; i < 5; i++) {
		cin >> tmp;
		unity.insert(tmp);
	}

	set <int>::iterator it;
	
	for (it = unity.begin(); it != unity.end(); ) {
		tmp = *it;
		it++;
		if (tmp > 10) unity.erase(tmp);
	}

	for (it = unity.begin(); it != unity.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
