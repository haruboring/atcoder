#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int op(int a, int b) { return max(a, b); }
int e() { return 1e18; }
int mapping(int f, int x) { return f + x; }
int composition(int f, int g) { return f + g; }
int id() { return 0; }

signed main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    rep(i, N) {
        A[i]--;
        B[i]--;
    }

    map<int, int> mp;
    rep(i, N) {
        mp[A[i]] = B[i];
        mp[B[i]] = A[i];
    }

    set<int> decided;

    int scope = 1e9;
    rep(i, 2 * N) {
        if (decided.count(i)) continue;

        int a = i, b = mp[i];
        if (a > scope) scope = 1e9;
        if ((b - a + 2 * N) % N == 1) {
            decided.insert(i);
            decided.insert(mp[i]);
            continue;
        }
        if (b > scope) {
            cout << "Yes" << endl;
            return 0;
        }
        scope = b;

        decided.insert(i);
        decided.insert(mp[i]);
    }

    cout << "No" << endl;
}
