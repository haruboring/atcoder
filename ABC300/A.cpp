#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> C(N);
    rep(i, N) {
        cin >> C[i];
    }
    rep(i, N) {
        if (C[i] == A + B) {
            cout << i + 1 << endl;
        }
    }
}