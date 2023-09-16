#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Q;
    cin >> Q;
    vector<vector<int>> query(Q, vector<int>(3));
    map<int, int> map;
    set<int> set;
    rep(i, Q) {
        cin >> query[i][0];
        if (query[i][0] != 3) {
            cin >> query[i][1];
        }
        if (query[i][0] == 2) {
            cin >> query[i][2];
        }
    }
    rep(i, Q) {
        if (query[i][0] == 1) {
            map[query[i][1]]++;
            set.insert(query[i][1]);
        } else if (query[i][0] == 2) {
            int size = map[query[i][1]];
            int erase_number = min(query[i][2], size);
            map[query[i][1]] -= erase_number;
            if (map[query[i][1]] == 0) {
                set.erase(query[i][1]);
            }
        } else {
            cout << *rbegin(set) - *begin(set) << endl;
        }
    }
}