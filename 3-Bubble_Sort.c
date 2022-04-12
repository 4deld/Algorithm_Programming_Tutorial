//Bubble_Sort
//계속해서 비교해서 작은 값을 앞으로 보내주는 방식
//제일 안쪽 반복문이 수행되는 횟수는 N + N-1 + N-2 ... 1
//O(N*N)
//시간복잡도는 Selection_Sort와 Insertion_Sort와 같이 O(N*N)이지만 
//가장 비효율적인 정렬 방식이다 그 이유는 계속해서 swap을 해줘야 하기 때문
#include<stdio.h>

int main() {

	int L[11] = { 1,4,5,6,2,3,9,8,7,10 };
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9-i; j++) {
			if (L[j] > L[j + 1]) {
				int tmp = L[j];
				L[j] = L[j + 1];
				L[j + 1] = tmp;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		printf("%d ", L[j]);
	}
}