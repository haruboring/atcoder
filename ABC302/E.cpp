#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> query(0);

    rep(i, Q) {
        vector<int> q(1);
        cin >> q[0];
        if (q[0] == 1) {
            int a, b;
            cin >> a >> b;
            q.push_back(a);
            q.push_back(b);
        } else {
            int c;
            cin >> c;
            q.push_back(c);
        }
        query.push_back(q);
    }

    vector<set<int>> G(N + 1);

    vector<int> cnt(N + 1, 0);
    int no = N;

    rep(i, Q) {
        if (query[i][0] == 1) {
            int a = query[i][1];
            int b = query[i][2];
            G[a].insert(b);
            G[b].insert(a);
            cnt[a]++;
            cnt[b]++;
            if (cnt[a] == 1) {
                no--;
            }
            if (cnt[b] == 1) {
                no--;
            }
        } else {
            int c = query[i][1];
            if (cnt[c] != 0) {
                no++;
            }
            cnt[c] = 0;
            vector<int> temp(0);
            for (auto g : G[c]) {
                cnt[g]--;
                if (cnt[g] == 0) {
                    no++;
                }
                G[g].erase(c);
                temp.push_back(g);
            }
            for (auto g : temp) G[c].erase(g);
        }
        cout << no << endl;
    }
}