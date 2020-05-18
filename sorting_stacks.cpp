#include <stack>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

vector <stack <int>> store;

int _move(int source, int target) {
	if (store[source].size() > 0) {
		store[target].push(store[source].top());
		cout << source + 1 << " -> " << target + 1 << " : " << store[source].top() << endl;
		store[source].pop();
		return 1;
	}
	return 0;
}

int isIdeal(int target) {
	stack <int> tmp_stack;

	bool ideal = true;

	while (store[target].size() > 0) {
		if (store[target].top() != target + 1) { 
			ideal = false; 
			break; 
		}
		tmp_stack.push(store[target].top());
		store[target].pop();

	}

	while (tmp_stack.size() > 0) {
		store[target].push(tmp_stack.top());
		tmp_stack.pop();
	}

	return ideal;
}


int isAllIdeal() {
	for (int pile = 0; pile < store.size(); pile++) {
		if (!isIdeal(pile)) return 0;
	}
	return 1;
}

int process(int target) {
	int tmp_pile = (target + 1) % store.size();
	if (store[target].top() - 1 == target) _move(target, (target + 1) % store.size());
	else _move(target, store[target].top() - 1);
	return 0;
}

int show_pile(int target) {
	stack <int> tmp_stack;

	while (store[target].size() > 0) {
		tmp_stack.push(store[target].top());
		store[target].pop();
	}

	while (tmp_stack.size() > 0) {
		cout << tmp_stack.top() << " ";
		store[target].push(tmp_stack.top());
		tmp_stack.pop();
	}

	return 0;
}

int show_store() {
	cout << "------------STORE------------" << endl;
	for (int pile = 0; pile < store.size(); pile++) {
		cout << pile + 1 << "> ";
		show_pile(pile);
		cout << endl;
	}
	cout << "-----------------------------" << endl;
	return 0;
}

int main() {
	ifstream file("task.txt");

	int n;
	file >> n;

	for (int pile = 0; pile < n; pile++) {
		int pile_size;
		file >> pile_size;
		stack <int> pile_stack;
		for (int container_index = 0; container_index < pile_size; container_index++) {
			int tmp;
			file >> tmp;
			pile_stack.push(tmp);
		}
		store.push_back(pile_stack);
	}

	show_store();

	while (!isAllIdeal()) {
		for (int pile = 0; pile < n; pile++) 
			while (!isIdeal(pile)) 
				process(pile);
		show_store();
	}


	return 0;
}
