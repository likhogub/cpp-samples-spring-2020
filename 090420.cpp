#include <iostream>
using namespace std;

struct tree {
	int value;
	int childIndex = -1;
	tree* child[2] = { NULL, NULL };
};

tree* root, * tmp;


int treeAdd(tree* treeToAdd, int value) {
	int childIndex = treeToAdd->value % 2;
	if (treeToAdd->child[childIndex] != NULL) {
		treeAdd(treeToAdd->child[childIndex], value);
		return 0;
	}
	tmp = new tree;
	tmp->value = value;
	treeToAdd->childIndex = childIndex;
	treeToAdd->child[childIndex] = tmp;
	return 0;
}

int treeBrowse(tree* treeToBrowse) {
	if (treeToBrowse == NULL) return 0;
	cout << treeToBrowse->value << " " << treeToBrowse->childIndex << " ";
	if (treeToBrowse->childIndex == -1) return 0;
	if (treeToBrowse->child[treeToBrowse->childIndex] != NULL) treeBrowse(treeToBrowse->child[treeToBrowse->childIndex]);
	return 0;
}

int main() {
	root = new tree;
	cin >> root->value;
	while (true) {
		int x;
		cin >> x;
		if (!x) break;
		treeAdd(root, x);

	}
	treeBrowse(root);
	return 0;
}
