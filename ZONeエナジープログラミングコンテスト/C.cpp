// #include "atcoder/all"
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
    vector<int> A(N), B(N), C(N), D(N), E(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];

    vector<pair<int, int>> Ai(N), Bi(N), Ci(N), Di(N), Ei(N);
    rep(i, N) {
        Ai[i] = make_pair(A[i], i);
        Bi[i] = make_pair(B[i], i);
        Ci[i] = make_pair(C[i], i);
        Di[i] = make_pair(D[i], i);
        Ei[i] = make_pair(E[i], i);
    }

    sort(all(Ai));
    sort(all(Bi));
    sort(all(Ci));
    sort(all(Di));
    sort(all(Ei));

    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;

        set<int> stA, stB, stC, stD, stE;
        rep(i, N) {
            if (Ai[i].first < m) stA.insert(Ai[i].second);
            if (Bi[i].first < m) stB.insert(Bi[i].second);
            if (Ci[i].first < m) stC.insert(Ci[i].second);
            if (Di[i].first < m) stD.insert(Di[i].second);
            if (Ei[i].first < m) stE.insert(Ei[i].second);
        }

        set<int> stAandB, stAandC, stAandD, stAandE, stBandC, stBandD, stBandE, stCandD, stCandE, stDandE;
        set_intersection(all(stA), all(stB), inserter(stAandB, stAandB.end()));
        set_intersection(all(stA), all(stC), inserter(stAandC, stAandC.end()));
        set_intersection(all(stA), all(stD), inserter(stAandD, stAandD.end()));
        set_intersection(all(stA), all(stE), inserter(stAandE, stAandE.end()));
        set_intersection(all(stB), all(stC), inserter(stBandC, stBandC.end()));
        set_intersection(all(stB), all(stD), inserter(stBandD, stBandD.end()));
        set_intersection(all(stB), all(stE), inserter(stBandE, stBandE.end()));
        set_intersection(all(stC), all(stD), inserter(stCandD, stCandD.end()));
        set_intersection(all(stC), all(stE), inserter(stCandE, stCandE.end()));
        set_intersection(all(stD), all(stE), inserter(stDandE, stDandE.end()));
        set<int> stAandBandC, stAandBandD, stAandBandE, stAandCandD, stAandCandE, stAandDandE, stBandCandD, stBandCandE, stBandDandE, stCandDandE;
        set_intersection(all(stAandB), all(stC), inserter(stAandBandC, stAandBandC.end()));
        set_intersection(all(stAandB), all(stD), inserter(stAandBandD, stAandBandD.end()));
        set_intersection(all(stAandB), all(stE), inserter(stAandBandE, stAandBandE.end()));
        set_intersection(all(stAandC), all(stD), inserter(stAandCandD, stAandCandD.end()));
        set_intersection(all(stAandC), all(stE), inserter(stAandCandE, stAandCandE.end()));
        set_intersection(all(stAandD), all(stE), inserter(stAandDandE, stAandDandE.end()));
        set_intersection(all(stBandC), all(stD), inserter(stBandCandD, stBandCandD.end()));
        set_intersection(all(stBandC), all(stE), inserter(stBandCandE, stBandCandE.end()));
        set_intersection(all(stBandD), all(stE), inserter(stBandDandE, stBandDandE.end()));
        set_intersection(all(stCandD), all(stE), inserter(stCandDandE, stCandDandE.end()));
        set<int> stAandBandCandD, stAandBandCandE, stAandBandDandE, stAandCandDandE, stBandCandDandE;
        set_intersection(all(stAandBandC), all(stD), inserter(stAandBandCandD, stAandBandCandD.end()));
        set_intersection(all(stAandBandC), all(stE), inserter(stAandBandCandE, stAandBandCandE.end()));
        set_intersection(all(stAandBandD), all(stE), inserter(stAandBandDandE, stAandBandDandE.end()));
        set_intersection(all(stAandCandD), all(stE), inserter(stAandCandDandE, stAandCandDandE.end()));
        set_intersection(all(stBandCandD), all(stE), inserter(stBandCandDandE, stBandCandDandE.end()));
        set<int> stAandBandCandDandE;
        set_intersection(all(stAandBandCandD), all(stE), inserter(stAandBandCandDandE, stAandBandCandDandE.end()));

        int stA_size = stA.size(), stB_size = stB.size(), stC_size = stC.size(), stD_size = stD.size(), stE_size = stE.size();
        int stAandB_size = stAandB.size(), stAandC_size = stAandC.size(), stAandD_size = stAandD.size(), stAandE_size = stAandE.size(), stBandC_size = stBandC.size(), stBandD_size = stBandD.size(), stBandE_size = stBandE.size(), stCandD_size = stCandD.size(), stCandE_size = stCandE.size(), stDandE_size = stDandE.size();
        int stAandBandC_size = stAandBandC.size(), stAandBandD_size = stAandBandD.size(), stAandBandE_size = stAandBandE.size(), stAandCandD_size = stAandCandD.size(), stAandCandE_size = stAandCandE.size(), stAandDandE_size = stAandDandE.size(), stBandCandD_size = stBandCandD.size(), stBandCandE_size = stBandCandE.size(), stBandDandE_size = stBandDandE.size(), stCandDandE_size = stCandDandE.size();
        int stAandBandCandD_size = stAandBandCandD.size(), stAandBandCandE_size = stAandBandCandE.size(), stAandBandDandE_size = stAandBandDandE.size(), stAandCandDandE_size = stAandCandDandE.size(), stBandCandDandE_size = stBandCandDandE.size();
        int stAandBandCandDandE_size = stAandBandCandDandE.size();

        int bad_count = 0;
        bad_count += stA_size * (stA_size - 1) * (stA_size - 2) / 6;
        bad_count += stB_size * (stB_size - 1) * (stB_size - 2) / 6;
        bad_count += stC_size * (stC_size - 1) * (stC_size - 2) / 6;
        bad_count += stD_size * (stD_size - 1) * (stD_size - 2) / 6;
        bad_count += stE_size * (stE_size - 1) * (stE_size - 2) / 6;
        bad_count -= stAandB_size * (stAandB_size - 1) * (stAandB_size - 2) / 6;
        bad_count -= stAandC_size * (stAandC_size - 1) * (stAandC_size - 2) / 6;
        bad_count -= stAandD_size * (stAandD_size - 1) * (stAandD_size - 2) / 6;
        bad_count -= stAandE_size * (stAandE_size - 1) * (stAandE_size - 2) / 6;
        bad_count -= stBandC_size * (stBandC_size - 1) * (stBandC_size - 2) / 6;
        bad_count -= stBandD_size * (stBandD_size - 1) * (stBandD_size - 2) / 6;
        bad_count -= stBandE_size * (stBandE_size - 1) * (stBandE_size - 2) / 6;
        bad_count -= stCandD_size * (stCandD_size - 1) * (stCandD_size - 2) / 6;
        bad_count -= stCandE_size * (stCandE_size - 1) * (stCandE_size - 2) / 6;
        bad_count -= stDandE_size * (stDandE_size - 1) * (stDandE_size - 2) / 6;
        bad_count += stAandBandC_size * (stAandBandC_size - 1) * (stAandBandC_size - 2) / 6;
        bad_count += stAandBandD_size * (stAandBandD_size - 1) * (stAandBandD_size - 2) / 6;
        bad_count += stAandBandE_size * (stAandBandE_size - 1) * (stAandBandE_size - 2) / 6;
        bad_count += stAandCandD_size * (stAandCandD_size - 1) * (stAandCandD_size - 2) / 6;
        bad_count += stAandCandE_size * (stAandCandE_size - 1) * (stAandCandE_size - 2) / 6;
        bad_count += stAandDandE_size * (stAandDandE_size - 1) * (stAandDandE_size - 2) / 6;
        bad_count += stBandCandD_size * (stBandCandD_size - 1) * (stBandCandD_size - 2) / 6;
        bad_count += stBandCandE_size * (stBandCandE_size - 1) * (stBandCandE_size - 2) / 6;
        bad_count += stBandDandE_size * (stBandDandE_size - 1) * (stBandDandE_size - 2) / 6;
        bad_count += stCandDandE_size * (stCandDandE_size - 1) * (stCandDandE_size - 2) / 6;
        bad_count -= stAandBandCandD_size * (stAandBandCandD_size - 1) * (stAandBandCandD_size - 2) / 6;
        bad_count -= stAandBandCandE_size * (stAandBandCandE_size - 1) * (stAandBandCandE_size - 2) / 6;
        bad_count -= stAandBandDandE_size * (stAandBandDandE_size - 1) * (stAandBandDandE_size - 2) / 6;
        bad_count -= stAandCandDandE_size * (stAandCandDandE_size - 1) * (stAandCandDandE_size - 2) / 6;
        bad_count -= stBandCandDandE_size * (stBandCandDandE_size - 1) * (stBandCandDandE_size - 2) / 6;
        bad_count += stAandBandCandDandE_size * (stAandBandCandDandE_size - 1) * (stAandBandCandDandE_size - 2) / 6;

        if (N * (N - 1) * (N - 2) / 6 - bad_count >= 1) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}