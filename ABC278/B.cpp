#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int h, m;
    cin >> h >> m;
    int add = 0;
    while (1) {
        int mx = (m + add) % 60;
        int hx = (h + ((m + add) / 60)) % 24;
        string a = to_string(hx / 10);
        string b = to_string(hx % 10);
        string c = to_string(mx / 10);
        string d = to_string(mx % 10);
        string ac = a + c;
        string bd = b + d;
        if (stoi(ac) < 24 && stoi(bd) < 60) {
            cout << hx << " " << mx << endl;
            break;
        }
        add++;
    }
}