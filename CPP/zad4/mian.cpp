#include <iostream>
#include <string>

#include "lifo.hpp"

using namespace std;

void run_test();

int main(int argc, char const *argv[])
{
	int controller = 0;
	string s;
	int temp;
	
	cout << "What is the capacity to be?" << endl;
	cin >> temp;
	try{
		Stack stack(temp);
		while(controller != 6 && controller != 7){
		cout << endl;
		cout << "What do you want?" << endl;
		cout << "1. Push new element." << endl;
		cout << "2. Pop element from stack." << endl;
		cout << "3. Peek the highest elemnet." << endl;
		cout << "4. Your stack size." << endl;
		cout << "5. Reverse your stack." << endl;
		cout << "6. Show tests and exit." << endl;
		cout << "7. Exit." << endl;
		cin >> controller;

		switch(controller){
			case 1:
				cout << "Print your element:" << endl;
				cin >> s;
				try{
					stack.push(s);
				}
				catch(out_of_range& e){
					clog << e.what() << endl;
				}
				break;
			case 2:
				try{
					cout << "Last element: " << stack.pop() << " is deleted." << endl; 
				}
				catch(range_error& e){
					clog << e.what() << endl;
				}
				break;
			case 3:
				try{
					cout << "At the top of the stack is: " << stack.peek() << endl;
				}
				catch(range_error& e){
					clog << e.what() << endl;
				}
				break;
			case 4:
				cout << "Your stack has " << stack.size << " element's" << endl; 
				break;
			case 5:
				stack.reverse();
				cout << "Your stack has been reversed" << endl;
				break;
			case 6:
				run_test();
				break;
			case 7:
				break;
			default:
				cout << "Wrong option!, choose number from 1 to 8!." << endl;
			}
		}
	}
	catch(invalid_argument& e){
		clog << e.what() << endl;
	}
}

void run_test(){
	Stack stack1;

	try{
		stack1.push("1");
	}
	catch(out_of_range& e){
		clog << e.what() << endl;
	}
	
	try{
		stack1.push("2");
	}
	catch(out_of_range& e){
		clog << e.what() << endl;
	}

	Stack stack2(3);
	Stack stack3({"first", "secound", "third", "fourth"});
	
	try{
		cout << stack3.pop() << endl; 
	}
	catch(range_error& e){
		clog << e.what() << endl;
	}
	stack3.reverse();
	try{
		cout << stack3.peek() << endl;
	}
	catch(range_error& e){
		clog << e.what() << endl;
	}
	try{
		stack2.push("xX_1_Xx");
	}
	catch(out_of_range& e){
		clog << e.what() << endl;
	}
	try{
		stack2.push("xX_2_Xx");
	}
	catch(out_of_range& e){
		clog << e.what() << endl;
	}
	try{
		stack1.push("xX_3_Xx");
	}
	catch(out_of_range& e){
		clog << e.what() << endl;
	}
	try{
		cout << stack2.pop() << endl; 
	}
	catch(range_error& e){
		clog << e.what() << endl;
	}
}