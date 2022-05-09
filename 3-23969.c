#include<stdio.h>
int n, k;
int main() {
	int A[100000];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (A[j] > A[j + 1]) {
				int tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
				k--;
			}
			if (k == 0) {
				for (int i = 0; i < n; i++) {
					printf("%d ", A[i]);
				}
				return 0;
			}
		}
	}
	printf("-1");

}