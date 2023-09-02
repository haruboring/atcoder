#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> ans(N);
    int st = 1;
    int u = -1, l = -1;
    rep(i, N) {
        if (A[i] > st) {
            st = A[i];
            u = i;
            if (l != -1) ans[l] = 1;
        }
        if (A[i] < st) {
            st = A[i];
            l = i;
            if (u != -1) ans[u] = 1;
        }
        if (i == N - 1) {
            if (l != -1) ans[l] = 1;
        }
    }

    rep(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
}