#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, H, X;
    cin >> N >> H >> X;
    vector<int> P(N);
    rep(i, N) cin >> P.at(i);

    rep(i, N) {
        if (X - H <= P.at(i)) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}