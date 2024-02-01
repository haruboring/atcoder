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
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }
    vector<int> sec(0);
    rep(i, 10) {
        multiset<int> pos;
        int time = 0;
        rep(j, N) {
            rep(k, 10) {
                if (S[j][k] == char(i + '0')) {
                    pos.insert(k);
                    break;
                }
            }
        }
        rep(k, 999) {
            if (pos.size() == 0) {
                sec.push_back(time);
                break;
            }
            if (pos.find(k % 10) == pos.end()) {
                continue;
            }
            time = 10 * (k / 10) + *rbegin(pos);
            pos.erase(pos.find(k % 10));
        }
    }
    sort(all(sec));
    cout << sec[0] << endl;
}