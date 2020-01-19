#include <iostream>
#include <Windows.h>
#include "brute.h"
#include "help.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void hashFinished(string hashKey);

int main(int argc, char *argv[], char *envp[])
{
	if (argc <= 1) {
		Help::argHelp();
	}
	else {
		string hash = argv[1];

		// STARTING CODE GOES HERE

		string hashKey = Brute::bruteattack(hash);

		hashFinished(hashKey);
	}
}

void hashFinished(string hashKey) {
	cout << "Key found! [";
	SetConsoleTextAttribute(hConsole, 10);
	cout << hashKey;
	SetConsoleTextAttribute(hConsole, 7); 
	cout << "]" << endl;

	Beep(1500, 350);
	Beep(1500, 350);
	Beep(1500, 350);
}
