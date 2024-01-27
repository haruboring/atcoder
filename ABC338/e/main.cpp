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
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    rep(i, N) {
        A[i]--;
        B[i]--;
    }

    int diff = -1;
    rep(i, N) {
        if (abs(A[i] - B[i]) == 1) {
            diff = max(A[i], B[i]);
            break;
        }
    }
    debug(diff);
    rep(i, N) {
        A[i] = (A[i] - diff + 2 * N) % (2 * N);
        B[i] = (B[i] - diff + 2 * N) % (2 * N);
        // debug(A[i]);
        // debug(B[i]);
    }

    rep(i, N) {
        if (A[i] > B[i]) swap(A[i], B[i]);
    }

    vector<pair<int, int>> AB;
    rep(i, N) AB.push_back(make_pair(A[i], B[i]));
    sort(all(AB));

    bool sp = true;
    swap(AB[0].first, AB[0].second);
    rep(i, N) {
        // cout << AB[i].first << " " << AB[i].second << endl;
        if (AB[i].first % 2 != 1) sp = false;
        if (AB[i].second % 2 != 0) sp = false;
    }
    swap(AB[0].first, AB[0].second);

    if (sp) {
        cout << "No" << endl;
        return 0;
    }

    rep(i, N) {
        if (AB[i].first != i) {
            cout << "Yes" << endl;
            return 0;
        }
        if (AB[i].second != 2 * N - i - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
