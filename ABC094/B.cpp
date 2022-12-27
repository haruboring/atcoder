#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    set<int> s;
    rep(i, M) {
        int A;
        cin >> A;
        s.insert(A);
    }
    int n_cnt = 0;
    repp(i, X, N + 1) {
        if (s.count(i)) {
            n_cnt++;
        }
    }
    int zero_cnt = 0;
    repp(i, 0, X + 1) {
        if (s.count(i)) {
            zero_cnt++;
        }
    }
    cout << min(n_cnt, zero_cnt) << endl;
}