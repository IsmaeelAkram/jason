j: jason/*.h jason/*.cpp jason/*.hpp
	rm -rf build
	mkdir build
	clang++ jason/*.cpp -std=c++11 -stdlib=libc++ -o jas0n

clean:
	rm -rf *.out jason/*.gch *.dSYM build
