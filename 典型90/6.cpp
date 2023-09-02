#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

// res[i][c] := i 文字目以降で最初に文字 c が登場する index
// 存在しないときは N
vector<vector<int>> calc_next(const string &S) {
    // 文字列 S の長さ
    int N = (int)S.size();

    // 答え
    vector<vector<int>> res(N + 1, vector<int>(26, N));

    // 後ろから見る
    for (int i = N - 1; i >= 0; --i) {
        // i + 1 文字目以降の結果を一旦 i 文字にコピー
        res[i] = res[i + 1];

        // i 文字目の情報を反映させる
        res[i][S[i] - 'a'] = i;
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int i = -1;
    string ans = "";

    vector<vector<int>> next = calc_next(S);

    while (ans.size() < K) {
        char c = 'z' + 1;
        for (char c = 'a'; c <= 'z'; c++) {
            int ni = next[i + 1][c - 'a'];

            if (ni + K - ans.size() <= N) {
                ans += c;
                i = ni;
                break;
            }
        }
    }

    cout << ans << endl;
}