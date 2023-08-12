#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    set<int> newer;
    bool small = false;
    bool large = false;
    rep(_, Q) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;

        if (t == 1) {
            S[x] = c;
            newer.insert(x);
        }

        if (t == 2) {
            newer.clear();
            small = true;
            large = false;
        }

        if (t == 3) {
            newer.clear();
            small = false;
            large = true;
        }
    }

    debug(small);
    debug(large);
    if (small) {
        rep(i, N) {
            if (newer.count(i)) {
                cout << S[i];
            } else {
                cout << char(tolower(S[i]));
            }
        }
    } else if (large) {
        rep(i, N) {
            if (newer.count(i)) {
                cout << S[i];
            } else {
                cout << char(toupper(S[i]));
            }
        }
    } else {
        rep(i, N) {
            cout << S[i];
        }
    }
    cout << endl;
}