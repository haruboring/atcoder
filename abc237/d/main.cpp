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

    deque<int> dq;
    dq.push_back(N);
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'R') {
            dq.push_front(i);
        } else {
            dq.push_back(i);
        }
    }

    for (auto a : dq) {
        cout << a << " ";
    }
    cout << endl;
}
