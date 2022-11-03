#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<int> d;
    rep(i, N) {
        int d_i;
        cin >> d_i;
        d.insert(d_i);
    }
    cout << d.size() << endl;
}