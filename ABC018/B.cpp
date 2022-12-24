#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int N;
    cin >> N;
    vector<int> l(N), r(N);
    rep(i, N) {
        cin >> l[i] >> r[i];
    }
    rep(i, N) {
        reverse(S.begin() + l[i] - 1, S.begin() + r[i]);
    }
    cout << S << endl;
}