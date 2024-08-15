# Compiler:

CXX = $(MPIROOT)/bin/mpicxx

# Default flags:

CXXFLAGS = -Wall -O2 -g -I$(MPIROOT)/inc

# Compile the program

EXEC = helloworld_mpi
OBJS = helloworld_mpi.o

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXEC) $(OBJS)
