#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<tuple<int, int, int>> txy(N);
    rep(i, N) {
        int t, x, y;
        cin >> t >> x >> y;
        txy[i] = make_tuple(t, x, y);
    }
    bool can_travel = true;
    sort(all(txy));
    int x = 0, y = 0, t = 0;
    rep(i, N) {
        int dis_x = abs(x - get<1>(txy[i]));
        int dis_y = abs(y - get<2>(txy[i]));
        int travel_time = get<0>(txy[i]) - t;

        if ((travel_time - (dis_x + dis_y)) % 2 == 1) {
            can_travel = false;
        }

        if (travel_time - (dis_x + dis_y) < 0) {
            can_travel = false;
        }
        t = get<0>(txy[i]);
        x = get<1>(txy[i]);
        y = get<2>(txy[i]);
    }
    if (can_travel) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}