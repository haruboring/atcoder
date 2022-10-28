#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> a_i(N, vector<int>(2));
    int a;
    ll same_num_cnt = 0;
    rep(i, N) {
        cin >> a;
        a_i[i][0] = a;
        a_i[i][1] = i + 1;
        if (a == i + 1) {
            same_num_cnt++;
        }
        sort(all(a_i[i]));
    }
    sort(all(a_i));
    ll ans = (same_num_cnt * (same_num_cnt - 1)) / 2;
    rep(i, N - 1) {
        if (a_i[i][0] == a_i[i + 1][0] && a_i[i][1] == a_i[i + 1][1]) {
            ans++;
        }
    }
    cout << ans << endl;
}