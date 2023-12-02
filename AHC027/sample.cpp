#include "bits/stdc++.h"
#include "fstream"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<pair<int, int>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
string dir = "RDLU";

string ans = "";

void dfs(int i, int j, int N, vector<string>& h, vector<string>& v, vector<vector<int>>& d, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int di = dij[k].first;
        int dj = dij[k].second;
        int i2 = i + di;
        int j2 = j + dj;
        if (0 <= i2 && i2 < N && 0 <= j2 && j2 < N && !visited[i2][j2]) {
            if ((di == 0 && v[i][min(j, j2)] == '0') || (dj == 0 && h[min(i, i2)][j] == '0')) {
                ans += dir[k];
                dfs(i2, j2, N, h, v, d, visited);
                ans += dir[(k + 2) % 4];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream fin("tools/in/" + string(argv[1]));
    if (!fin) {
        cerr << "can not open " << "tools/in/" + string(argv[1]) << endl;
        return 1;
    }
    cout << "tools/out/" + string(argv[1]) << endl;
    ofstream fout("tools/out/" + string(argv[1]));

    int N;
    fin >> N;
    vector<string> h(N - 1);
    vector<string> v(N);
    vector<vector<int>> d(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    rep(i, N - 1) fin >> h[i];
    rep(i, N) fin >> v[i];
    rep(i, N) rep(j, N) fin >> d[i][j];

    dfs(0, 0, N, h, v, d, visited);

    fout << ans << endl;

    return 0;
}

// // 提出用
// int main() {
//     int N;
//     cin >> N;
//     vector<string> h(N - 1);
//     vector<string> v(N);
//     vector<vector<int>> d(N, vector<int>(N));
//     vector<vector<bool>> visited(N, vector<bool>(N, false));

//     rep(i, N - 1) cin >> h[i];
//     rep(i, N) cin >> v[i];
//     rep(i, N) rep(j, N) cin >> d[i][j];

//     dfs(0, 0, N, h, v, d, visited);
//     cout << ans << endl;

//     return 0;
// }
