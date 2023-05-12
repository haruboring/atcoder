#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> numbers_of_UB(0);
vector<int> number_of_UB(0);

void dfs(int m, int n) {
    if (m < 0 || n < 0) {
        return;
    }
    if (n == 0 && m >= 0) {
        numbers_of_UB.push_back(number_of_UB);
        return;
    }

    for (int i = 0; i <= m; i++) {
        number_of_UB.push_back(i);
        dfs(m - i, n - 1);
        number_of_UB.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];
    set<string> check;
    rep(i, M) check.insert(T[i]);
    int size = N - 1;
    rep(i, N) size += S[i].size();
    if (size > 16) {
        cout << -1 << endl;
        return 0;
    }

    dfs(16 - size, N - 1);

    string UB = "________________";
    sort(all(S));
    do {
        for (auto number_of_UB : numbers_of_UB) {
            string pass = "";
            int i = -1;
            for (string key : S) {
                if (i == -1)
                    pass += key;
                else
                    pass += UB.substr(15 - number_of_UB[i], 16) + key;
                i++;
            }
            if (check.count(pass) == 0 && pass.size() >= 3) {
                cout << pass << endl;
                return 0;
            }
        }
    } while (next_permutation(all(S)));

    cout << -1 << endl;
}