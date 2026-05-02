#include "CDeque.h"

CDeque& CDeque::operator=(const CDeque& other)
{
	if (this != &other) {
		delete[] array;
		size = other.size;
		array = new double[size];
		for (int i = 0; i < other.size; i++) {
			array[i] = other.array[i];
		}
	}
	return *this;
}

CDeque& CDeque::operator=(CDeque&& other) noexcept {
	if (this != &other)
	{
		delete[] array;
		array = other.array;
		size = other.size;
		other.array = nullptr;
		other.size = 0;
	}
	return *this;
}

void CDeque::addLeft(double data)
{
	try {
	double* newArr = new double[size + 1];
	newArr[0] = data;
	for (int i = 0; i < size; i++) {
		newArr[i + 1] = array[i];
	}

	delete[] array;
	array = newArr;

	size++;
	}
	catch (const std::bad_alloc) {
		throw Memory();
	}
}

void CDeque::addRight(double data)
{
	try {
	double* newArr = new double[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = array[i];
	}
	newArr[size] = data;

	delete[] array;
	array = newArr;

	size++;
	}
	catch (std::bad_alloc) {
		throw Memory();
	}
}

void CDeque::deleteLeft()
{
	if (isEmpty()) throw Empty("Error with deleting element from left!");
	double* newArr = new double[size - 1];
	for (int i = 1; i < size; i++) {
		newArr[i - 1] = array[i];
	}
	delete[] array;
	array = newArr;
	size--;
}

void CDeque::deleteRight()
{
	if (isEmpty()) throw Empty("Error with deleting element from right!");
	double* newArray = new double[size - 1];
	for (int i = 0; i < size - 1; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
	size--;
}

int CDeque::getSize() const noexcept
{
	return size;
}

double CDeque::getAvg()
{
	if (isEmpty()) throw Avg();
	double* Sum = new double;
	*Sum = 0;
	for (int i = 0; i < size; i++) *Sum += array[i];
	return (double)(*Sum) / size;
}

void CDeque::clearAll() noexcept
{
	delete[] array;
	array = nullptr;
	size = 0;
	std::cout << "Clear Success!" << std::endl;
}

bool CDeque::isEmpty() const noexcept
{
	return size == 0;
}

CDeque CDeque::operator+(const CDeque& other) const
{
	if (size != other.size) throw Size();
	CDeque res;
	res.size = other.size;
	res.array = new double[res.size];
	for (int i = 0; i < other.size; i++) {
		res.array[i] = array[i] + other.array[i];
	}
	return res;
}

CDeque CDeque::operator-(const CDeque& other) const
{
	if (size != other.size) throw Size();
	
	CDeque res;
	res.size = other.size;
	res.array = new double[other.size];
	for (int i = 0; i < other.size; i++) {
		res.array[i] = array[i] - other.array[i];
	}
	return res;
}

CDeque CDeque::operator*(double scalar) const
{
	CDeque res;
	res.size = size;
	res.array = new double[res.size];

	for (int i = 0; i < res.size; i++) {
		res.array[i] = array[i] * scalar;
	}
	return res;
}

std::istream& operator>>(std::istream& in, CDeque& cl)
{
	std::cout << "Enter Size: ";
	int tmp_s;
	if (!(in >> tmp_s)) throw InOuErr();
	if (tmp_s < 0) throw MyErrorClass("Size cant be < 0!");

	double* tmp_arr = nullptr;
	if (tmp_s > 0) {
		try { tmp_arr = new double[tmp_s]; }
		catch (const std::bad_alloc&) { throw Memory(); }
	}

	for (int i = 0; i < tmp_s; i++) {
		if (!(in >> tmp_arr[i])) {
			delete[] tmp_arr;
			throw InOuErr();
		}
	}
	delete[] cl.array;
	cl.array = tmp_arr;
	cl.size = tmp_s;
	return in;
}

std::ostream& operator<<(std::ostream& out, const CDeque& cl)
{
	if (!out) throw InOuErr();
	if (cl.isEmpty()) {
		out << "Queue is empty";
		return out;
	}
	for (int i = 0; i < cl.size; i++) {
		out << cl.array[i] << " ";
	}
	return out;
}