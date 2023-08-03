#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N) cin >> p[i];

    vector<int> cp = p;
    sort(all(cp));

    int cnt = 0;
    rep(i, N) {
        if (p[i] != cp[i]) cnt++;
    }

    if (cnt == 2 || cnt == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}