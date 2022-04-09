#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() { data = 0; next = nullptr; }
	Node(int x) {data = x; next = nullptr;}
};

class StaticStack {
public:
	int* A;
	int size;
	int top = -1;
	StaticStack(int n) {
		A = new int[ n ];
		size = n;
		for (int i = 0; i < n; i++) {
			A[i] = 0;
		}
	}

	void Pop() {
		if (top <= -1) {
			cout << "Stack is empty no more to pop"<<endl;
		}
		else {
			A[top] = 0;
			top--;
		}
	}

	int PopBack() {
		return A[top];
	}

	void Push(int x) {
		if (top>=size-1) {
			cout << "There is no more space in the stack!"<<endl;
		}
		else {

			top++;
			A[top] = x;
		}
	}

	void PrintInfo() {
		if (top == -1) {
			cout << "Nothing in stack no printing please!"<<endl;
		}
		else {
			for (int i = top - 1; i >= 0; i--) {
				cout << A[i] << " ";
			}
			cout << endl;
		}
		
	}
};

class DynamicStack {
public:
	Node* top;
	DynamicStack() { top = nullptr; }

	void Push(int x) {
		Node* newNode = new Node(x);
		top = newNode;
	}//place new node at "Top" of stack
	
	void Pop() {
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	void PrintInfo() {
		Node* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;

	}
	int StackTop() {
		if (top != nullptr) {

			return top->data;
		}
		else {
			cout << "Stack is empty";
		}
	}
};


int main() {


	DynamicStack* Stack = new DynamicStack();
	Stack->Push(10);	Stack->PrintInfo();
	Stack->Push(4);		Stack->PrintInfo();
	Stack->Push(1);		Stack->PrintInfo();
	Stack->Push(8);		Stack->PrintInfo();
	Stack->StackTop();	Stack->PrintInfo();
	Stack->Pop();		Stack->PrintInfo();
	/*
	StaticStack* stack = new StaticStack(6);
	stack->PrintInfo();

	stack->Push(5);		stack->PrintInfo();
	stack->Push(10);	stack->PrintInfo();
	stack->Push(3);		stack->PrintInfo();
	stack->Push(7);		stack->PrintInfo();
	stack->Push(12);	stack->PrintInfo();
	stack->Push(6);		stack->PrintInfo();
	
	stack->Pop();		stack->PrintInfo();
	
	*/
}