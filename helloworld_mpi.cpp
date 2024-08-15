/**
 * @file  hello_world_mpi.cpp
 * @brief The first steps to building an MPI program: a "Hello World!" program 
 * utilizing MPI. A C++ version of 
 * https://mpitutorial.com/tutorials/mpi-hello-world.
 */

#include <iostream>

#include <mpi.h>

int main (int argc, char* argv[])
{
  // Establish environment necessary for MPI to run. Pass command line args
  // (MPI runtime flags):
  
  MPI_Init(&argc, &argv);

  // Get number of process from the "world communicator," MPI_COMM_WORLD, which
  // includes all processes specified at runtime by -np:
  
  int size;
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  // Get the process rank. The rank is a unique identifier for each process:
  
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Get the processor name:
  
  char name[MPI_MAX_PROCESSOR_NAME];
  int len;
  MPI_Get_processor_name(name, &len);

  // Print the message for each rank:

  std::cout << "Hello World! from processor " << name << " rank " << rank
	    << " of " << size << std::endl;
  
  MPI_Finalize();
    
  return 0;
}
