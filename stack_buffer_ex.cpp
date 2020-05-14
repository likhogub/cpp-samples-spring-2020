#include <queue>
#include <stack>

queue <int> input_way;
queue <int> output_way;
stack <int> buffer;


int getTopBufferItem() {
	if (!buffer.empty()) return buffer.top();
	return 0;
}

int popTopBufferItem() {
	if (!buffer.empty()) buffer.pop();
	return 0;
}

int addItemToBuffer(int wagon_number) {
	buffer.push(wagon_number);
	return 0;
}

int getBufferSize() {
	return buffer.size();
}

int getInputItem() {
	if (!input_way.empty()) {
		int tmp = input_way.front();
		input_way.pop();
		return tmp;
	}
	return 0;
}

int getInputSize() {
	return input_way.size();
}

int addItemToOutput(int wagon_number) {
	output_way.push(wagon_number);
	return 0;
}

int getOutputSize() {
	return output_way.size();
}

int main() {
	int n;
	cout << "Enter N: ";
	cin >> n;

	cout << "Enter wagon numbers: ";
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		input_way.push(tmp);
	}

	int target_wagon = 1;

	while (getInputSize() > 0) {
		while (getTopBufferItem() == target_wagon) {
			addItemToOutput(getTopBufferItem());
			popTopBufferItem();
			target_wagon++;
		}

		int item = getInputItem();
		if (item != 0) addItemToBuffer(item);

		while (getTopBufferItem() == target_wagon) {
			addItemToOutput(getTopBufferItem());
			popTopBufferItem();
			target_wagon++;
		}
	}

	if (!getBufferSize()) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
