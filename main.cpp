#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ctime>
#include "rang.hpp"
#include "argh.h"
#include "brute.h"
#include "help.h"

using namespace std;
using namespace rang;

void hashFinished(string hashKey, chrono::duration<double> elapsed_time);

int main(int argc, char *argv[], char *envp[])
{
	if (argc <= 1) {
		Help::argHelp();
		return 0;
	}

	argh::parser cmdl(argv);

	bool visualization = false;
	if (cmdl({ "-v", "--visualization", "--verbose" }) >> visualization);

	string hash;
	if (cmdl({ "-s", "--string", "--hash" }) >> hash);
	else { cout << fg::red << "Please specify a hash with -s!" << fg::reset << endl; return 0; }

	string hashType;
	if (cmdl({ "-t", "--type" }) >> hashType);
	else { cout << fg::red << "Please specify a type with -t!" << fg::reset << endl; return 0; }

	cout << endl << fg::green << "Commencing attack..." << fg::reset << endl << endl;

	auto start = chrono::system_clock::now();
	
	string hashKey = Brute::bruteattack(hash, visualization, hashType);

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;

	hashFinished(hashKey, elapsed_seconds);
}

void hashFinished(string hashKey, chrono::duration<double> elapsed_time) {
	cout << "Key found! [" << bg::green << hashKey << bg::reset << "]" << endl;

	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int attempts = hashKey.length() * alphabet.length();
	cout << "Attempts: " << fg::green << attempts << fg::reset << endl;
	cout << "Elapsed time: " << fg::green << elapsed_time.count() << " seconds" << fg::reset << endl;

	Beep(1500, 500);
	Beep(1500, 500);
	Beep(1500, 500);
}
