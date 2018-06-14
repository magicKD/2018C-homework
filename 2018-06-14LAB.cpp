#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>

class Table 
{
private:
	map<string, int> MapCol;
	map<int, int> MapRow;
	vector<string> Row[100];
	vector<string> headCol;
	vector<string> headRow;
	int colNum;
	int rowNum;
public:
	Table() {
		colNum = rowNum = 0;
	}
	void addCol(string str) {
		MapCol[str] = colNum;
		headCol.push_back(str);
		colNum++;
	}
	vector<string> & operator [] (int index) {
		if (index >= rowNum) {
			rowNum++;
		}
		return Row[index];
	}

	string json() const {
		string str = "";
		str += "{\n";
		//headers
		str += "\theaders:[";
		for (int i = 0; i < colNum; i++) {
			str += "'" + headCol[i] + "'" + ",";
		}
		str += "],\n";
		//rows
		str += "\trows:[\n";
		for (int i = 0; i < rowNum; i++) {
			str += "\t\t";
			str += "[";
			for (int j = 0; j < colNum; j++) {
				str += "'" + Row[i][j] + "',";
			}
			str += "],";
			str += "\n";
		}
		str += "\t],\n";
		//endrows
		str += "}\n";
		return str;
	}
};

ostream & operator << (ostream & out, const Table & table) {
	out << table.json() << endl;
	return out;
}

int main() {
	Table t1;
	t1.addCol("AA");
	t1.addCol("BB");
	vector<string> vec;
	vec.push_back("123");
	vec.push_back("456");
	t1[0] = vec;
	vec[0] = "234";
	vec[1] = "567";
	t1[1] = vec;
	cout << t1 << endl;
}
