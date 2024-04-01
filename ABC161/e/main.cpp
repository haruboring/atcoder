#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    set<int> s, s1, s2;
    int idx = 0;
    int cnt = 0;
    while (1) {
        if (idx >= N) break;
        if (S[idx] == 'o') {
            s.insert(idx);
            cnt++;
            idx += C + 1;
        } else {
            idx++;
        }
    }
    if (cnt > K) {
        cout << endl;
        return 0;
    }

    idx = 0;
    cnt = 0;
    while (1) {
        if (cnt == K) break;
        if (S[idx] == 'o') {
            s1.insert(idx);
            cnt++;
            idx += C + 1;
        } else {
            idx++;
        }
    }
    idx = N - 1;
    cnt = 0;
    while (1) {
        if (cnt == K) break;
        if (S[idx] == 'o') {
            s2.insert(idx);
            cnt++;
            idx -= C + 1;
        } else {
            idx--;
        }
    }

    for (int i = 0; i < N; i++) {
        if (s1.count(i) && s2.count(i)) {
            cout << i + 1 << endl;
        }
    }
}
