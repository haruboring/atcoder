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

    deque<int> d;
    rep(i, N) {
        if (A[i] == 0) {
            d.push_back(-1);
        } else {
            d.push_back(1);
        }
    }
    int ord = 1;
    while (d.size() > 0) {
        int ecnt = 0;
        int t = d.back();
        while ((t * ord) == -1) {
            d.pop_back();
            if (d.size() == 0) {
                cout << "Yes" << endl;
                return 0;
            }
            t = d.back();
            ecnt++;
        }
        t = d.front();
        if (t * ord == -1) {
            d.pop_front();
            ord *= -1;
            ecnt++;
        }

        if (ecnt == 0) break;
    }

    if (d.size() == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
