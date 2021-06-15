j: jason/*.h jason/*.cpp jason/*.hpp
	clang++ jason/*.cpp jason/*.h jason/*.hpp -std=c++11 -stdlib=libc++
	mv a.out cracker

clean:
	rm -rf *.out jason/*.gch *.dSYM