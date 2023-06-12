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

    vector<vector<int>> G(N);
    vector<bool> visited(N, false);
    int pos = 0;
    queue<int> q;
    q.push(0);
    rep(_, 2 * N + 10) {
        visited[pos] = true;
        string k;
        cin >> k;
        if (k == "OK") return 0;
        int ik = stoi(k);
        if (ik == -1) return 0;
        vector<int> v(ik);
        rep(i, ik) cin >> v[i];
        rep(i, ik) v[i]--;

        bool a = false;
        rep(i, ik) {
            if (visited[v[i]] == 0) {
                q.push(v[i]);
                cout << v[i] + 1 << endl;
                a = true;
                break;
            } else {
                q.pop();
            }
        }
        if (a) continue;

        cout << q.front() + 1 << endl;

        q.pop();

        pos = ik - 1;
    }
}