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

    set<pair<int, int>> st;
    int i = 0, j = 0;
    st.insert({i, j});
    rep(k, N) {
        int ni = i, nj = j;
        if (S[k] == 'R') {
            ni++;
        }
        if (S[k] == 'L') {
            ni--;
        }
        if (S[k] == 'U') {
            nj++;
        }
        if (S[k] == 'D') {
            nj--;
        }
        if (st.count({ni, nj})) {
            cout << "Yes" << endl;
            return 0;
        }
        st.insert({ni, nj});
        i = ni;
        j = nj;
    }
    cout << "No" << endl;
}
