#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 1e9;
    vector<string> commands = {"AA", "AB", "AX", "AY", "BA", "BB", "BX", "BY", "XA", "XB", "XX", "XY", "YA", "YB", "YX", "YY"};
    rep(i, commands.size()) {
        rep(j, commands.size()) {
            string command1 = commands[i];
            string command2 = commands[j];
            int cnt = 0;
            rep(k, N) {
                if (k < N - 1 && S.substr(k, 2) == command1) {
                    cnt++;
                    k++;
                } else if (k < N - 1 && S.substr(k, 2) == command2) {
                    cnt++;
                    k++;
                } else {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
}