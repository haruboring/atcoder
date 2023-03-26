#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> W(N);
    rep(i, N) {
        cin >> W[i];
    }
    rep(i, N) {
        if (W[i] == "and" || W[i] == "not" || W[i] == "that" || W[i] == "the" || W[i] == "you") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}