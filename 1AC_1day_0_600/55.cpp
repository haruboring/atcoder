#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll X;
    cin >> X;

    ll money = 100;
    ll year = 0;
    while (money < X) {
        money += money / 100;
        year++;
    }
    cout << year << endl;
}