#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string W;
    cin >> W;
    vector<char> boin = {'a', 'i', 'u', 'e', 'o'};

    rep(i, W.size()) {
        bool is_boin = false;
        rep(j, 5) {
            if (W[i] == boin[j]) {
                is_boin = true;
            }
        }
        if (is_boin == false) {
            cout << W[i];
        }
    }
    cout << endl;
}