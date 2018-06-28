#include <iostream>
#include <cstring>
#include <istream>
#include <ostream>

using namespace std;

class Integer {
public:
	Integer * t;
	int num;
public:
	Integer() { t = NULL; }
	Integer(int n) { t = NULL; num = n; }
	Integer& operator -= (Integer n) {
		num -= n.num;
		t->num -= n.num;
		return *this;
	}
	Integer& operator += (Integer n) {
		num += n.num;
		t->num += n.num;
		return *this;
	}
};

ostream & operator << (ostream & o, const Integer& x) {
	o << x.num;
	return o;
}

istream & operator >> (istream & is, Integer& x) {
	is >> x.num;
	return is;
}

void link(Integer& a, Integer& b) {
	a.t = &b;
	b.t = &a;
}

int main() {
	Integer a, b;
	cin >> a >> b;
	//a = 1000; b = 2000;
	cout << a << " " << b << endl;
	link(a, b);
	a -= 100;
	cout << a << " " << b << endl;
	b += a;
	cout << a << " " << b << endl;
}