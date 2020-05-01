#ifndef LIFO_HPP
#define LIFO_HPP

#include <string>
#include <stdexcept>

class Stack
{
private:
	int capacity;
	std::string* stack = nullptr;
public:
	int size;

	Stack();
	Stack(int);
	Stack(std::initializer_list<std::string>);
	Stack(Stack&&);
	Stack(const Stack&);

	~Stack();
	
	void push(std::string k);
	std::string pop();
	std::string peek();
	void reverse();
};

#endif