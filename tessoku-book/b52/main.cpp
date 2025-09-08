#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, X;
    cin >> N >> X;
    string A;
    cin >> A;

    queue<int> q;
    q.push(X - 1);
    A[X - 1] = '@';
    while (!q.empty()) {
        int pos = q.front();
        q.pop();

        if (pos - 1 >= 0 && A[pos - 1] == '.') {
            A[pos - 1] = '@';
            q.push(pos - 1);
        }
        if (pos + 1 < N && A[pos + 1] == '.') {
            A[pos + 1] = '@';
            q.push(pos + 1);
        }
    }

    cout << A << endl;
}
