#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    vector<vector<int>> C(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> C[i][j];

    set<vector<int>> st1, st2, st3, st4, st5, st6, st7, st8;
    if (C[0][0] == C[0][1]) {
        st1.insert({0, 1});
        st1.insert({1, 0});
    }
    if (C[0][1] == C[0][2]) {
        st1.insert({1, 2});
        st1.insert({2, 1});
    }
    if (C[0][0] == C[0][2]) {
        st1.insert({0, 2});
        st1.insert({2, 0});
    }

    if (C[1][0] == C[1][1]) {
        st2.insert({3, 4});
        st2.insert({4, 3});
    }
    if (C[1][1] == C[1][2]) {
        st2.insert({4, 5});
        st2.insert({5, 4});
    }
    if (C[1][0] == C[1][2]) {
        st2.insert({3, 5});
        st2.insert({5, 3});
    }

    if (C[2][0] == C[2][1]) {
        st3.insert({6, 7});
        st3.insert({7, 6});
    }
    if (C[2][1] == C[2][2]) {
        st3.insert({7, 8});
        st3.insert({8, 7});
    }
    if (C[2][0] == C[2][2]) {
        st3.insert({6, 8});
        st3.insert({8, 6});
    }

    if (C[0][0] == C[1][0]) {
        st4.insert({0, 3});
        st4.insert({3, 0});
    }
    if (C[1][0] == C[2][0]) {
        st4.insert({3, 6});
        st4.insert({6, 3});
    }
    if (C[0][0] == C[2][0]) {
        st4.insert({0, 6});
        st4.insert({6, 0});
    }

    if (C[0][1] == C[1][1]) {
        st5.insert({1, 4});
        st5.insert({4, 1});
    }
    if (C[1][1] == C[2][1]) {
        st5.insert({4, 7});
        st5.insert({7, 4});
    }
    if (C[0][1] == C[2][1]) {
        st5.insert({1, 7});
        st5.insert({7, 1});
    }

    if (C[0][2] == C[1][2]) {
        st6.insert({2, 5});
        st6.insert({5, 2});
    }
    if (C[1][2] == C[2][2]) {
        st6.insert({5, 8});
        st6.insert({8, 5});
    }
    if (C[0][2] == C[2][2]) {
        st6.insert({2, 8});
        st6.insert({8, 2});
    }

    if (C[0][0] == C[1][1]) {
        st7.insert({0, 4});
        st7.insert({4, 0});
    }
    if (C[1][1] == C[2][2]) {
        st7.insert({4, 8});
        st7.insert({8, 4});
    }
    if (C[0][0] == C[2][2]) {
        st7.insert({0, 8});
        st7.insert({8, 0});
    }

    if (C[0][2] == C[1][1]) {
        st8.insert({2, 4});
        st8.insert({4, 2});
    }
    if (C[1][1] == C[2][0]) {
        st8.insert({4, 6});
        st8.insert({6, 4});
    }
    if (C[0][2] == C[2][0]) {
        st8.insert({2, 6});
        st8.insert({6, 2});
    }

    vector<int> order = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int cnt = 0;
    int all = 0;
    do {
        vector<int> tmp_st1(0), tmp_st2(0), tmp_st3(0), tmp_st4(0), tmp_st5(0), tmp_st6(0), tmp_st7(0), tmp_st8(0);
        for (int ij : order) {
            int i = ij / 3;
            int j = ij % 3;
            if (i == 0) tmp_st1.push_back(i * 3 + j);
            if (i == 1) tmp_st2.push_back(i * 3 + j);
            if (i == 2) tmp_st3.push_back(i * 3 + j);
            if (j == 0) tmp_st4.push_back(i * 3 + j);
            if (j == 1) tmp_st5.push_back(i * 3 + j);
            if (j == 2) tmp_st6.push_back(i * 3 + j);
            if (i == j) tmp_st7.push_back(i * 3 + j);
            if (i + j == 2) tmp_st8.push_back(i * 3 + j);
        }

        vector<int> tmp1(0), tmp2(0), tmp3(0), tmp4(0), tmp5(0), tmp6(0), tmp7(0), tmp8(0);
        for (auto i : {0, 1}) {
            tmp1.push_back(tmp_st1[i]);
            tmp2.push_back(tmp_st2[i]);
            tmp3.push_back(tmp_st3[i]);
            tmp4.push_back(tmp_st4[i]);
            tmp5.push_back(tmp_st5[i]);
            tmp6.push_back(tmp_st6[i]);
            tmp7.push_back(tmp_st7[i]);
            tmp8.push_back(tmp_st8[i]);
        }

        if ((st1.count(tmp1) && tmp_st1[1] !=tmp_st1[2]) || (st2.count(tmp2) && tmp_st2[1] !=tmp_st2[2]) || (st3.count(tmp3) && tmp_st3[1] !=tmp_st3[2]) || (st4.count(tmp4) && tmp_st4[1] !=tmp_st4[2]) || (st5.count(tmp5) && tmp_st5[1] !=tmp_st5[2]) || (st6.count(tmp6) && tmp_st6[1] !=tmp_st6[2]) || (st7.count(tmp7) && tmp_st7[1] !=tmp_st7[2]) || (st8.count(tmp8) && tmp_st7[1] !=tmp_st7[2])) {
            cnt++;
        }
        all++;
    } while (next_permutation(all(order)));

    double ch = all - cnt;
    double pa = all;

    debug(cnt);
    debug(all);

    cout << fixed << setprecision(10) << ch / pa << endl;
}

// 3 6 7
// 1 9 7
// 5 7 5
// cnt: 217728
// all: 362880