#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> S(K);
    rep(i, N) {
        string s;
        cin >> s;
        if (i < K) {
            S[i] = s;
        }
    }
    sort(all(S));
    rep(i, K) {
        cout << S[i] << endl;
    }
}