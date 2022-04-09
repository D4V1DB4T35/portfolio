#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node()		{ data = 0; next = nullptr; }
	Node(int x) { data = x; next = nullptr; }

	void PrintInfo() {
		cout << data << " " << next << endl;
	}
};

class LinkedList {
public:
	Node* head;
	LinkedList() { head = nullptr; }
	void AddAtHead(int x) {
		Node* newNode = new Node(x);
		newNode->next = head;
		head = newNode;
	}
	void AddAtEnd(int x) {
		Node* newNode = new Node(x);
		if (head == nullptr) {
			head = newNode;
		}
		else {//go to end of list and add new node there
			//find last node
			Node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}//moves the temp value to the end of the list
			temp->next = newNode;
			//sets the new node to the node that would be after the last node
		}
	}
	void AddAtPosition(int x, int pos) {
		Node* newNode = new Node(x);

		Node* temp = head;

		if (pos == 1) {
			AddAtEnd(x);
		}
		else
		{
		for (int i = 1; i <= pos - 2; i++) {
			temp = temp->next;
		}//moves to the position where we want to hook up the new piece of data. 

		newNode->next = temp->next;
		temp->next = newNode; 
		}

		
	}
	void UpdateAtPosition(int x, int pos) {
		Node* temp = head;

		for (int i = 1; i <= pos-1; i++) {
			temp = temp->next;
		}//moves to the position where we want to hook up the new piece of data.

		temp->data = x;
	}
	void UpdateByValue(int up, int x) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data == x) {
				temp->data = up;
			}//changes data to updated data if parameters match
			temp = temp->next;
		}//cycle through the node
	}
	int FindPositionByValue(int x) {
		Node* temp = head;
		int pos = 1;
		bool isFound = false;
		while (temp != nullptr) {
			if (temp->data == x) {
				return pos;
				isFound = true;
				break;
			}
			else {
				pos++;
				temp = temp->next;
			}
		}//cycle through the 
		if (isFound == false) {
			return -1;
		}
	}
	int CountByValue(int x) {
		Node* temp = head;
		int count = 0;
		while (temp != nullptr) {
			if (temp->data == x) {
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
	int CountNodes() {
		Node* temp = head;
		int counter = 0;
		while (temp != nullptr) {
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	void DeleteAtHead() {
		Node* temp = head;
		head = head->next;

		delete temp;
	}//deletes the first node in memory. 
	void DeleteAtEnd() {
		Node* temp = head;
		if (CountNodes() == 1) {
			DeleteAtHead();
		}
		else {
			
			while (temp->next != nullptr && temp->next->next != nullptr) {
				temp = temp->next;
			}
		}
		
		Node* nodeTobeDeleted = temp->next;
		temp->next = nullptr;
		delete nodeTobeDeleted;
	}
	void DeleteAtPosition(int pos) {

		Node* temp = head;

		if (pos == 1) {
			DeleteAtHead();
		}
		else
		{
			for (int i = 1; i <= pos - 2; i++) {
				temp = temp->next;
			}//moves to the position where we want to hook up the new piece of data. 

			if (temp->next == nullptr) {
				DeleteAtEnd();
			}
			else {
				Node* nodeTobeDeleted = temp->next;
				temp->next = temp->next->next;
				delete nodeTobeDeleted;
			}
			
			
		}
	}
	void DeleteByValue(int x) {
		int n = CountByValue(x);
		for (int i = 0; i < n; i++) {
			int pos = FindPositionByValue(x);
			DeleteAtPosition(pos);
		}
		
	}
	void PrintInfo() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	~LinkedList() {
		int n = CountNodes();

		for (int i = 0; i < n; i++) {
			cout << "Deleteing node: " << n << endl;

			DeleteAtHead();
		}
	}
};
//-----------------------User-----------------------
int main() {
	//**************************************************************
	//*******************Automated Model****************************
	//**************************************************************
	LinkedList* list = new LinkedList();
	for (int i = 0; i < 20; i++) {
		list->AddAtEnd(rand() % 10 + 1);
	}

	list->PrintInfo();
	list->DeleteByValue(2);
	list->PrintInfo();
	/*
	cout << "******************************************************************\n";
	list->AddAtEnd(1);		list->PrintInfo(); //1
	list->AddAtEnd(2);		list->PrintInfo(); //1 2
	list->AddAtEnd(4);		list->PrintInfo(); //1 2 3
	list->AddAtEnd(4);		list->PrintInfo(); //1 2 3 4
	list->AddAtEnd(5);		list->PrintInfo(); //1 2 3 4 5
	//list->DeleteAtPosition(3); list->PrintInfo();//1 2 4 5
	list->DeleteByValue(4);	list->PrintInfo(); //1 2 5
	cout << "**************************************************************\n";
	
	*/
	
	/*
	//**************************************************************
	//********************By*Hand*Model*****************************
	//**************************************************************
	Node* head = new Node(4); 
	Node* node2 = new Node(8);

	head->next = node2;
	head->next->next = new Node(12);
	head->next->next->next = new Node(4);

	cout <<head->data << "  " << head->next << endl;
	cout <<head->next->data<<"  " << head->next->next << endl;
	cout << head->next->next->data << "  " << head->next->next->next << endl;

	*/
	//******************************************************************************************************
	//Doing by hand is very un-sustainable especialy for thousands of entries we must think of an automatic
	//way of doing things Which would make it a whole lot easier for the user to create these nodes of memory
	//******************************************************************************************************
}
