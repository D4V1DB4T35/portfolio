#include <iostream>

using namespace std;

class StaticQueue {
public:
	int* A;
	int size;
	int front = -1;
	int end = -1;
	StaticQueue(int n) {
		A = new int[n];
		size = n;
		for (int i = 0; i < n; i++) { A[i] = 0; }

	}

	int PeekQueue() {
		return A[front];
	}

	void Enqueue(int x) {
		if (isFull()) {
			cout << "No space left in queue try again later!";
		}
		else {
			if (isEmpty()) {
				front++;
			}
			else {
				end++;
				A[end] = x;
			}
		}
		
	}//add to back of the queue

	void Dequeue() {
		if (isEmpty()) {
			cout << "Nothing to Dequeue, Queue is empty";
			return;
		}

		if (front == end && !isEmpty()) {
			front = -1;
			end = -1;
		}
		else {
			front++;
		}
			
	}//remove from the queue
	bool isFull() {
		if (end >= size - 1)return true;
		else                return false;
	}
	bool isEmpty() {
		if (front == -1 && end == -1)	return true;
		else							return false; 
	}
	void PrintInfo() {
		if (isEmpty()) {
			cout << "Nothing to print, Queue is empty."<<endl;
			return;
		}
		for (int i = front; i < end; i++) {
			cout << A[i] << " ";
			cout << endl;
		}
	}
};//None of this works
class DynamicQueue {
	class Node {
	public:
		int data;
		Node* next;
		Node() { next = nullptr; }
		Node(int x) { data = x; next = nullptr; }

	};
public:
	Node* front;
	DynamicQueue() { front = nullptr; }
	void Enqueue(int x) {
		Node* newNode = new Node(x);
		if (isEmpty()) {
			front = newNode;
		}
		else {
			Node* temp = front;
			while (temp != nullptr && temp->next != nullptr) {
				temp = temp->next;
			}

			temp->next = newNode;
		}
	}

	void Dequeue() {

		if (isEmpty()) {
			cout << "Nothing to dequeue\n";
		}
		else {
			Node* nodeToBeDeleted = front;
			front = front->next;

			delete nodeToBeDeleted;
		}
		
	}

	bool isEmpty() {
		if (front == nullptr) {
			return true;
		}
		else { return false; }
	}

	void PrintInfo() {
		Node* temp = front;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;

		}
		cout << endl;

	}


};

int main() {
	
	DynamicQueue* queue = new DynamicQueue();

	queue->Enqueue(1);		queue->PrintInfo();
	queue->Enqueue(2);		queue->PrintInfo();
	queue->Enqueue(3);		queue->PrintInfo();
	queue->Enqueue(4);		queue->PrintInfo();
	queue->Enqueue(5);		queue->PrintInfo();

	queue->Dequeue();		queue->PrintInfo();

	/*
	StaticQueue* queue = new StaticQueue(6);

	queue->Enqueue(5);		queue->PrintInfo();
	queue->Enqueue(7);		queue->PrintInfo();
	queue->Enqueue(3);		queue->PrintInfo();
	queue->Enqueue(9);		queue->PrintInfo();
	queue->Enqueue(10);		queue->PrintInfo();

	
	return 0;
	
	None of this works Bro you got to fix it 


	*/
}