j: jason/*.h jason/*.cpp jason/*.hpp
	g++ -o jason -I . -I ./jason jason/*.cpp jason/*.h jason/*.hpp -std=c++11 -stdlib=libc++