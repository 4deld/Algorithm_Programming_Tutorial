//���� �����ϴ� �������� K��° ��ȯ�� �̷���� ���� �� ���� ����ϴ� ����
//���� ������ Min�� ���ؼ� �� ���� �ְ� Max�� ���ؼ� �� ���� �ִ�
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