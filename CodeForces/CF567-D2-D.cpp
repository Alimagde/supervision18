/*
 binary search for the first index that can't put the ships after it
 */
#include <bits/stdc++.h>
using namespace std;

int n, k, a;
int arr[200005];

bool can(int idx) {
	vector<int> vec;
	for (int i = 1; i <= idx; ++i) {
		vec.push_back(arr[i]);
	}
	vec.push_back(0);
	vec.push_back(n + 1);
	sort(vec.begin(), vec.end());
	int v = 0;
	for (int i = 1; i < (int) vec.size(); ++i) {
		v += (vec[i] - vec[i - 1]) / (a + 1);
	}

	return (v >= k);
}

int main() {
	scanf("%d %d %d", &n, &k, &a);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d", arr + i);
	int s = 1, e = m + 1;
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (!can(mid))
			e = mid;
		else
			s = mid + 1;
	}

	if (s < m + 1)
		printf("%d", s);
	else
		puts("-1");
}
