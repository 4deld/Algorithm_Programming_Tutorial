//Selection_Sort
//Min을 구하고 계속해서 앞에 있는 것과 교환하여 정렬할 수 있다
//제일 안쪽 반복문이 수행되는 횟수는 N + N-1 + N-2 ... 1
//O(N*N)
#include<stdio.h>

int main() {

	int L[11] = { 1,4,5,6,2,3,9,8,7,10 };
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		int min = 999; //정렬할 수들보다 커야함
		for (int j = i; j < 10; j++) {
			if (L[j] < min) {
				min = L[j];
				idx = j;
			}
		}

		int tmp = L[i];
		L[i] = min;
		L[idx] = tmp;
	}
	for (int j = 0; j < 10; j++) {
		printf("%d ", L[j]);
	}
}