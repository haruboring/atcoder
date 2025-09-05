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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int Q;
    cin >> Q;

    map<int, int> mae, usiro;
    rep(i, N - 1) mae[A[i + 1]] = A[i], usiro[A[i]] = A[i + 1];
    mae[A[0]] = 0;
    usiro[0] = A[0];
    usiro[A[N - 1]] = 1e18;
    mae[1e18] = A[N - 1];

    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int x, y;
            cin >> x >> y;

            int ousiro = usiro[x];
            usiro[x] = y;
            mae[y] = x;
            usiro[y] = ousiro;
            mae[ousiro] = y;
        } else {
            int x;
            cin >> x;

            int omae = mae[x], ousiro = usiro[x];
            usiro[omae] = ousiro;
            mae[ousiro] = omae;
        }
    }

    int s = usiro[0];
    while (s != 1e18) {
        cout << s << " ";
        s = usiro[s];
    }
    cout << endl;
}
