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
        cout << fg::red << "No args specified!" << fg::reset << endl;
        cout << fg::yellow << "Example: jason -s=<hash>" << fg::reset << endl;
        return 0;
    }

    argh::parser cmdl(argv);

    bool verbose = false;
    verbose = cmdl[{ "-v", "--verbose" }] ? "ON" : "OFF";

    string hash;
    if (cmdl({ "-s", "--string", "--hash" }) >> hash);
    else { cout << fg::red << "Please specify a hash with -s!" << fg::reset << endl; return 0; }

    string hashType;
    cmdl({ "-t", "--type" }) >> hashType;

    string defaultAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string alphabet = "";
    if (cmdl({ "-a", "--alphabet" }) >> alphabet);
    else {
        cout << fg::yellow << "No alphabet specified. Using default alphabet" << fg::reset << endl;
        alphabet = defaultAlphabet;
    }

    cout << fg::green << "Commencing attack..." << fg::reset << endl << endl;

    auto start = chrono::system_clock::now();
    
    string hashKey = Brute::bruteattack(hash, verbose, hashType, alphabet);

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    if (!(hashKey == "")) {
        hashFinished(hashKey, elapsed_seconds, alphabet);
    }
    else if (alphabet != defaultAlphabet){
        cout << fg::red << "Cracking failed, try using the default alphabet." << fg::reset << endl;
    }
    else {
        cout << fg::red << "Cracking failed." << fg::reset << endl;
    }
}

void hashFinished(string hashKey, chrono::duration<double> elapsed_time, string alphabet) {
    cout << endl;
    cout << "Key found! [" << bg::green << hashKey << bg::reset << "]" << endl;

    int attempts = pow(alphabet.length(), hashKey.length());
    cout << "Attempts: " << fg::green << attempts << fg::reset << endl;
    cout << "Elapsed time: " << fg::green << elapsed_time.count() << " seconds" << fg::reset << endl;
}
