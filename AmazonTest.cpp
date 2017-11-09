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
const int QUEUE_MAX=50;

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
	Cart data[QUEUE_MAX];
};

Cart Queue_Front(Queue q){
	if(q.size == 0) {
		cout << "There are no current orders" << endl;
		// return empty cart
		Cart cart;
		return cart;
	} else {
		return q.data[0];
	}
}

void Queue_Dequeue(Queue q){
	if(q.size == 0){
		cout << "Error: No additional orders to deliver" << endl;
	} else {
		q.size--;
		q.front++;
		if(q.front==QUEUE_MAX){
			q.front=0;
		}
	}
}

void Queue_Enqueue(Queue q, Cart c){
	if(q.size < QUEUE_MAX){
		q.size++;
		q.rear++;

		if(q.rear == QUEUE_MAX){
			q.rear = 0;
		}
		q.data[q.rear] = c;
	} else {
		cout << "Error: Order Queue is full" << endl;
	}
}


int main() {	
	Queue queue;

	int exit = 0;
	string command;
	while(exit != 1) {
		cout<<"Please enter a command!" << endl;
		cin >> command;

		if (command == "EXIT") {
			exit=1;
		} else if (command == "ORDER") {
			cout<<"Please enter your order" << endl;
			int productID, quantity;
			string productName;
			cin >> productID >> productName >> quantity;

			Product product;
			Cart cart;

			product.productID = productID;
			product.productName = productName;
			cart.products[0] = product;
			cart.quantities[0] = quantity;

			Queue_Enqueue(queue, cart);
		} else if (command == "DELIVERY") {
						Cart cart = Queue_Front(queue);
			cout << "Delivered order: " << cart.products[0].productID << " " << cart.products[0].productName << " " 
					<< cart.quantities[0] <<endl;
			
			Queue_Dequeue(queue);
		} else {
			cout << "Unrecognized command, please try again" << endl;
		}
	}

	return 0;
}
