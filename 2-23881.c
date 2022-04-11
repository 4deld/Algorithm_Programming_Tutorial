//선택 정렬하는 과정에서 K번째 교환이 이루어질 때의 두 수를 출력하는 문제
//선택 정렬을 Min을 구해서 할 수도 있고 Max를 구해서 할 수도 있다
#include<stdio.h>
int L[100000];
int N, K;
int cnt;
int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &L[i]);
	int idx = 0;
	for (int i = N - 1; i >= 0; i--) {
		int max = -1;
		for (int j = i; j >= 0; j--) {
			if (L[j] > max) {
				max = L[j];
				idx = j;
			}
		}
		if (L[i] != max) {
			cnt++;

			if (cnt == K) {
				printf("%d %d\n", L[i], max);
				break;
			}
			int tmp = L[i];
			L[i] = max;
			L[idx] = tmp;
		}
	}

	if (cnt < K)
		printf("-1\n");
	return 0;
}