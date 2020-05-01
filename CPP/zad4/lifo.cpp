#include "lifo.hpp"

Stack::Stack(){
	capacity = 1;
	size = 0;
	stack = new std::string[1];
}

Stack::Stack(int cap){
	if (cap < 1){
		capacity = 1;
		size = 0;
		stack = new std::string[1];
		throw std::invalid_argument("Wrong size! Program make default stack.");
	}
	else{
		capacity = cap;
		size = 0;
		stack = new std::string[cap];
	}
}

Stack::Stack(std::initializer_list<std::string> list){
	capacity = list.size();
	size = 0;
	stack = new std::string[list.size()];
	for (auto i : list)
		push(i);
}

Stack::Stack(Stack&& s){
	capacity = s.capacity;
	size = s.size;
	stack = s.stack;
}

Stack::Stack(const Stack& s){
	capacity = s.capacity;
	size = s.size;
	for(int i = 0; i < s.size - 1; i++)
		stack[i] = s.stack[i];

}
Stack::~Stack(){
	delete [] stack;
}

void Stack::push(std::string k){
	if(size >= capacity)
		throw std::out_of_range("Stack is full!");
	else{
		stack[size] = k;
		size++;
	}
}

std::string Stack::pop(){
	if (size == 0)
		throw std::range_error("Stack is empty!");
	else{
		std::string ret = stack[--size];
		stack[size] = "";
		return ret;
	}	
}

std::string Stack::peek(){
	if (size == 0)
		throw std::range_error("Stack is empty!");
	else
		return stack[size - 1];
}

void Stack::reverse(){
	int top = size - 1;
	for (int bot = 0; bot < top; top--, bot ++){
		stack[bot].swap(stack[top]);
	}
}