# compiler name
CXX = clang++-12
# c++ compiler flags
# -g : adds debugging information to the executable file
# -Wall : turns on most, but not  all, compiler warnings
# -std=C++17 : uses c++17 standarda
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file
PROGRAM = demo

# file to compile:
CPPFILES = main.cpp

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o
	