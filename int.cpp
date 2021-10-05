#include <iostream>

class Int {
	int data;

public:
	Int(int data) :data(data) {}
	Int(const Int& i) :data(i.data) {}

	operator int() { return data; }

	Int& operator++(); //���� ���� ����
	Int operator--();
	Int& operator++(int x); // ���� ���� ����
	Int operator--(int x);

};

Int& Int::operator++()
{
	data++;
	return *this;
}

Int Int::operator--()
{
	data--;
	return *this;
}

Int& Int::operator++(int x)
{
	Int temp(x);
	x++;
	return temp;
}

Int Int::operator--(int x)
{
	Int temp(x);
	x--;
	return temp;
}

//int main() {
//	Int a(3);
//
//	std::cout << a << a++ << ++a << std::endl;
//}