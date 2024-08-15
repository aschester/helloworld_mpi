##
# To build:
#     MPIROOT=/path/to/mpi/install make
# To run:
#     OMPI_MCA_btl=^openib PATH=/path/to/mpi/install/bin/:$PATH    \
#     LD_LIBRARY_PATH=/path/to/mpi/install/lib/:$LD_LIBRARY_PATH   \
#     mpirun -np 4 helloworld_mpi
# OMPI_MCA_btl=^openib may or may not be needed depending on the host system.
#

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
