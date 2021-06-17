all: jas0n

jas0n: jason/*.cpp
	clang++ jason/*.cpp -std=c++11 -o jas0n

test: ./jas0n
	./jas0n -s=425a226eb69a5e2480230f9b53a09a98 -v

clean:
	rm -rf jason/*.gch *.dSYM jas0n
