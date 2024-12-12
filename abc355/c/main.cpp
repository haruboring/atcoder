#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(T);
    rep(i, T) cin >> A[i];
    rep(i, T) A[i]--;

    vector<set<int>> yoko(N), tate(N);
    rep(i, N) {
        rep(j, N) {
            yoko[i].insert(j);
            tate[i].insert(j);
        }
    }
    set<int> cross1, cross2;
    rep(i, N) {
        cross1.insert(i);
        cross2.insert(i);
    }

    rep(i, T) {
        int x = A[i] / N;
        int y = A[i] % N;

        if (yoko[x].count(y)) {
            yoko[x].erase(y);
            if (yoko[x].empty()) {
                cout << i + 1 << endl;
                return 0;
            }
        }
        if (tate[y].count(x)) {
            tate[y].erase(x);
            if (tate[y].empty()) {
                cout << i + 1 << endl;
                return 0;
            }
        }
        if (x == y) {
            if (cross1.count(x)) {
                cross1.erase(x);
                if (cross1.empty()) {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
        if (x + y == N - 1) {
            if (cross2.count(x)) {
                cross2.erase(x);
                if (cross2.empty()) {
                    cout << i + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;
}
