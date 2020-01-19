#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>
using namespace std;

class CppEssentials
{
private:
	static double PI;
public:
	static double getPi();

	static double getCircleCircumference(double radius);
	static double getCircleArea(double radius);
	static double getRadiusFromCircumference(double circumference);
	static double getRadiusFromArea(double area);

	static void print(string x);
	static void print(double x);
	static void print(int x);
	static void println(string x);
	static void println(double x);
	static void println(int x);

	static string toString(int x);
	static string toString(double x);
	static char* toChar(string x);
};
