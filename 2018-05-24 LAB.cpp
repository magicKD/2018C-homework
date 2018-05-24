#include <iostream> 
#include <string> 
#include <vector> 
#include <cstring>
using namespace std; 
 
string readAll() { 
    string all; 
    string line; 
    while (getline(cin, line)) 
        all += line + '\n'; 
    return all; 
} 

vector<string> V;
vector<char> temp;

bool isDigit(char c){
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isAlph(char c){
	if (c >= 'a' && c <= 'z'){
		return true;
	}
	if (c >= 'A' && c <= 'Z'){
		return true;
	}
	return false;
}

void addStr(){
	char container[100];
	if (temp.size() == 0)	return;
	for (int i = 0; i < temp.size(); i++){
		container[i] = temp[i];
	}
	container[temp.size()] = 0;
	//cout << "addStr: " << container << endl;
	string s = container;
	V.push_back(s);
	temp.clear();
}

vector<string> lexicalAnalysis(string str){
	
	for (int index = 0; index < str.length(); index++){
		if (isDigit(str[index]) || isAlph(str[index])){
			temp.push_back(str[index]);
		}
		else if (str[index] == '-' && str[index+1] == '>'){
			string s = "->";
			V.push_back(s);
			str[index+1] = ' ';
			continue;
		}
		else if (str[index] == '<' && str[index+1] == '<' ){
			string s = "<<";
			V.push_back(s);
			str[index+1] = ' ';
			continue;
		}
		else if (str[index] != ' ' && str[index] != '\n'){
			addStr();
			char container[10];
			container[0] = str[index];
			container[1] = 0;
			string s = container;
			V.push_back(s);
		}
		else if (str[index] == ' ' || str[index] == '\n'){
			if (!temp.empty()){
				addStr();
			}
		}
	}
	return V;
}
 
int main() { 
    string program = readAll(); 
    vector<string> words = lexicalAnalysis(program); 
    for (int i = 0; i < words.size(); ++ i) { 
        cout << words[i] << endl; 
    } 
} 
