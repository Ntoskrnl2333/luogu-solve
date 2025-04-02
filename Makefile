CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

.PHONY: clean all config

all: config

clean:
	rm luogu-solve *.o -f
	# Remove the build in /uar/local/bin? Run "sudo rm /usr/local/bin/luogu-solve"

luogu-solve: main.o init.o io.o util.o swap.o
	$(CXX) $^ -o $@ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) -c

config: luogu-solve
	sudo mv luogu-solve /usr/local/bin

