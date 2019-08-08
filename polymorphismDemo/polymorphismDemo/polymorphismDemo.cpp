// polymorphismDemo.cpp : This file contains the 'main' function. 
// This is a sample of using polymorphism with virtual classes in C++. 
//Polymorphism means that a call to a member function causes a different function to be executed depending on the type
// of object that invokes the function.
#include "pch.h"
#include <iostream>
#include<cmath>
using namespace std;

class Human {
protected: 
	double weight, height;

public:
	Human(double a = 0.0, int b = 0.0) {
		weight = a;
		height = b;
	}
	virtual double bmi() { //naming this function virtual protects later calls from early binding, when the function is already set before it can be used.
		cout << "Parent class BMI: " << endl;
		return 0;
	}
};
class Adult : public Human {
public:
	Adult(double a = 0, double b = 0):Human(a, b){ }

	double bmi() {
		cout << " Adult BMI: " << endl;
		return((703*weight)/pow(height, 2));
	}
};
class Child : public Human {
public:
	Child(double a = 0.0, double b = 0.0):Human(a, b){ }

	double bmi() {
		cout << "Child BMI: " << endl;
		return(weight / (pow(height, 2)) * 703);
	}
};
int main()
{
	Human *human; //create an object of the human class.
	Adult big(182.5, 75.4); //the object created by the parent class will be different b/c the invoking child class is different.
	Child small(120.2, 54.1);

	//store the address of the Adult with a reference.
	human = &big;

	//call the Adult BMIfunction
	human->bmi();

	//store the address of the Child.
	human = &small;

	//call the Child BMI function.
	human->bmi();

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


