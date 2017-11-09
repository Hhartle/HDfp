//============================================================================
// Name        : Amazon.cpp
// Author      : Hans Hartle and Dante Colucci
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
tbd=to be determined
Display every loop:
Menu
~~~~~~~tbd
~~~~~~tbd
*/

#include <iostream>
#include <string>
using namespace std;

struct Product {
	int productID;
	string productName;
};

struct Cart {
	Product products[10];
	int quantities[10];
};

struct Queue {
	int size;
	int front;
	int rear;
	int QUEUE_MAX=50;
	Cart data[QUEUE_MAX];
};

Cart Queue_Front(Queue q){
	if(q.size == 0) {
		cout << "There are no current orders" << endl;
		return 0;
		// Have to deal with outside of method call
	} else {
		return q.data[0]; 
	}
}

void Queue_Deque(Queue q){
	if(q.size == 0){
		cout << "Error: No additional orders to deliver" << endl;
	} else {
		q.size--;
		q.front++;
		if(q.front==q.QUEUE_MAX){
			q.front=0;
		}
	}
}

void Queue_Enqueue(Queue q, Cart c){
	if(q.size < q.QUEUE_MAX){
		q.size++;
		q.rear++;
		
		if(q.rear == q.QUEUE_MAX){
			q.rear = 0;
		}
		q.data[q.rear] = c;
	} else {
		cout << "Error: Order Queue is full" << endl;
	}
}

int main() {	
	int exit = 0;
	string command;
	while(exit != 1) {
		cout<<"Please enter a command!" << endl;
		cin >> command;

		if (command == "EXIT") {
			exit=1;
		} else if (command == "ORDER") {

		} else if (command == "DELIVERY") {

		} else {
			cout << "Unrecognized command, please try again" << endl;
		}
	}

	return 0;
}
