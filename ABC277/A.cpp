#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> P(N);
    rep(i, N) {
        cin >> P[i];
    }
    rep(i, N) {
        if (P[i] == X) {
            cout << i + 1 << endl;
        }
    }
}