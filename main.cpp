#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include "brute.h"
#include "help.h"
#include "computer.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void hashFinished(string hashKey, chrono::duration<double> elapsed_time);
void getSpecs();

int main(int argc, char *argv[], char *envp[])
{
	if (argc <= 1) {
		Help::argHelp();
	}
	else {
		string hash = argv[1];
		bool visualization = argv[2];

		getSpecs();
		cout << endl << "Commencing attack..." << endl << endl;

		auto start = chrono::system_clock::now();
		string hashKey = Brute::bruteattack(hash, visualization);
		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end - start;

		if (visualization == true) {
			cout << "\r";
		}
		hashFinished(hashKey, elapsed_seconds);
	}
}

void hashFinished(string hashKey, chrono::duration<double> elapsed_time) {
	cout << "Key found! [";
	SetConsoleTextAttribute(hConsole, 10);
	cout << hashKey;
	SetConsoleTextAttribute(hConsole, 7); 
	cout << "]" << endl;

	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int attempts = hashKey.length() * alphabet.length();
	cout << "Attempts: " << attempts << endl;
	cout << "Elapsed time: " << elapsed_time.count() << " seconds" << endl;

	/*Beep(1500, 500);
	Beep(1500, 500);
	Beep(1500, 500);*/
}

void getSpecs() {
	cout << "CPU: " << Computer::getCPU() << " cores" << endl;
	cout << "RAM: " << Computer::getRAM() << " KB" << endl;
}
