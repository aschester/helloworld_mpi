/**
 * @file  hello_world_mpi.cpp
 * @brief A version of https://mpitutorial.com/tutorials/mpi-hello-world.
 */

#include <iostream>

#include <mpi.h>

int main (int argc, char* argv[])
{  
  int size, rank, len;
  char name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(name, &len);

  // Print our message for each processor:
  
  std::cout << "Hello World! from processor " << name << " rank " << rank
	    << " of " << size << std::endl;
  
  MPI_Finalize();
    
  return 0;
}
