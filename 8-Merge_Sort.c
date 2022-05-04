//Merge_Sort
//�迭�� �� �κ����� ������ �����ؼ� ���� �����̶�� �θ���
// ������ �ߴٰ� ��ĥ �� ������ ���ҵ� �迭���� �� ������ �Ǿ��ִ� �����̱�  ������
// N���� �˻��ϸ� ������ �迭�� ���ĵ� ���·� ���� �� �ִ� -> ������!
// (���Ҹ� �� �������� �����ٴ� ��)
// 
// �� �κ����� ������ ����ϰ� ��ġ�� ���� Ƚ���� �ſ� ��������
//�ð����⵵ O(N*logN)�� �����Ѵ� (���� ���� 2�� �α׸� ���α׷� ����)
// logN�� ���� ����� ���� �� ������ ���� ���̴�
//�� ���İ� �ٸ��� �׻� ������ ������ ������ Pivot���� ����
//���Ŀ� ���Ǵ� �迭�� ���� ������ �����ؾ� �Ѵ�
//���� ������ �������� ������ �Ź� �迭�� �����ؾ� �ϱ� ����
//������ �����͸� ���� �迭�� �ʿ��ؼ� �޸� Ȱ���� ��ȿ����



//��ü���� �������
//7 6 5 8 -> 7 6 -> 7 -> 6->merge(6, 7) -> 5 8 -> 5 -> 8->merge(5, 8)->merge(5, 6, 7, 8)
//                                                                                                                                        ->merge(1, 3, 5, 5, 6, 7, 8, 9) -> 1 3 5 5 6 7  8 9
//3 5 9 1 -> 3 5 -> 3 -> 5->merge(3, 5) -> 9 1 -> 9 -> 1->merge(1, 9)->merge(1, 3, 5, 9)
#include<stdio.h>
int sorted[10000]; //���ĵ� �迭�� ������ �������� �迭
int N;


void Merge(int *L,int left, int middle, int right) {

	int i = left; //���� ���� �迭�� ù��° �ε���
	int j = middle + 1; //������ ������ ù��° �ε���
	int k = left; //�������� �迭�� ù��° �ε���

	//fix�� ����
	int h = left; 
	int f = middle;
	int u = right;

	while (i <= f && j <= u) {  //���� �迭 Ȥ�� ������ �迭 �� �ϳ��� ���Ұ� �� �� ������
		if (L[i] > L[j]) {
			sorted[k] = L[j++];
		}
		else {
			sorted[k] = L[i++];
		}
		k++;
	}

	
	int q;
	if (i <= f)
		q = i;
	else
		q = j;

	//������ ���� ���ҵ� �ֱ�
	while (k != u+1) {
		sorted[k++] = L[q++];
	}

	//�����ϱ�
	for (int z = left; z<= right; z++) {
		L[z] = sorted[z];
	}
}

void Merge_Sort(int L[], int left, int right) {
	/*if (left < right) {
		int middle = (left + right) / 2;

		Merge_Sort(L, left, middle);
		Merge_Sort(L, middle + 1, right);
		Merge(L, left, middle, right);
	}*/

	if (left >= right)
		return;

	//�߰�
	int middle = (left + right) / 2;

	//����Լ��� ����
	Merge_Sort(L, left, middle);
	Merge_Sort(L, middle + 1, right);

	//����
	Merge(L, left, middle, right);
}

int main() {
	scanf("%d", &N);
	int L[10000];
	for (int i = 0; i < N; i++) {
		scanf("%d", &L[i]);
	}

	Merge_Sort(L, 0, N-1);

	for (int j = 0; j < N; j++) {
		printf("%d ", L[j]);
	}
}