#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> x(Q);
    rep(i, Q) {
        cin >> x[i];
    }
    // value -> index
    map<int, int> v_i, i_v;
    rep(i, N) {
        v_i[i + 1] = i;
        i_v[i] = i + 1;
    }
    rep(i, Q) {
        if (v_i[x[i]] != N - 1) {
            int rvalue = i_v[v_i[x[i]] + 1];
            int lvalue = x[i];
            int rindex = v_i[rvalue];
            int lindex = v_i[lvalue];
            i_v[lindex] = rvalue;
            i_v[rindex] = lvalue;
            v_i[lvalue] = rindex;
            v_i[rvalue] = lindex;
        }
        else{
            int rvalue = x[i];
            int lvalue = i_v[v_i[x[i]] - 1];
            int rindex = v_i[rvalue];
            int lindex = v_i[lvalue];
            i_v[lindex] = rvalue;
            i_v[rindex] = lvalue;
            v_i[lvalue] = rindex;
            v_i[rvalue] = lindex;
        }
    }
    rep(i, N) {
        cout << i_v[i] << " ";
    }
    cout << endl;
}