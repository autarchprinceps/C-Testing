/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  boehm garbage collector test
 *
 *        Created:  10.10.2013 08:18:23
 *
 *         Author:  autarch princeps (), autarch@outlook.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <gc.h>
#include <omp.h>

int main() {
	int i;

	GC_init();
		#pragma omp parallel
		for(i = 0; i < 10000000; ++i) {
			const unsigned int id = omp_get_thread_num();
			if(i % 2 == id % 2) {
				int** p = (int **)GC_malloc(sizeof(int *));
				int* q = (int *)GC_malloc_atomic(sizeof(int));
				// assert(*p == 0);
				*p = (int *)GC_malloc(sizeof(int) * (i / 100 + 1)); // (int *)GC_realloc(q, 2 * sizeof(int));
				if(i % 1000 == 0)
					printf("Heap size = %d\n", GC_get_heap_size());
			} else {
				int** p2 = (int **)malloc(sizeof(int *));
				int* q2 = (int *)malloc(sizeof(int));
				// assert(*p2 == 0);
				*p2 = (int *)malloc(sizeof(int) * (i / 100 + 1));
				if(i % 1000 == 0)
					printf("Malloc size = %d\n", GC_get_heap_size());
			}
		}
	return 0;
}
