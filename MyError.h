#pragma once

#include <iostream>
#include <exception>

class MyErrorClass : public std::exception {
protected:
	std::string err_message;
public:
	MyErrorClass(const std::string msg) : err_message(msg){}
	~MyErrorClass()	{}
	const char* what() const noexcept override {
		return err_message.c_str();
	}
};

class Memory : public MyErrorClass {
public:
	Memory() :MyErrorClass("Error with allocation memory!") {}
};

class Empty : public MyErrorClass {
public:
	Empty(const std::string& msg = "Error with deleting element from an empty queue!") : MyErrorClass(msg) {}
};

class Avg : public MyErrorClass {
public:
	Avg() : MyErrorClass("Error with avg num in empty queue!") {}
};

class Size : public MyErrorClass {
public:
	Size(): MyErrorClass("Error with different size!") {}
};

class InOuErr : public MyErrorClass {
public:
	InOuErr(): MyErrorClass("Error with wrong input/output!") {}
};