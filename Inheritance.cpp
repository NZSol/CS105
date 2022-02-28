#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape {
protected:
	int sides;
	int length;
	int width;
	string name;

public:
	//example of abstraction
	//Using parameters to perform specific behaviours
	int calculateArea(int len, int wid) {
		int output = wid * len;
		return output;
	}

	//Virtual keyword allows method to be overwritten in subsequent classes
	//Example of encapsulation
	//Using Getters and Setters and assign and fetch unaccessible variables
	virtual void SetSides(int count) {
		sides = count;
		cout << "Number of sides in shape is " << sides;
	}
	virtual void SetSize(int wid, int len) {
		length = len;
		width = wid;
		cout << "\nShape Length = " << len << "\nShape Width = " << wid << "\n\n";
	}
	int GetSides() {
		return sides;
	}
	int GetWidth() {
		return width;
	}
	int GetLength() {
		return length;
	}

	//Declaration of Pure virtual method
	//Must be inherited within all instanced classes inheriting from Shape
	virtual void output() = 0;
};

//Triangle Class, inheriting properties of Shape class
class Triangle : public Shape {

	//Declaration of properties accessible outside of class
public:

	//Triangle constructor
	Triangle(int wid, int len) {
		width = wid;
		length = len;
	};

	void setName() {
		name = "Triangle";
	}
};

//Rectangle class, inheriting properties of Shape class
class Rectangle : public Shape {

//Declaration of properties available outsid of class
public:

	//Declaration of public methods/behaviours
	Rectangle(int wid, int len) {
		wid = width;
		len = length;
	};

	void SetSides(int count) {
		sides = count;
	}

	void output() {
		cout << "This is the Rectangle class of Quad";
	}
};


int main()
{
	Shape* base;
	Rectangle quad{3, 8};
	base = &quad;


	//Using setter method to assign a non-accessible variable
	quad.SetSides(4);
	

	//Using getter methods to output various values to console
	cout << "Quad length = " << quad.GetLength() << endl;
	cout << "Quad width = " << quad.GetWidth() << endl;
	cout << "Quad side count = " << quad.GetSides() << endl;



	//---------------------------------------------------------------------------------
	//Example of abstraction through header files
	//Using a function we cannot see the behaviour of to perform a mathmatical operation
	float value = powf(3, 2);
	cout << value << endl;
	//Outputs a value of 9 (3 to the power of 2 / 3*3*3)

}