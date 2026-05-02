#pragma once
#include <iostream>
#include "MyError.h"
class CDeque
{
private:
	double* array;
	int size;

public:
	CDeque() noexcept{
		array = nullptr;
		size = 0;
	}
	CDeque(int n, double data) {
		if (n < 0) throw MyErrorClass("Size cant be < 0!");
		if (n > 1000) throw Memory();
		size = n;
		array = new double[size];
		for (int i = 0; i < size; i++) array[i] = data+i;
	}

	CDeque(const CDeque& other) { //конструктор копіювання
		size = other.size;

		array = new double[other.size];
		for (int i = 0; i < other.size; i++) {
			array[i] = other.array[i];
		}
	}
	CDeque(CDeque&& other) noexcept { //конструктор переміщення
		array = other.array;
		size = other.size;
		other.array = nullptr;
		other.size = 0;
	}
	~CDeque() { //деструктор для видалення пам'яті
		delete[]array;
		size = 0;
	}

	CDeque& operator=(const CDeque& other); //оператор прирівнювання
	CDeque& operator=(CDeque&& other) noexcept; //оператор переміщення


	void addLeft(double data); //додати число зліва
	void addRight(double data); //додати число справа


	void deleteLeft(); //видалити число зліва
	void deleteRight(); //видалити число справа


	int getSize() const noexcept; //розмір
	double getAvg(); // сер. значення
	void clearAll() noexcept; //очистити чергу
	bool isEmpty() const noexcept; //чи пуста черга


	//оператори перевантаження + - *
	CDeque operator+(const CDeque& other) const;
	CDeque operator-(const CDeque& other) const;
	CDeque operator*(double scalar) const;

	//Ввід вивід
	friend std::istream& operator>>(std::istream& in, CDeque& cl);
	friend std::ostream& operator<<(std::ostream& out, const CDeque& cl);
};

