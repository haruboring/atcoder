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

    int pre = -1;
    map<int, int> mp;
    deque<int> q;
    rep(i, N) {
        q.push_back(A[i]);
        if (pre == A[i]) {
            mp[A[i]]++;
        } else {
            mp.clear();
            mp[A[i]] = 0;
            for (int j = q.size() - 1; j >= 0; j--) {
                if (q[j] == A[i]) {
                    mp[A[i]]++;
                } else {
                    break;
                }
            }
        }
        if (mp[A[i]] >= A[i]) {
            mp[A[i]] -= A[i];
            rep(j, A[i]) {
                q.pop_back();
            }
        }
        pre = A[i];

        cout << q.size() << endl;
    }
}
