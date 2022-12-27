#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> m(a[N - 1] + 1);
    rep(i, N) {
        m[a[i]]++;
    }
    int max_cnt = 0;
    int current_cnt = m[0] + m[1] + m[2];
    rep(i, a[N - 1] - 2) {
        current_cnt += m[i + 3] - m[i];
        max_cnt = max(max_cnt, current_cnt);
    }
    cout << max_cnt << endl;
}