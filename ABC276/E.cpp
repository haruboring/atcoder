#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

map<pair<int, int>, int> m;
int H, W;
int si, sj;
vector<string> C(0);

void search(int i, int j, int cnt, vector<vector<bool>> &b) {
    if (i < 0 || i >= H || j < 0 || j >= W) {
        return;
    }
    if (C[i][j] == '#') {
        return;
    }
    if (i == si && j == sj) {
        m[make_pair(i, j)] = max(m[make_pair(i, j)], cnt);
    }
    if (b[i][j]) {
        return;
    }
    b[i][j] = true;
    pair<int, int> p = make_pair(i, j);
    if (m[p] == 0) {
        m[p] = cnt;
        search(i + 1, j, cnt + 1, b);
        search(i - 1, j, cnt + 1, b);
        search(i, j + 1, cnt + 1, b);
        search(i, j - 1, cnt + 1, b);
    }
}

int main() {
    cin >> H >> W;
    rep(i, H) {
        string cc;
        cin >> cc;
        C.push_back(cc);
    }
    vector<vector<bool>> b(H, vector<bool>(W));
    rep(i, H) {
        rep(j, W) {
            b[i][j] = false;
        }
    }
    rep(i, H) {
        rep(j, W) {
            if (C[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    search(si, sj, 0, b);
    if (m[make_pair(si, sj)] > 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}