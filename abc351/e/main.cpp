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
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    int dist_sum = 0;
    vector<int> cX(0), cY(0);
    rep(i, N) {
        int x = X[i], y = Y[i];
        if ((x + y) % 2 == 0) continue;
        cX.push_back(x + y);
        cY.push_back(x - y);
    }
    if (cX.size() != 0) {
        sort(all(cX));
        sort(all(cY));
        vector<int> sumX(cX.size()), sumY(cX.size());
        sumX[0] = cX[0];
        sumY[0] = cY[0];
        repp(i, 1, cX.size()) {
            sumX[i] = sumX[i - 1] + cX[i];
            sumY[i] = sumY[i - 1] + cY[i];
        }
        rep(i, cX.size()) {
            int idx = lower_bound(all(cX), cX[i]) - cX.begin();
            dist_sum += (sumX[cX.size() - 1] - sumX[idx]) - (cX.size() - idx - 1) * cX[i] + (idx + 1) * cX[i] - sumX[idx];
        }

        rep(i, cX.size()) {
            int idx = lower_bound(all(cY), cY[i]) - cY.begin();
            dist_sum += (sumY[cX.size() - 1] - sumY[idx]) - (cX.size() - idx - 1) * cY[i] + (idx + 1) * cY[i] - sumY[idx];
        }
    }

    vector<int> cX1(0), cY1(0);
    rep(i, N) {
        int x = X[i], y = Y[i];
        if ((x + y) % 2 == 1) continue;
        cX1.push_back(x + y);
        cY1.push_back(x - y);
    }
    if (cX1.size() != 0) {
        sort(all(cX1));
        sort(all(cY1));
        vector<int> sumX1(cX1.size()), sumY1(cX1.size());
        sumX1[0] = cX1[0];
        sumY1[0] = cY1[0];
        repp(i, 1, cX1.size()) {
            sumX1[i] = sumX1[i - 1] + cX1[i];
            sumY1[i] = sumY1[i - 1] + cY1[i];
        }
        rep(i, cX1.size()) {
            int idx = lower_bound(all(cX1), cX1[i]) - cX1.begin();
            dist_sum += (sumX1[cX1.size() - 1] - sumX1[idx]) - (cX1.size() - idx - 1) * cX1[i] + (idx + 1) * cX1[i] - sumX1[idx];
        }

        rep(i, cX1.size()) {
            int idx = lower_bound(all(cY1), cY1[i]) - cY1.begin();
            dist_sum += (sumY1[cX1.size() - 1] - sumY1[idx]) - (cX1.size() - idx - 1) * cY1[i] + (idx + 1) * cY1[i] - sumY1[idx];
        }
    }

    cout << dist_sum / 4 << endl;
}
