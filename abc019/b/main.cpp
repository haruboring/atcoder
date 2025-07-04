#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    S += "Z";
    int N = S.size();

    char c = 'X';
    int n = 0;
    rep(i, N) {
        if (S[i] == c) {
            n++;
        } else {
            if (c != 'X') cout << c << n;
            c = S[i];
            n = 1;
        }
    }
    cout << endl;
}
