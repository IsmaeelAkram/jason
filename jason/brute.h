#include <iostream>
#include <string>
#include <algorithm>
#include "rang.hpp"
#include "md5.h"

using namespace std;
using namespace rang;

class Brute
{
public:
	static string bruteattack(string hash, bool visualization, string hashType, string alphabet);
};
