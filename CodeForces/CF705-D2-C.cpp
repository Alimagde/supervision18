/*
     
 */
#include<bits/stdc++.h>

using namespace std;

const int N = 300005;
bool vis[N];
stack<int> st[N];
int all = 0, sz = 0;
int mxt = 0;

int main() {

    int n, q;
    scanf("%d %d", &n, &q);
    int t, x;
    while (q--) {
        scanf("%d %d", &t, &x);
        if (t == 1) {
            ++all;
            st[x].push(sz++);
        } else if (t == 2) {
            while (st[x].size()) {
                if (!vis[st[x].top()]) {
                    vis[st[x].top()] = 1;
                    --all;
                }
                st[x].pop();
            }
        } else {
            if (x > mxt) {
                for (int i = mxt; i < x; ++i) {
                    if (!vis[i]) {
                        --all;
                        vis[i] = 1;
                    }
                }
                mxt = x;
            }
        }
        printf("%d\n", all);
    }
}
