//#include<stdio.h> //정답 코드
//int n, u, sorted[1000000],q;
//int L[1000000];
//
//void P(int l, int k) {
//	for (int i = 0; i < n; i++) {
//		if(i>=l && i<=k)
//			printf("%d ", sorted[i]);
//		else
//			printf("%d ", L[i]);
//	}
//	q = 1;
//}
//
//void Merge(int *arr,int l,int m,int r) {
//	int i = l;
//	int j = m + 1;
//	int k = l;
//	
//	while (i <= m && j <= r) {
//		if (arr[i] > arr[j])
//			sorted[k++] = arr[j++];
//		else
//			sorted[k++] = arr[i++];
//		u--;
//		if (u == 0)
//			P(l, k);
//	}
//	while (i <= m) {
//		sorted[k++] = arr[i++];
//		u--;
//		if (u == 0)
//			P(l, k);
//	}
//	while (j <= r) {
//		sorted[k++] = arr[j++];
//		u--;
//		if (u == 0)
//			P(l, k);
//	}
//	for (int t = l; t <= r; t++)
//		L[t] = sorted[t];
//
//
//}
//
//void Merge_Sort(int *arr,int l, int r) {
//	if (l >= r)
//		return;
//	int m = (l + r) / 2;
//	Merge_Sort(arr, l, m);
//	Merge_Sort(arr, m+1, r);
//	Merge(arr, l, m, r);
//
//
//}
//int main() {
//
//	scanf("%d %d", &n, &u);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &L[i]);
//		sorted[i] = L[i];
//	}
//	Merge_Sort(L, 0, n - 1);
//	if (!q)
//		printf("-1");
//	return 0;
//}

#include<stdio.h> //시각화
int n, sorted[1000000], q;
int L[1000000];

void P(int l, int k) {
	for (int i = 0; i < n; i++) {
		if (i >= l && i <= k)
			printf("%d ", sorted[i]);
		else
			printf("%d ", L[i]);
	}
	printf("\n");
	q = 1;
}

void Merge(int* arr, int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (arr[i] > arr[j])
			sorted[k++] = arr[j++];
		else
			sorted[k++] = arr[i++];
		P(l, k);
	}
	while (i <= m) {
		sorted[k++] = arr[i++];
		P(l, k);
	}
	while (j <= r) {
		sorted[k++] = arr[j++];
		P(l, k);
	}
	for (int t = l; t <= r; t++)
		L[t] = sorted[t];


}

void Merge_Sort(int* arr, int l, int r) {
	if (l >= r)
		return;
	int m = (l + r) / 2;
	Merge_Sort(arr, l, m);
	Merge_Sort(arr, m + 1, r);
	Merge(arr, l, m, r);


}
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &L[i]);
		sorted[i] = L[i];
	}
	Merge_Sort(L, 0, n - 1);
	if (!q)
		printf("-1");
	return 0;
}