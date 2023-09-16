#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    int slide = N / 5;
    vector<int> card(6);
    rep(i, 6) {
        card[i] = (i + slide) % 6 + 1;
    }
    rep(i, N % 5) {
        int buf = card[i];
        card[i] = card[i + 1];
        card[i + 1] = buf;
    }
    rep(i, 6) {
        cout << card[i];
    }
    cout << endl;
}