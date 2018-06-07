#include <string> 
#include <vector> 
#include <iostream> 

#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

class Grammar
{
public:
	string to;
	vector<string> from;

	Grammar(string to, string from1, string from2 = "", string from3 = "", string from4 = "", string from5 = "") {
		this->to = to;
		if (from1.size() > 0) from.push_back(from1);
		if (from2.size() > 0) from.push_back(from2);
		if (from3.size() > 0) from.push_back(from3);
		if (from4.size() > 0) from.push_back(from4);
		if (from5.size() > 0) from.push_back(from5);
	}

	Grammar() {}
};

ostream & operator << (ostream & out, const Grammar & grammar) {
	out << grammar.to << "\t<=\t";
	for (int i = 0; i < grammar.from.size(); ++i)
		cout << grammar.from[i] << "  ";
	return out;
}

istream & operator >> (istream & in, Grammar & grammer) {
	string s, tmp;
	getline(cin, s);
	stringstream ss(s);
	vector<string> V;
	string to;
	ss >> to;
	ss >> tmp;
	while (ss >> tmp) {
		V.push_back(tmp);
	}
	grammer.to = to;
	grammer.from = V;
	return in;
}

int main() {
	for (int i = 0; i < 9; ++i) {
		Grammar grammar;
		cin >> grammar;
		cout << grammar << endl;
	}
}
