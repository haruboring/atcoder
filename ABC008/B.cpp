#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    map<string, int> m;
    rep(i, N) {
        cin >> S[i];
    }
    rep(i, N) {
        m[S[i]]++;
    }
    int max_duplicate_cnt = 0;
    rep(i, N) {
        max_duplicate_cnt = max(max_duplicate_cnt, m[S[i]]);
    }
    rep(i, N) {
        if (m[S[i]] == max_duplicate_cnt) {
            cout << S[i] << endl;
            return 0;
        }
    }
}