#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    map<char, vector<int>> map;
    rep(i, 3) {
        map[S[i]].push_back(1);
    }
    rep(i, 3) {
        if (map[S[i]].size() == 1) {
            cout << S[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}