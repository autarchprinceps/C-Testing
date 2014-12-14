int* map(int* arr, int n, int(*mapper)(int)) {
	int* result = malloc(sizeof(int)*n);
	#pragma omp parallel for
	for(int i = 0; i < n; i++) {
		result[i] = mapper(arr[i]);
	}
}

int reduce(int* arr, int n, int(*reducer)(int, int)) {
	int tmp = reducer(arr[0], arr[1]);
	for(int i = 2; i < n; i++) {
		tmp = reducer(tmp, arr[i]);
	}
	return tmp;
}