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
    set<int> call, go, uncall;
    rep(i, N) {
        uncall.insert(i + 1);
    }
    rep(i, Q) {
        int flag;
        cin >> flag;
        if (flag == 1) {
            int calling_number = *begin(uncall);
            uncall.erase(calling_number);
            call.insert(calling_number);
        } else if (flag == 2) {
            int x;
            cin >> x;
            call.erase(x);
            go.insert(x);
        } else {
            cout << (int)(*begin(call)) << endl;
        }
    }
}