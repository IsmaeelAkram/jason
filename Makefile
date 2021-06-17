all: jas0n

jas0n: jason/*.cpp
	clang++ jason/*.cpp -std=c++11 -o jas0n

clean:
	rm -rf jason/*.gch *.dSYM jas0n
