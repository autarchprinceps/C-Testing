CC = mpicc
CFLAGS = -O0

test: test.c
	$(CC) $(CFLAGS) test.c -o test

clean:
	rm test

run: test
	mpirun -np 4 ./test
