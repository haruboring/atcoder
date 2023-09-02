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

    if (N == 6) {
        cout << "###..." << endl;
        cout << "...###" << endl;
        cout << "###..." << endl;
        cout << "...###" << endl;
        cout << "###..." << endl;
        cout << "...###" << endl;
        return 0;
    }

    vector<vector<char>> ans(N, vector<char>(N, '.'));

    ans[0][0] = '#';
    int x = 0;
    repp(i, 1, N) {
        repp(j, x, x + 2) {
            ans[i][j] = '#';
        }
        x++;
    }

    ans[0][N - 2] = '#';
    ans[0][N - 1] = '#';
    ans[1][N - 1] = '#';

    x = N - 3;
    repp(i, 2, N) {
        ans[i][x % (N - 2)] = '#';
        x++;
    }

    rep(i, N) {
        rep(j, N) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}