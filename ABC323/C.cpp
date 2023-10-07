#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) {
        cin >> A[i];
    }
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<multiset<int>> res(N);
    multiset<int> ms;
    vector<int> v(N);

    rep(i, N) {
        int tmp = 0;
        rep(j, M) {
            if (S[i][j] == 'o') {
                tmp += A[j];
            } else {
                res[i].insert(A[j]);
            }
        }
        tmp += i + 1;
        ms.insert(tmp);
        v[i] = tmp;
    }

    debug(N);

    rep(i, N) {
        int score = v[i];
        ms.erase(ms.find(score));
        int h = *ms.rbegin();
        int tmp = score;
        int cnt = 0;
        debug(i);
        while (tmp <= h) {
            int a = *res[i].rbegin();
            debug(a);
            tmp += a;
            res[i].erase(res[i].find(a));
            cnt++;
        }

        cout << cnt << endl;
        ms.insert(score);
    }
}