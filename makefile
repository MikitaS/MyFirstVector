testvector:testvector.cpp vector.hpp vectorlibtemp.hpp memory.hpp boolvector.hpp
	g++ testvector.cpp -c
	g++ testvector.o -o testvector
	rm testvector.o
