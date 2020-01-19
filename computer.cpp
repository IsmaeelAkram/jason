#include "computer.h"
#define DIV 1024
#include <Windows.h>
#include <sstream>

SYSTEM_INFO sysInfo;

string Computer::getCPU() {
	GetSystemInfo(&sysInfo);
	ostringstream stream;
	stream << sysInfo.dwNumberOfProcessors/2;
	return stream.str();
}

int Computer::getRAM() {
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	int TOTAL_RAM = statex.ullTotalPhys / DIV;
	return TOTAL_RAM;
}

string Computer::getGPU() {
	return "null";
}

string Computer::getOS() {
	return "null";
}