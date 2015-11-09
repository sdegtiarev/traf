

CXX= g++
CC= g++
CXXFLAGS= -std=c++11 
LDFLAGS= 
LDLIBS=  



traf: traf.cc runge_kutta.h arithn.h
	g++ $(CXXFLAGS) traf.cc -o$@



clean:
	rm -rf traf *.o core*
