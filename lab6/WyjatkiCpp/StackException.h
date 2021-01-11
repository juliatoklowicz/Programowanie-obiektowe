#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class StackException : public exception
{
public:
	StackException() {}
	virtual const char* what() const noexcept override
	{
		return "Bledna operacja na stosie!";
	}
};

class StackFullException : public StackException {
	int element = 0;
	int maxStackSize = 0;
	mutable string message;
public:
	StackFullException() {}
	StackFullException(string p , int e , int s)
	{
        element = e;
        maxStackSize = s;
        message = p;
	}

	virtual const char* what() const noexcept override
	{
        string x = "Nadmiarowy element: ";
		x += to_string(element);
		x += " Maksymalny rozmiar stosu: " + to_string(maxStackSize);
		x += " " + message;
		message = x;
		return message.c_str();
	}
};

class StackEmptyException : public StackException 
{
private:
	mutable string message;
public:
	StackEmptyException() { }
	StackEmptyException(string p) 
	{
        message = p;
	}

	virtual const char* what() const noexcept override 
	{
		string x = "Pusty stos. ";
		x += message;
		message = x;
		return message.c_str();
	}
};

#endif

