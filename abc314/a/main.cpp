#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    int N;
    cin >> N;

    rep(i, N + 2) {
        cout << pi[i];
    }
    cout << endl;
}