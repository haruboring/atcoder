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
    vector<int> C(N);
    vector<vector<int>> S(N);
    vector<double> ave(N);
    rep(i, N) {
        cin >> C[i];
        int P;
        cin >> P;
        double sum = 0;
        rep(j, P) {
            int s;
            cin >> s;
            S[i].push_back(s);
            sum += s;
        }
        ave[i] = sum / P;
        debug(ave[i]);
    }

    vector<double> dp(10000000 + 10, -1);
    dp[0] = 0;
    set<int> st;
    st.insert(0);
    for (auto i : st) {
        vector<int> add(0);
        bool over = false;
        vector<int> dpp(0);
        rep(j, N) {
            if (dp[i] + ave[j] >= M) {
                over = true;
                dpp.push_back(dp[i] + ave[j]);
            } else {
                dp[i + C[j]] = max(dp[i + C[j]], dp[i] + ave[j]);

                if (dp[i + C[j]] < M) add.push_back(i + C[j]);
            }
        }
        if (over) {
            sort(all(dpp));
            int mi = dpp[0];
            rep(j, N) {
                if (dp[i] + ave[j] == mi) {
                    dp[i + C[j]] = max(dp[i + C[j]], dp[i] + ave[j]);
                }
            }
        }
        for (auto j : add) {
            st.insert(j);
        }
    }

    debug(st.size());

    double cnt = 0;
    double sum = 0;
    rep(i, 10000000 + 10) {
        if (dp[i] == -1) continue;
        if (dp[i] < M) continue;
        debug(i);
        debug(dp[i]);
        cnt++;
        sum += i;
    }
    cout << sum / cnt << endl;
}