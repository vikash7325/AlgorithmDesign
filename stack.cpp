#include<iostream>
using namespace std;
#define STACK_MAX_SIZE 10
class stack{
	int top;
	int elements[STACK_MAX_SIZE];
public:
	stack();
	void insert(int i);
	int pop();
	bool isEmpty();
	bool isFull();
	void display();
};
stack::stack(){
	top = -1;
}
void stack::insert(int elem){
	if (isFull()){
		cout<<"Stack is full"<<"\n";
		return;
	}
	top++;
	elements[top] = elem;
	return;
}
int stack::pop(){
	int elem = elements[top];
	top--;
	return elem;
}
bool stack::isEmpty(){
	if (top == -1){
		return true;
	}
	return false;
}
bool stack::isFull(){
	if (top == STACK_MAX_SIZE - 1){
		return true;
	}
	return false;
}
void stack::display(){
	int index;
	cout<<"\n"<<"New Stack Is"<<"\n";
	for (index=0; index<= top; index++){
		cout<<elements[index]<<"\n";
	}
}
int main(){
	stack s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	s.insert(7);
	s.insert(8);
	s.insert(9);
	s.insert(10);
	s.insert(11);
	s.display();
	int p = s.pop();
	cout<<"\nPopped element is "<<p<<"\n";
	s.display();
	p = s.pop();
	cout<<"\nPopped element is "<<p<<"\n";
	s.display();
	return 0;
}
