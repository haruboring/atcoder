#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<int>> G(N, vector<int>()), rG(N, vector<int>());
    rep(i, N) G[i].push_back(A[i] - 1);
    rep(i, N) rG[A[i] - 1].push_back(i);

    vector<int> score(N, 0);
    vector<int> visited(N, 0);
    rep(i, N) {
        int now = i;
        set<int> loop;
        loop.insert(now);
        if (visited[now] != 0) continue;
        visited[now] = 1;
        int r = 1;
        while (1) {
            int next = G[now][0];

            if (loop.count(next)) {
                int rnow = next;
                while (1) {
                    score[rnow] = visited[now] - visited[next] + 1;
                    rnow = G[rnow][0];
                    if (rnow == next) break;
                }
            }
            if (visited[next] != 0) break;
            visited[next] = visited[now] + 1;
            now = next;
            loop.insert(now);
        }
    }

    queue<int> q;
    rep(i, N) if (score[i] != 0) q.push(i);
    while (!q.empty()) {
        int now = q.front();
        debug(now);
        q.pop();
        for (auto next : rG[now]) {
            if (score[next] != 0) continue;
            score[next] = score[now] + 1;
            q.push(next);
        }
    }

    cout << accumulate(all(score), 0LL) << endl;
}
