#ifndef CPOLYNOM3_H
#define CPOLYNOM3_H
#include <iostream>
#include <cmath>
class CPolynom3 {

	int a;
	int b;
	int c;

public:

	CPolynom3() {
		a = 0;
		b = 0;
		c = 0;
	}
	CPolynom3(int valueA, int valueB, int ValueC) {
		a = valueA;
		b = valueB;
		c = ValueC;
	}
	CPolynom3(int valueA, int valueB) {
		a = valueA;
		b = valueB;
		c = 0;
	}
	CPolynom3(int valueA) {
		a = valueA;
		b = 0;
		c = 0;
	}

	void SetA(int valueA);
	int GetA() const;

	void SetB(int valueB);
	int GetB() const;

	void SetC(int valueC);
	int GetC() const;

	int ResultAtX(int x) const;
	int DerivativeAtX(int x) const;
	void FindRoots() const;

	CPolynom3 operator+(const CPolynom3& otherClass) const;
	CPolynom3 operator-(const CPolynom3& otherClass) const;

	bool operator==(const CPolynom3& other) const;
	CPolynom3 operator*(int scalar) const;
	CPolynom3 operator-();

	friend std::ostream& operator<<(std::ostream& out, const CPolynom3& p);
	friend std::istream& operator>>(std::istream& in, CPolynom3& p);

};
#endif
