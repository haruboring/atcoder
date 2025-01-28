#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int N;
vector<int> A(20);
vector<int> tmp(20);
unordered_set<int> ans;

void dfs(int i, int k) {
    if (i == N) {
        int x = 0;
        for (int j = 0; j < k; j++) x ^= tmp[j];
        ans.insert(x);
        return;
    }

    for (int j = 0; j < k; j++) {
        tmp[j] += A[i];
        dfs(i + 1, k);
        tmp[j] -= A[i];
    }

    tmp[k] = A[i];
    dfs(i + 1, k + 1);
}

signed main() {
    cin >> N;
    rep(i, N) cin >> A[i];

    dfs(0, 0);

    cout << ans.size() << endl;
}
