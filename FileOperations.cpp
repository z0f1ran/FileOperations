#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

static bool printFile(string path) {
	ifstream inFile(path);
	if (!inFile) {
		cout << "File didnt open!" << endl;
		return false;
	}
	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}
	return true;
}

static vector<string> readFile(string path) {
	ifstream inFile(path);
	vector<string> res = vector<string>();
	if (!inFile) {
		cout << "File didnt open!" << endl;
	}
	string line;
	while (getline(inFile, line)) {
		res.push_back(line);
	}
	return res;
}

static bool RewriteFile(vector<string> line, string path) {
	ofstream out;
	out.open(path);
	if (!out.is_open()) {
		cout << "file didnt open";
		return false;
	}
	else if (out.is_open())
	{
		for (unsigned long i = 0; i < line.size(); i++) {
			out << line[i] << endl;
		}
	}
	out.close();
	return true;
}

static bool AddToEndFile(vector<string> line, string path) {
	ofstream out(path, ios::app);
	if (!out.is_open()) {
		cout << "file didnt open";
		return false;
	}
	else if (out.is_open()){
		for (unsigned long i = 0; i < line.size(); i++) {
			out << line[i] << endl;
		}
	}
	out.close();
	return true;
}