#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<pair<int, int>> adjacent = {make_pair(1, 1), make_pair(0, 1), make_pair(1, 0), make_pair(-1, -1), make_pair(0, -1), make_pair(-1, 0)};

set<pair<int, int>> XY, visited_XY;

void visit(int x, int y) {
    visited_XY.insert(make_pair(x, y));
    rep(i, 6) {
        pair<int, int> adjacent_XY = make_pair(x + adjacent[i].first, y + adjacent[i].second);
        if (XY.count(adjacent_XY) && visited_XY.count(adjacent_XY) == 0) {
            visit(adjacent_XY.first, adjacent_XY.second);
        }
    }
}

int main() {
    int N;
    cin >> N;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        pair<int, int> xy = make_pair(x, y);
        XY.insert(xy);
    }
    ll cnt = 0;
    for (auto xy : XY) {
        if (visited_XY.count(xy) == 0) {
            visit(xy.first, xy.second);
            cnt++;
        }
    }
    cout << cnt << endl;
}