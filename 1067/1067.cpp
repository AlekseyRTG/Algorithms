#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Dir {

	private: map<string, Dir*> childDirs;

	public:
		Dir() {}

		Dir* getDir(string name) {
			if (childDirs.find(name) != childDirs.end()) return childDirs[name];
			else return createDir(name);
		}

		Dir* createDir(string name) {
			childDirs[name] = new Dir();
			return childDirs[name];
		}

		void printTree(string separator = "") {
			string tabs = " ";
			tabs += separator;
			map<string, Dir*> contents(childDirs.begin(), childDirs.end());
			for (auto it = contents.begin(); it != contents.end(); it++) {
				cout << separator << it->first << endl;
				it->second->printTree(tabs);
			}
		}
};

int main() {
	int n;
	cin >> n;
	Dir* root = new Dir();
	for (int i = 0; i < n; i++) {
		Dir* currentDir = root;
		string fullPath, name;
		cin >> fullPath;
		stringstream ss(fullPath);
		while (getline(ss, name, '\\'))
			currentDir = currentDir->getDir(name); //здесь '\\' - это экраннированный символ '\'
	}
	root->printTree();
	return 0;
}
