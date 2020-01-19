#include "brute.h"
#include "md5.h"

string performHash(string key, string hashtype) {
	if (hashtype == "md5") {
		return md5(key);
	}
	return "";
}

string Brute::bruteattack(string hash) {
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string hashKey;



	for (char c : alphabet) {
		string hashOfChar = performHash(string(1, c), "md5");
		if (hashOfChar == hash) {
			return string(1, c);
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			string hashOfChar = performHash(string(1, c) + string(1, c2), "md5");
			if (hashOfChar == hash) {
				return string(1, c) + string(1, c2);
			}
		}
	}
	for (char c : alphabet) {
		for (char c2 : alphabet) {
			for (char c3 : alphabet) {
				string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3), "md5");
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
					string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4), "md5");
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
						string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5), "md5");
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
							string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6), "md5");
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
								string hashOfChar = performHash(string(1, c) + string(1, c2) + string(1, c3) + string(1, c4) + string(1, c5) + string(1, c6) + string(1, c7), "md5");
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