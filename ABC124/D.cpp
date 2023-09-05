#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<pair<char, int>> runLengthEncoding(string s) {
    int n = s.length();

    vector<pair<char, int>> res;
    char pre = s[0];
    int cnt = 1;
    repp(i, 1, n) {
        if (pre != s[i]) {
            res.push_back({pre, cnt});
            pre = s[i];
            cnt = 1;
        } else
            cnt++;
    }

    res.push_back({pre, cnt});
    return res;
}

signed main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    auto blocks = runLengthEncoding(S);
    int ans = 0;
    int sum = 0;
    int cnt = 0;
    int L = 0;
    rep(i, blocks.size()) {
        sum += blocks[i].second;
        if (blocks[i].first == '0') cnt++;

        while (K < cnt) {
            sum -= blocks[L].second;
            if (blocks[L].first == '0') cnt--;
            L++;
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
}