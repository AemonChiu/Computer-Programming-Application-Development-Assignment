#include "Header.h"
using namespace std;
#include <iostream>

VecThreeD::VecThreeD() {
	o = 0, p = 0, q = 0, r = 0, s = 0, t = 0;
}

double VecThreeD::exp(double base, long power) {
	double result = 1;
	for (int i = 0; i < power; i++)
	{
		result = result * base; // If power is 0, then return 1.
	}
	return result;
}

double VecThreeD::arctan(double a, double b, int term) {
	double result = 0;
	if (b / a < -1 || b / a>1)     //if z is not in the range of [-1,1], the program will end after displaying an error message
	{
		cout << "Your input is not in the required range!" << endl;
		return 0;
	}
	else {
		for (double i = 0; i < term; i++) {
			result = result + exp(-1, i) * exp(b / a, 2 * i + 1) / (2 * i + 1);
		}
		return result;
	}
}


void VecThreeD::setVec1(float a) {
	o = a;
}

void VecThreeD::setVec2(float b) {
	p = b;
}
void VecThreeD::setVec3(float c) {
	q = c;
}
void VecThreeD::setVec4(float d) {
	r = d;
}
void VecThreeD::setVec5(float e) {
	s = e;
}
void VecThreeD::setVec6(float f) {
	t = f;
}

void VecThreeD::displayVec()
{
	cout << "Vector 1 is: " << getVec1() << "i + " << getVec2() << "j + " << getVec3() << "k.\n";
	cout << "Vector 2 is: " << getVec4() << "i + " << getVec5() << "j + " << getVec6() << "k.\n";
}

float VecThreeD::getVec1()
{
	return o;
}

float VecThreeD::getVec2()
{
	return p;
}

float VecThreeD::getVec3()
{
	return q;
}
float VecThreeD::getVec4()
{
	return r;
}
float VecThreeD::getVec5()
{
	return s;
}
float VecThreeD::getVec6()
{
	return t;
}

void VecThreeD::calVec()
{
	float DotProduct = 0;
	DotProduct = getVec1() * getVec4() + getVec2() * getVec5() + getVec3() * getVec6();
	cout << "The dot product of the two vectors is: " << DotProduct << "." << endl;
}
