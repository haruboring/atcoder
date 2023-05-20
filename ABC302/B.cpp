#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<char> su = {'s', 'n', 'u', 'k', 'e'};
    vector<vector<int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    rep(i, H) {
        rep(j, W) {
            for (auto m : move) {
                int ind = 0;
                vector<pair<int, int>> a(0);
                int x = i, y = j;
                if (S[i][j] == su[ind]) {
                    a.push_back(make_pair(x, y));
                    ind++;
                } else {
                    break;
                }
                rep(_, 4) {
                    x += m[0];
                    y += m[1];
                    if (x < 0 || x >= H || y < 0 || y >= W) break;
                    if (S[x][y] == su[ind]) {
                        a.push_back(make_pair(x, y));
                        ind++;
                    }
                }
                if (a.size() == 5) {
                    for (auto ans : a) {
                        cout << ans.first + 1 << " " << ans.second + 1 << endl;
                    }
                    return 0;
                }
            }
        }
        cout << endl;
    }
}