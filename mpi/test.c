/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Created:  30.10.2013 08:23:00
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
	int tid, nthreads;
	char *cpu_name;
	double time;

	MPI_Init(&argc, &argv);

	time = MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &tid);
	MPI_Comm_size(MPI_COMM_WORLD, &nthreads);
	cpu_name = (char*)calloc(80, sizeof(char));
	gethostname(cpu_name, 80);

	// usleep(500000 * tid);
	printf("[%.3f]: tid=%i machine=%s NCPU=%i\n", MPI_Wtime() - time, tid, cpu_name, nthreads);

	MPI_Finalize();
	return(0);
}
