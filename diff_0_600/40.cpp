#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int cnt = 0;
    rep(i, n - 2) {
        vector<int> tmp(0);
        tmp.push_back(p[i]);
        tmp.push_back(p[i + 1]);
        tmp.push_back(p[i + 2]);
        sort(all(tmp));
        if (tmp[1] == p[i + 1]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}