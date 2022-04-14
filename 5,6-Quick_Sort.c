//Quick_Sort
//배열을 두 부분으로 나눠서 정렬해서 분할 정복이라고도 부른다
// (원소를 두 집합으로 나눈다는 말)
// Quick_Sort에서는 기준 값이 있다 이를 피벗이라고 한다
// 피벗 값을 기준으로 왼쪽과 오른쪽으로 나눈다
// 
// 두 부분으로 나눠서 계산하고 합치면 연산 횟수가 매우 적어진다
//평균적인 시간복잡도 O(N*logN) (보통 밑이 2인 로그를 상용로그로 쓴다)
// logN은 거의 상수로 봐도 될 정도로 작은 값이다
//피벗 값을 최악으로 잡았을 때 시간 복잡도는 O(N*N)이다 
//(정렬된 상태에서 Qucik_Sort를 쓰는 경우도)
#include<stdio.h>

void Quick_Sort(int L[],int start, int end) {
	if (start >= end) //원소가 1개인 경우
		return;

	int pivot = start; //pivot값을 중간 값으로 설정하려면 코드를 어떻게 고쳐야 할까??
	int i = pivot + 1; //pivot 다음 원소부터 검사
	int j = end;

	while (1) {
		while (L[i] < L[pivot] && i < end)  //while (L[i] > L[pivot] && i < end) 오름차순
			i++;
		while(L[j] > L[pivot] && j > start) //while(L[j] < L[pivot] && j > start) 오름차순
			j--;
		if (i >= j) { //엇갈림
			int tmp = L[pivot];
			L[pivot] = L[j];
			L[j] = tmp;
			break;
		}

		//엇갈리지 않음
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