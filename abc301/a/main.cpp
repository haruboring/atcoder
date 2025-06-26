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
    string S;
    cin >> S;

    int t_cnt = 0;
    rep(i, N) if (S[i] == 'T') t_cnt++;

    if (t_cnt < N - t_cnt) {
        cout << "A" << endl;
        return 0;
    }
    if (t_cnt > N - t_cnt) {
        cout << "T" << endl;
        return 0;
    }

    int ac = 0, tc = 0;
    rep(i, N) {
        if (S[i] == 'T') {
            tc++;
        } else {
            ac++;
        }

        if (tc == t_cnt) {
            cout << "T" << endl;
            return 0;
        }
        if (ac == t_cnt) {
            cout << "A" << endl;
            return 0;
        }
    }
}
