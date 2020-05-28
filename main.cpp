#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>
#include "rang.hpp"
#include "argh.h"
#include "brute.h"

using namespace std;
using namespace rang;

void hashFinished(string hashKey, chrono::duration<double> elapsed_time, string alphabet);

int main(int argc, char *argv[], char *envp[])
{
	if (argc <= 1) {
		cout << "No args specified!" << endl;
		cout << "Example: jason -s=<hash>" << endl;
		return 0;
	}

	argh::parser cmdl(argv);

	bool visualization;
	if (cmdl({ "-v", "--visualization", "--verbose" }) >> visualization);

	string hash;
	if (cmdl({ "-s", "--string", "--hash" }) >> hash);
	else { cout << fg::red << "Please specify a hash with -s!" << fg::reset << endl; return 0; }

	string hashType;
	if (cmdl({ "-t", "--type" }) >> hashType);

	string alphabet;
	if (cmdl({ "-a", "--alphabet" }) >> alphabet);
	else {
		cout << fg::yellow << "No alphabet specified. Using default alphabet (abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789)" << fg::reset << endl;
		alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	}

	cout << fg::green << "Commencing attack..." << fg::reset << endl << endl;

	auto start = chrono::system_clock::now();
	
	string hashKey = Brute::bruteattack(hash, visualization, hashType, alphabet);

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;

	if (!(hashKey == "")) {
		hashFinished(hashKey, elapsed_seconds, alphabet);
	}
	else {
		cout << fg::red << "Cracking failed. Try using the default alphabet." << fg::reset << endl;
	}
}

void hashFinished(string hashKey, chrono::duration<double> elapsed_time, string alphabet) {
	cout << "Key found! [" << bg::green << hashKey << bg::reset << "]" << endl;

	int attempts = pow(alphabet.length(), hashKey.length());
	cout << "Attempts: " << fg::green << attempts << fg::reset << endl;
	cout << "Elapsed time: " << fg::green << elapsed_time.count() << " seconds" << fg::reset << endl;
}
