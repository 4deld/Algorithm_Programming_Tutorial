#include<stdio.h>

int main() {
	int n, k, li[100000];
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &li[i]);

	for (int i = 0; i < n; i++) {
		int loc = i - 1;
		int newitem = li[i];
		while (-1 < loc && newitem < li[loc]) {
			li[loc + 1] = li[loc];
			k--;
			if (k == 0) {
				printf("%d", li[loc]);
				return 0;
			}
			loc--;
		}
		if (loc + 1 != i) {
			li[loc + 1] = newitem;
			k--;
			if (!k) {
				printf("%d", newitem);
				return 0;
			}
		}
	}
	printf("-1");

	return 0;
}