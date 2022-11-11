#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> h(N + 1), ans(N + 1);
    rep(i, N) {
        cin >> h[i + 1];
    }
    ans[2] = abs(h[2] - h[1]);
    repp(i, 3, N + 1) {
        ans[i] = min(ans[i - 1] + (abs(h[i] - h[i - 1])), ans[i - 2] + (abs(h[i] - h[i - 2])));
    }
    cout << ans[N] << endl;
}