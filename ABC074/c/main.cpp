#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    int sugar = 0, water = 0;
    double max_concentration = 0;
    rep(i, 31) {
        rep(j, 31) {
            int tmp_water = 100 * A * i + 100 * B * j;
            if (tmp_water == 0) continue;
            if (tmp_water > F) break;
            rep(k, 3001) {
                int tmp_sugar = C * k;
                if (100 * tmp_sugar > tmp_water * E) break;
                if (tmp_water + tmp_sugar > F) break;
                int sugar_cap = (tmp_water * E - 100 * tmp_sugar) / 100;
                sugar_cap = min(sugar_cap, F - tmp_water - tmp_sugar);
                int add_sugar = (sugar_cap / D) * D;

                double concentration = (double)(tmp_sugar + add_sugar) / (double)(tmp_water + tmp_sugar + add_sugar);
                if (concentration > max_concentration) {
                    max_concentration = concentration;
                    sugar = tmp_sugar + add_sugar;
                    water = tmp_water;
                }
            }
        }
    }

    if (sugar == 0) {
        cout << A * 100 << " " << 0 << endl;
        return 0;
    }

    cout << water + sugar << " " << sugar << endl;
}
