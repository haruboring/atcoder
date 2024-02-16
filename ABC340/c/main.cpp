#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    return memo[n] = n + f(n / 2) + f((n + 1) / 2);
}

signed main() {
    int N;
    cin >> N;

    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 2;
    memo[3] = 5;

    int ans = f(N);
    cout << memo[N] << endl;
}
