#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;


class Master {
private:
	string name;
public:
	Master(string name) { this->name = name; }
	string getName() { return this->name; }
	void setName(string name) { this->name = name; }
};

class Pet {
public:
	Master * pMaster;
public:
	Pet(string name) { pMaster = new Master(name); }
	string getMaster() { return pMaster->getName(); }
	void changeMaster(string name) { pMaster->setName(name); }
	void setMaster(Master *p) { this->pMaster = p; }
};

class Dog;

class Cat : public Pet {
private:
	Dog * pDog;
public:
	Cat(string name) : Pet(name) {}
	Dog& getPeer() { return *pDog; }
};

class Dog: public Pet{
private:
	Cat * pCat;
public:
	Dog(string name) : Pet(name) { pCat = new Cat(name); pCat->pMaster = this->pMaster; }
	Cat& getPeer() { return *pCat; }
};

int main() {
	string name1, name2;
	cin >> name1 >> name2; // XiaoMing XiaoHong 
	Master somebody(name1);
	Dog snoopy(somebody.getName());
	Cat helloKitty = snoopy.getPeer();
	cout << helloKitty.getMaster() << endl; // XiaoMing 
	snoopy.changeMaster(name2);
	cout << helloKitty.getMaster() << endl; // XiaoHong 
	helloKitty.changeMaster(name1);
	cout << snoopy.getMaster() << endl; // XiaoMing 
}