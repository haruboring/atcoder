#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> rs(N);
    rep(i, N) {
        string s;
        cin >> s;
        reverse(all(s));
        rs[i] = s;
    }

    sort(all(rs));
    rep(i, N) {
        reverse(all(rs[i]));
        cout << rs[i] << endl;
    }
}