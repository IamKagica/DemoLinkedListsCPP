// Author: Phillip Sin
// Date: 11/11/15
// Class: CP2 C++ (A2)
// DemoLinkedListsCPP.cpp

#include "stdafx.h"
#include <iostream>
#include <string>

struct trainCar {
	std::string name;
	trainCar *next;
};

void insertCar(int position_in_train, trainCar *start,std::string name) {
	// Let's assume we have 10 cars
	trainCar *newCar = new trainCar;
	newCar->name = name;
	// we need a pointer to car1 and car2
	trainCar *position = start;
	int car_number = 0;

	while (car_number < position_in_train) {
		position = position->next;
		car_number++;
	}
	// now we can do the switching
	newCar->next = position->next;
	//
	position->next = newCar;
}

void deleteCar(int position_in_train,trainCar *start) {
	trainCar *position = start;
	trainCar *secondPosition = start;
	trainCar *deletedCar;
	int car_number = 0;
	int car_number2 = 0;

	//Must Subtract 1 to point to the position we
	//don't want because position points
	//to the car thereafter. 1->2->3->4 
	//We start at Car Number 1 (Engine)
	
	while (car_number < position_in_train - 2)
	{
		position = position->next;
		car_number++;
	}

	while (car_number2 < position_in_train - 1)
	{
		secondPosition = secondPosition->next;
		car_number2++;
	}

	deletedCar = position->next;
	position->next = secondPosition->next;
	delete deletedCar;
	//deletedCar = position;
	//position = secondPosition;
	//delete deletedCar;

}

int countCars(trainCar *start) {
	int number = 0;
	trainCar *position = start;
	if (position != 0)
	{
		number = 1;
		while (position->next != 0)
		{
			position = position->next;
			number++;
		}
	}
	return number;
}

void printCars(trainCar *start) {
	trainCar *position = start;
	if (position != 0) { //Makes sure there is a place to start
		while (position->next != 0) {
			std::cout << position->name << std::endl;
			position = position->next;
		}
		std::cout << position->name << std::endl;
	}
}

int main()
{
	trainCar *root;      // This will be the unchanging first node
	trainCar *position; // Will point to each node 
	root = new trainCar; // Now root points to a node struct
	root->next = 0;  // The node root points to has its next pointer
					 //  set equal to a null pointer
	root->name = "engine";     // By using the -> operator, you can modify the node
					 //  a pointer (root in this case) points to.
	position = root;
	if (position->next != 0) {
		while (position->next != 0)
		{
			position = position->next;
		}
	}
	// We're at the end
	// we'll add a new car at the end
	//std::cout << "How many cars (including the caboose) should we add? " << std::endl;
	int cars_to_add=10;
	//std::cin >> cars_to_add;

	for (int x = 1; x <= cars_to_add; x++) {
		position->next = new trainCar;
		position = position->next;
		position->next = 0;
		
		if (x < cars_to_add) {
			position->name = "This is the car #" + std::to_string(x);
		}
		else {
			position->name = "Caboose";
		}
	}
	std::cout << countCars(root) << std::endl;

	

	// Let's insert a new car
	insertCar(5, root, "Dining Car");
	insertCar(2, root, "luggage car");
	insertCar(12, root, "New Caboose 1");
	insertCar(13, root, "New Caboose 2");
	deleteCar(2, root);
	deleteCar(9, root);


	position = root;
	printCars(root);
	std::cout << countCars(root) << std::endl;
	
	

	system("Pause");
}