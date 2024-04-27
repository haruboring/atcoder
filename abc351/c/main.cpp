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

    stack<int> q;
    rep(i, N) {
        q.push(A[i]);
        while (q.size() >= 2) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if (a != b) {
                q.push(b);
                q.push(a);
                break;
            } else {
                q.push(a + 1);
            }
        }
    }
    cout << q.size() << endl;
}
