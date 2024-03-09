#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(T), B(T);
    rep(i, T) cin >> A[i] >> B[i];

    map<int, int> mp;
    map<int, int> scores;
    mp[0] = N;
    rep(i, N) scores[i] = 0;
    int cnt = 1;
    rep(i, T) {
        int p_score = scores[A[i]];
        int a_score = p_score + B[i];
        int b_size = mp[p_score];
        int a_size = mp[a_score];

        if (b_size == 1) {
            cnt--;
        }
        if (a_size == 0) {
            cnt++;
        }
        mp[p_score]--;
        mp[a_score]++;
        scores[A[i]] = a_score;

        cout << cnt << endl;
    }
}
