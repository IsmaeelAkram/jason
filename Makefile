all: jason

jason: jason/*.cpp
	clang++ jason/*.cpp -std=c++11 -stdlib=libc++ -o jas0n

clean:
	rm -rf jason/*.gch *.dSYM jas0n
