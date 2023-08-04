#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    rep(i, M) A[i]--;

    vector<int> base(N);
    rep(i, N) base[i] = i + 1;
    rep(i, M) {
        int tmp = base[A[i]];
        base[A[i]] = base[A[i] + 1];
        base[A[i] + 1] = tmp;
    }

    map<int, int> mp;
    rep(i, N) {
        mp[base[i]] = i + 1;
    }

    vector<int> B(N);
    rep(i, N) B[i] = i + 1;
    rep(i, M) {
        int x = B[A[i]];
        int y = B[A[i] + 1];

        if (x != 1 && y != 1) {
            cout << mp[1] << endl;
        } else if (x == 1) {
            cout << mp[y] << endl;
        } else {
            cout << mp[x] << endl;
        }

        int tmp = B[A[i]];
        B[A[i]] = B[A[i] + 1];
        B[A[i] + 1] = tmp;
    }
}