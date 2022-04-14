//Quick_Sort
//�迭�� �� �κ����� ������ �����ؼ� ���� �����̶�� �θ���
// (���Ҹ� �� �������� �����ٴ� ��)
// Quick_Sort������ ���� ���� �ִ� �̸� �ǹ��̶�� �Ѵ�
// �ǹ� ���� �������� ���ʰ� ���������� ������
// 
// �� �κ����� ������ ����ϰ� ��ġ�� ���� Ƚ���� �ſ� ��������
//������� �ð����⵵ O(N*logN) (���� ���� 2�� �α׸� ���α׷� ����)
// logN�� ���� ����� ���� �� ������ ���� ���̴�
//�ǹ� ���� �־����� ����� �� �ð� ���⵵�� O(N*N)�̴� 
//(���ĵ� ���¿��� Qucik_Sort�� ���� ��쵵)
#include<stdio.h>

void Quick_Sort(int L[],int start, int end) {
	if (start >= end) //���Ұ� 1���� ���
		return;

	int pivot = start; //pivot���� �߰� ������ �����Ϸ��� �ڵ带 ��� ���ľ� �ұ�??
	int i = pivot + 1; //pivot ���� ���Һ��� �˻�
	int j = end;

	while (1) {
		while (L[i] < L[pivot] && i < end)  //while (L[i] > L[pivot] && i < end) ��������
			i++;
		while(L[j] > L[pivot] && j > start) //while(L[j] < L[pivot] && j > start) ��������
			j--;
		if (i >= j) { //������
			int tmp = L[pivot];
			L[pivot] = L[j];
			L[j] = tmp;
			break;
		}

		//�������� ����
		int tmp = L[i];
		L[i] = L[j];
		L[j] = tmp;
	}
	Quick_Sort(L, start, j - 1);
	Quick_Sort(L, j + 1, end);
}
int main() {

	int L[11] = { 1,4,5,6,2,3,9,8,7,10 };

	Quick_Sort(L, 0, 9);

	for (int j = 0; j < 10; j++) {
		printf("%d ", L[j]);
	}
}