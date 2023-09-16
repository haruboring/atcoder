#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;
    vector<set<char>> box(int(S.size()));
    stack<int> q;
    rep(i, S.size()) {
        if (i > 0) {
            box[i] = box[i - 1];
        }
        if (S[i] == '(') {
            q.push(i);
        } else if (S[i] == ')') {
            box[i] = box[q.top()];
            q.pop();
        } else {
            if (box[i].count(S[i])) {
                cout << "No" << endl;
                return 0;
            } else {
                box[i].insert(S[i]);
            }
        }
    }
    cout << "Yes" << endl;
}