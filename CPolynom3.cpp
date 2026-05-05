#include <iostream>
#include "cpolynom3.h"

int CPolynom3::GetA() const {
	return a;
}
void CPolynom3::SetA(int valueA) {
	a = valueA;
}

int CPolynom3::GetB() const {
	return b;
}
void CPolynom3::SetB(int valueB) {
	b = valueB;
}

int CPolynom3::GetC() const {
	return c;
}
void CPolynom3::SetC(int valueC) {
	c = valueC;
}

int CPolynom3::ResultAtX(int x) const {
	return a * x * x + b * x + c;
}

int CPolynom3::DerivativeAtX(int x) const {
	return a * 2 * x + b;
}

void CPolynom3::FindRoots() const {
	if (a == 0 && b != 0) {
		double res = (double)(-c) / b;
		printf("There is 1 root: %lf", res);
	}
	else {
		int D = b * b - 4 * a * c;
		if (D < 0) {
			printf("There is no root.");
			return;
		}
		else if (D == 0) {
			double res = (-b) / (a * 2.0);
			printf("There is 1 root: %lf", res);
		}
		else {
			double x1 = (-b - sqrt(D)) / (a * 2.0);
			double x2 = (-b + sqrt(D)) / (a * 2.0);
			printf("There is 2 roots: x1 = %lf; x2 = %lf", x1, x2);
		}
	}

}

CPolynom3 CPolynom3::operator+(const CPolynom3& otherClass) const{
	CPolynom3 res;
	res.a = a + otherClass.a;
	res.b = b + otherClass.b;
	res.c = c + otherClass.c;
	return res;
}

CPolynom3 CPolynom3::operator-(const CPolynom3& otherClass) const{
	CPolynom3 res;
	res.a = a - otherClass.a;
	res.b = b - otherClass.b;
	res.c = c - otherClass.c;
	return res;
}
CPolynom3 CPolynom3::operator*(int scalar) const{

	CPolynom3 res;
	res.a = a * scalar;
	res.b = b * scalar;
	res.c = c * scalar;
	return res;
}

CPolynom3 CPolynom3::operator-() {
	CPolynom3 res;
	res.a = -a;
	res.b = -b;
	res.c = -c;
	return res;
}

bool CPolynom3::operator==(const CPolynom3& other) const {
	return (a == other.a && b == other.b && c == other.c);
}

std::ostream& operator<<(std::ostream& out, const CPolynom3& p)
{
	out << p.GetA() << " " << p.GetB() << " " << p.GetC();
	return out;
}

std::istream& operator>>(std::istream& in, CPolynom3& p)
{
	int tmp_a, tmp_b, tmp_c;
	in >> tmp_a >> tmp_b >> tmp_c;
	p.SetA(tmp_a);
	p.SetB(tmp_b);
	p.SetC(tmp_c);
	return in;
}

