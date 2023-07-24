#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N + 2);
    S[0] = string(M + 2, '#');
    rep(i, N) {
        string s;
        cin >> s;
        S[i + 1] = "#" + s + "#";
    }
    S[N + 1] = string(M + 2, '#');

    set<pair<int, int>> st;
    st.insert({2, 2});
    queue<pair<int, int>> q;
    q.push({2, 2});
    set<pair<int, int>> already_stop;
    already_stop.insert({2, 2});

    vector<vector<int>> move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        rep(i, 4) {
            int dx = move[i][0];
            int dy = move[i][1];
            int nx = x;
            int ny = y;
            while (S[nx + dx][ny + dy] == '.') {
                st.insert({nx, ny});
                nx += dx;
                ny += dy;
            }
            if (already_stop.count({nx, ny}) == 0) {
                q.push({nx, ny});
                already_stop.insert({nx, ny});
            }
        }
    }

    // for(auto [a, b] : already_stop) {
    //     cout << "a: " << a << " b: " << b << endl;
    // }

    cout << st.size() << endl;
}