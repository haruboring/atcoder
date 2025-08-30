#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int Rt, Ct, Ra, Ca;
    cin >> Rt >> Ct >> Ra >> Ca;
    int N, M, L;
    cin >> N >> M >> L;
    debug(L);
    vector<char> S(M);
    vector<int> A(M);
    rep(i, M) cin >> S[i] >> A[i];
    vector<char> T(L);
    debug(L);
    vector<int> B(L);
    debug("kokomade");
    rep(i, L) cin >> T[i] >> B[i];

    debug("ok");

    vector<char> S_, T_;
    vector<int> A_ = A, B_ = B;

    set<int> s;
    int a = 0, b = 0;
    rep(i, M) a += A[i], s.insert(a);
    rep(i, L) b += B[i], s.insert(b);
    rep(i, M - 1) A_[i + 1] += A[i];
    rep(i, L - 1) B_[i + 1] += B[i];
    debug("k");

    int NN = s.size();
    vector<int> time(NN);
    vector<char> SS(NN), TT(NN);
    int i = 0;
    debug(NN);
    for (auto ss : s) {
        time[i] = ss;
        int si = lower_bound(all(A_), ss) - A_.begin();
        int ti = lower_bound(all(B_), ss) - B_.begin();
        if (si == NN) si--;
        if (ti == NN) ti--;
        SS[i] = S[si], TT[i] = T[ti];
        i++;
    }

    rep(i, NN - 1) {
        time[NN - 1 - i] -= time[NN - 2 - i];
    }

    // rep(i, NN) cout << time[i] << " " << SS[i] << " " << TT[i] << " "<< endl;

    map<int, pair<int, int>> m;
    m['U'] = {-1, 0}, m['D'] = {1, 0}, m['L'] = {0, -1}, m['R'] = {0, 1};

    // debug(SS.size());
    // debug(TT.size());
    int cnt = 0;
    rep(i, NN) {
        auto [rt, ct] = m[SS[i]];
        auto [ra, ca] = m[TT[i]];
        int t_ = time[i];
        // debug(t_);
        if (SS[i] == TT[i]) {
            // onazihoukouint Rt, Ct, Ra, Ca;
            if (Rt == Ct && Ra == Ca) cnt += t_;
        } else if (rt * ra == -1) {
            // 向かい合うor離れ合う 縦
            if ((Ct == Ca) && ((Rt - Ra) * (rt - ra) < 0) && abs(Rt - Ra) % 2 == 0 && abs(Rt - Ra) != 0) cnt++;
        } else if (ct * ca == -1) {
            // 向かい合うor離れ合う 横
            if ((Rt == Ra) && (Ct - Ca) * (ct - ca) < 0 && abs(Ct - Ca) % 2 == 0 && abs(Ct - Ca) != 0) cnt++;
        } else if (abs(rt + ra) == 1 && abs(ct + ca) == 1) {
            // クロス
            int t = abs(Ct - Rt);
            if ((t != 0) && (t <= t_) && (Rt + t * rt == Ra + t * ra) && (Ct + t * ct == Ca + t * ca)) cnt++;
        }

        Rt += rt * t_, Ct += ct * t_, Ra += ra * t_, Ca += ca * t_;
        // debug(i);
    }
    cout << cnt << endl;
}
