#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int Y;
    cin >> Y;
    int held_year = 4 * ((Y + 1) / 4) + 2;
    cout << held_year << endl;
}