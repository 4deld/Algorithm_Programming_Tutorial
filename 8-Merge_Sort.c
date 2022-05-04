//Merge_Sort
//배열을 두 부분으로 나눠서 정렬해서 분할 정복이라고도 부른다
// 분할을 했다가 합칠 때 각각의 분할된 배열들은 다 정렬이 되어있는 상태이기  때문에
// N번만 검사하면 합쳐진 배열을 정렬된 상태로 만들 수 있다 -> 빠르다!
// (원소를 두 집합으로 나눈다는 말)
// 
// 두 부분으로 나눠서 계산하고 합치면 연산 횟수가 매우 적어진다
//시간복잡도 O(N*logN)을 보장한다 (보통 밑이 2인 로그를 상용로그로 쓴다)
// logN은 거의 상수로 봐도 될 정도로 작은 값이다
//퀵 정렬과 다르게 항상 반으로 나누기 때문에 Pivot값이 없다
//정렬에 사용되는 배열은 전역 변수로 선언해야 한다
//전역 변수로 선언하지 않으면 매번 배열을 선언해야 하기 때문
//기존의 데이터를 담을 배열이 필요해서 메모리 활용이 비효율적



//전체적인 실행순서
//7 6 5 8 -> 7 6 -> 7 -> 6->merge(6, 7) -> 5 8 -> 5 -> 8->merge(5, 8)->merge(5, 6, 7, 8)
//                                                                                                                                        ->merge(1, 3, 5, 5, 6, 7, 8, 9) -> 1 3 5 5 6 7  8 9
//3 5 9 1 -> 3 5 -> 3 -> 5->merge(3, 5) -> 9 1 -> 9 -> 1->merge(1, 9)->merge(1, 3, 5, 9)
#include<stdio.h>
int sorted[10000]; //정렬된 배열을 저장할 전역변수 배열
int N;


void Merge(int *L,int left, int middle, int right) {

	int i = left; //왼쪽 분할 배열의 첫번째 인덱스
	int j = middle + 1; //오른쪽 분할의 첫번째 인덱스
	int k = left; //합쳐지는 배열의 첫번째 인덱스

	//fix된 값들
	int h = left; 
	int f = middle;
	int u = right;

	while (i <= f && j <= u) {  //왼쪽 배열 혹은 오른쪽 배열 중 하나의 원소가 다 들어갈 때까지
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

	//위에서 남은 원소들 넣기
	while (k != u+1) {
		sorted[k++] = L[q++];
	}

	//복사하기
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

	//중간
	int middle = (left + right) / 2;

	//재귀함수로 분할
	Merge_Sort(L, left, middle);
	Merge_Sort(L, middle + 1, right);

	//병합
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