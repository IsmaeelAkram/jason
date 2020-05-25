#include "brute.h"

string performHash(string key, string hashtype) {
	if (hashtype == "md5") {
		return md5(key);
	}
	if (hashtype == "ntlm") {
		char* key_ = &key[0];
		return "";
	}
	return "";
}

string detectHash(string hash) {
	if (hash.length() == 32 && !all_of(hash.begin(), hash.end(), [](unsigned char c) { return isupper(c); })) return "md5";
	else if (hash.length() == 32 && all_of(hash.begin(), hash.end(), [](unsigned char c) { return isupper(c); })) return "ntlm";
	else if (hash.length() == 40) return "sha1";
	else if (hash.length() == 64) return "sha256";
	else if (hash.length() == 96) return "sha384";
	else if (hash.length() == 128) return "sha512";
	else return "";
}

string Brute::bruteattack(string hash, bool visualization, string hashType) {
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string hashKey;
	/*string hashType = detectHash(hash);*/
	cout << "Hash type detected: " << hashType << endl;

	if (visualization == true) {
		cout << "a";
	}

	for (char c : alphabet) {
		string hashOfChar = performHash(string(1, c), hashType);
		if(visualization == true) cout << "\r" << c;
		if (hashOfChar == hash) {
			return string(1, c);
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			if(visualization == true) cout << "\r" << c << c2;
			string hashOfChar = performHash(string(1, c) + string(1, c2), hashType);
			if (hashOfChar == hash) {
				return string(1, c) + string(1, c2);
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				if(visualization == true) cout << "\r" << c << c2 << c3;
				string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3), hashType);
				if (hashOfChar == hash) {
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
					string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4), hashType);
					if (hashOfChar == hash) {
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
						string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5), hashType);
						if (hashOfChar == hash) {
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
							string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6), hashType);
							if (hashOfChar == hash) {
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
								string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6) + string(1, c7), hashType);
								if (hashOfChar == hash) {
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