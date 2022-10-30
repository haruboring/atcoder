#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }
    map<string, vector<string>> map;
    rep(i, N) {
        if (map[S[i]].size() == 0) {
            cout << S[i] << endl;
        } else {
            cout << S[i] << "(" << map[S[i]].size() << ")" << endl;
        }
        map[S[i]].push_back(S[i]);
    }
}