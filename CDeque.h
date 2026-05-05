#pragma once
#include <iostream>
#include "MyError.h"
template <typename T>
class CDeque
{
private:
	T* array;
	int size;

public:
	CDeque() noexcept{
		array = nullptr;
		size = 0;
	}
	CDeque(int n, T data) {
		if (n < 0) throw MyErrorClass("Size cant be < 0!");
		if (n > 1000) throw Memory();
		size = n;
		array = new T[size];
		for (int i = 0; i < size; i++) array[i] = data;
	}

	CDeque(const CDeque& other) { //конструктор копіювання
		size = other.size;

		array = new T[other.size];
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

	CDeque& operator=(const CDeque& other) {
		if (this != &other) {
			delete[] array;
			size = other.size;
			array = new T[size];
			for (int i = 0; i < other.size; i++) {
				array[i] = other.array[i];
			}
		}
		return *this;
	} //оператор прирівнювання

	CDeque& operator=(CDeque&& other) noexcept {
		if (this != &other)
		{
			delete[] array;
			array = other.array;
			size = other.size;
			other.array = nullptr;
			other.size = 0;
		}
		return *this;
	} //оператор переміщення

	void addLeft(T data) {
		T* newArr = nullptr;
		try {
			newArr = new T[size + 1];
			newArr[0] = data;
			for (int i = 0; i < size; i++) {
				newArr[i + 1] = array[i];
			}

			delete[] array;
			array = newArr;

			size++;
		}
		catch (const std::bad_alloc&) {
			throw Memory();
		}
	} //додати число зліва

	void addRight(T data) {
		T* newArr = nullptr;
		try {
			newArr = new T[size + 1];
			for (int i = 0; i < size; i++) {
				newArr[i] = array[i];
			}
			newArr[size] = data;

			delete[] array;
			array = newArr;

			size++;
		}
		catch (std::bad_alloc&) {
			throw Memory();
		}
	} //додати число справа

	void deleteLeft() {
		if (isEmpty()) throw Empty("Error with deleting element from left!");
		
		if (size == 1) {
			delete[] array;
			array = nullptr;
			size = 0;
			return;
		}

		T* newArr = new T[size - 1];
		for (int i = 1; i < size; i++) {
			newArr[i - 1] = array[i];
		}
		delete[] array;
		array = newArr;
		size--;
	} //видалити число зліва

	void deleteRight() {
		if (isEmpty()) throw Empty("Error with deleting element from right!");
		
		if (size == 1) {
			delete[] array;
			array = nullptr;
			size = 0;
			return;
		}

		T* newArray = new T[size - 1];
		for (int i = 0; i < size - 1; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
		size--;
	} //видалити число справа

	int getSize() const noexcept {
		return size;
	} //розмір

	T* getArray() const noexcept {
		return array;
	}

	void clearAll() noexcept {
		delete[] array;
		array = nullptr;
		size = 0;
		std::cout << "Clear Success!" << std::endl;
	} //очистити чергу

	bool isEmpty() const noexcept {
		return size == 0;
	}

	//оператори перевантаження + - *
	CDeque operator+(const CDeque& other) const
	{
		if (size != other.size) throw Size();
		CDeque res;
		res.size = other.size;
		res.array = new T[res.size];
		for (int i = 0; i < other.size; i++) {
			res.array[i] = array[i] + other.array[i];
		}
		return res;
	}

	CDeque operator-(const CDeque& other) const
	{
		if (size != other.size) throw Size();

		CDeque res;
		res.size = other.size;
		res.array = new T[other.size];
		for (int i = 0; i < other.size; i++) {
			res.array[i] = array[i] - other.array[i];
		}
		return res;
	}

	CDeque operator*(int scalar) const
	{
		CDeque res;
		res.size = size;
		res.array = new T[res.size];

		for (int i = 0; i < res.size; i++) {
			res.array[i] = array[i] * scalar;
		}
		return res;
	}

	bool operator==(const CDeque& other) const{
		if (this->size != other.size) return false;
		for (int i = 0; i < other.size; i++) {
			if (!(array[i] == other.array[i])) return false;
		}
		return true;
	}

	//Ввід вивід
	friend std::istream& operator>>(std::istream& in, CDeque& cl)
	{
		T value;
		
		while (in >> value) {
			cl.addRight(value);
		}
		
		in.clear();
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const CDeque& cl)
	{
		if (!out) throw InOuErr();
		if (cl.isEmpty()) {
			out << "Queue is empty";
			return out;
		}
		for (int i = 0; i < cl.size; i++) {
			out << cl.array[i] << " ";
		}
		out << std::endl;
		return out;
	}
};

template<typename T> 
int FindElementInArray(T* array, int size, T element) {
	for (int i = 0; i < size; i++) {
		if (array[i] == element) return i;
	}
	return size;
}