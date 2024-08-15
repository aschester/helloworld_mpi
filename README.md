# MPI Hello World!

This is a simple Hello World! program written for MPI. It can be used to e.g., test running MPI processes inside a container at HPC facilities like NERSC.

## To build:

`MPIROOT=/path/to/mpi/install make`

where `MPIROOT` points to the MPI installation path e.g., `MPIROOT=/usr/opt/mpi/openmpi-4.1.4` in the FRIB bullseye container.

## To run:

`OMPI_MCA_btl=^openib PATH=/path/to/mpi/install/bin/:$PATH  LD_LIBRARY_PATH=/path/to/mpi/install/lib/:$LD_LIBRARY_PATH  mpirun -np 4 helloworld_mpi`

OMPI_MCA_btl=^openib may or may not be needed depending on the host system.