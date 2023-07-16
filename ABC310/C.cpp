#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<string> rS(N);
    rep(i, N) {
        rS[i] = S[i];
        reverse(all(rS[i]));
    }

    set<string> st;
    int cnt = 0;
    rep(i, N) {
        if (st.count(S[i]) == 0 && st.count(rS[i]) == 0) cnt++;
        st.insert(S[i]);
        st.insert(rS[i]);
    }
    cout << cnt << endl;
}