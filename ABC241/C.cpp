#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    bool ans = false;

    // 横
    rep(i, N) {
        // 1, 2個目の#によって連続している黒の数
        queue<int> q;
        int cnt = 0;
        rep(j, N) {
            if (S[i][j] == '#') {
                cnt++;
            } else {
                if (q.size() == 2) {
                    int connect1 = q.front();
                    q.pop();
                    cnt -= connect1;
                    int connect2 = q.front();
                    q.pop();
                    q.push(connect2 - connect1);
                }
                cnt++;
                q.push(cnt);
            }
            if (cnt >= 6) {
                ans = true;
            }
        }
    }

    // 縦
    rep(i, N) {
        // 1, 2個目の#によって連続している黒の数
        queue<int> q;
        int cnt = 0;
        rep(j, N) {
            if (S[j][i] == '#') {
                cnt++;
            } else {
                if (q.size() == 2) {
                    int connect1 = q.front();
                    q.pop();
                    cnt -= connect1;
                    int connect2 = q.front();
                    q.pop();
                    q.push(connect2 - connect1);
                }
                cnt++;
                q.push(cnt);
            }
            if (cnt >= 6) {
                ans = true;
            }
        }
    }

    // 斜め（右下がり）
    rep(i, N) {
        // 1, 2個目の#によって連続している黒の数
        queue<int> q;
        int cnt = 0;
        rep(j, N) {
            if (i + j == N) {
                cnt = 0;
                while (!q.empty()) {
                    q.pop();
                }
            }
            if (S[(i + j) % N][j] == '#') {
                cnt++;
            } else {
                if (q.size() == 2) {
                    int connect1 = q.front();
                    q.pop();
                    cnt -= connect1;
                    int connect2 = q.front();
                    q.pop();
                    q.push(connect2 - connect1);
                }
                cnt++;
                q.push(cnt);
            }
            if (cnt >= 6) {
                ans = true;
            }
        }
    }

    // 斜め（右上がり）
    rep(i, N) {
        // 1, 2個目の#によって連続している黒の数
        queue<int> q;
        int cnt = 0;
        rep(j, N) {
            if (i - j == -1) {
                cnt = 0;
                while (!q.empty()) {
                    q.pop();
                }
            }
            if (S[(i - j + N) % N][j] == '#') {
                cnt++;
            } else {
                if (q.size() == 2) {
                    int connect1 = q.front();
                    q.pop();
                    cnt -= connect1;
                    int connect2 = q.front();
                    q.pop();
                    q.push(connect2 - connect1);
                }
                cnt++;
                q.push(cnt);
            }
            if (cnt >= 6) {
                ans = true;
            }
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}