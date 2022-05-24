#include<stdio.h>

int main() {
	int n, k, li[100000];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &li[i]);
	for (int i = 0; i < n; i++) {
		int loc = i - 1;
		int newitem = li[i];
		while (loc > -1 && newitem < li[loc]) {
			li[loc + 1] = li[loc];
			k--;
			if (!k) {
				for (int i = 0; i < n; i++)
					printf("%d ", li[i]);
				return 0;
			}
			loc--;
		}
		if (loc + 1 != i) {
			li[loc + 1] = newitem;
			k--;
			if (!k) {
				for (int i = 0; i < n; i++)
					printf("%d ", li[i]);
				return 0;
			}
		}
	}

	printf("-1");
	return 0;
}