#include "brute.h"

string performHash(string key, string hashtype) {
	if (hashtype == "md5") {
		return md5(key);
	}
	return "";
}

string detectHash(string hash) {
	if (hash.length() == 32) return "md5";
	else if (hash.length() == 40) return "sha1";
	else if (hash.length() == 64) return "sha256";
	else if (hash.length() == 96) return "sha384";
	else if (hash.length() == 128) return "sha512";
    // TODO: Setup NTLM detection
	else return "";
}

string Brute::bruteattack(string hash, bool visualization, string hashType, string alphabet) {
	string hashKey;
	if (hashType == "") {
		hashType = detectHash(hash);
	}
	if(hashType == ""){
        cout << fg::red << "Hashing algorithm could not be detected. If it is not detected, that most likely means it is not supported but you can always add your own support brute.cpp:performHash()" << fg::reset << endl;
        return "";
	}
	cout << "Hash type detected: " << hashType << endl;

	if (visualization == true) {
		cout << "a";
	}

	for (char c : alphabet) {
		if(visualization == true) cout << "\r" << c;
		if (performHash(string(1, c), hashType) == hash) {
			return string(1, c);
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			if(visualization == true) cout << "\r" << c << c2;
			if (performHash(string(1, c) + string(1, c2), hashType) == hash) {
				return string(1, c) + string(1, c2);
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				if(visualization == true) cout << "\r" << c << c2 << c3;
				if (performHash(string(1, c) + string(1, c2) + string(1, c3), hashType) == hash) {
					return string(1, c) + string(1, c2) + string(1, c3);
				}
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				for (char c4 : alphabet) {
					if(visualization == true) cout << "\r" << c << c2 << c3 << c4;
					if (performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4), hashType) == hash) {
						return string(1, c) + string(1, c2) + string(1, c3) + string(1, c4);
					}
				}
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				for (char c4 : alphabet) {
					for (char c5 : alphabet) {
						if(visualization == true) cout << "\r" << c << c2 << c3 << c4 << c5;
						if (performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5), hashType) == hash) {
							return string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5);
						}
					}
				}
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				for (char c4 : alphabet) {
					for (char c5 : alphabet) {
						for (char c6 : alphabet) {
							if(visualization == true) cout << "\r" << c << c2 << c3 << c4 << c5 << c6;
							if (performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6), hashType) == hash) {
								return string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6);
							}
						}
					}
				}
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				for (char c4 : alphabet) {
					for (char c5 : alphabet) {
						for (char c6 : alphabet) {
							for (char c7 : alphabet) {
								if(visualization == true) cout << "\r" << c << c2 << c3 << c4 << c5 << c6 << c7;
								if (performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6) + string(1, c7), hashType) == hash) {
									return string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6) + string(1, c7);
								}
							}
						}
					}
				}
			}
		}
	}
	return hashKey;
}
