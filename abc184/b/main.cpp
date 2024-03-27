#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    rep(i, N) {
        if (S.at(i) == 'o') {
            X++;
        } else {
            X = max(0, X - 1);
        }
    }

    cout << X << endl;
}