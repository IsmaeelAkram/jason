#include "CppEssentials.h"

double CppEssentials::PI = M_PI;

double CppEssentials::getPi() {
	return CppEssentials::PI;
}

// CIRCLE MATH

double CppEssentials::getCircleCircumference(double radius) {
	// C = 2πr
	return 2 * (radius * CppEssentials::PI);
}

double CppEssentials::getCircleArea(double radius) {
	// A = πr^2
	return (CppEssentials::PI * pow(radius, 2));
}

double CppEssentials::getRadiusFromArea(double area) {
	// r = sqrt(A/π)
	return sqrt(area / CppEssentials::PI);
}

double CppEssentials::getRadiusFromCircumference(double circumference) {
	// r = C/(π*2)
	return circumference / (CppEssentials::PI * 2);
}

// OUTPUT HELPERS

void CppEssentials::print(string x) {
	cout << x;
}
void CppEssentials::print(double x) {
	cout << x;
}
void CppEssentials::print(int x) {
	cout << x;
}

void CppEssentials::println(string x) {
	cout << x << endl;
}
void CppEssentials::println(double x) {
	cout << x << endl;
}
void CppEssentials::println(int x) {
	cout << x << endl;
}

// TYPE CONVERTERS
string CppEssentials::toString(int x) {
	stringstream ss;
	ss << x;
	string x_ = ss.str();
	return x_;
}
string CppEssentials::toString(double x) {
	stringstream ss;
	ss << x;
	string x_ = ss.str();
	return x_;
}
char* CppEssentials::toChar(string x) {
	return 0;
}