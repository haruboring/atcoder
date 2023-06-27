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

    vector<int> dels(N);
    set<int> left;
    map<int,int> l2r;
    rep(i, N) {
        if (S[i] == '(') {
            left.insert(i);
        }
        if (S[i] == ')') {
            if (left.empty()) continue;
            int l = *left.rbegin();
            debug(l);
            left.erase(l);
            l2r[l] = i;

            for (int j = l; j <= i; j++) {
                if (dels[j] == 1) j = l2r[j];
                dels[j] = 1;
            }
        }
    }

    rep(i, N) {
        if (!dels[i]) cout << S[i];
    }
    cout << endl;
}