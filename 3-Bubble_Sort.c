//Bubble_Sort
//����ؼ� ���ؼ� ���� ���� ������ �����ִ� ���
//���� ���� �ݺ����� ����Ǵ� Ƚ���� N + N-1 + N-2 ... 1
//O(N*N)
//�ð����⵵�� Selection_Sort�� Insertion_Sort�� ���� O(N*N)������ 
//���� ��ȿ������ ���� ����̴� �� ������ ����ؼ� swap�� ����� �ϱ� ����
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