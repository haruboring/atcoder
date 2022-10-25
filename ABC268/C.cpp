#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i, N) {
        cin >> p[i];
    }

    vector<int> dis(N);
    rep(i, N) {
        dis[i] = (p[i] - i + N) % N;
    }

    vector<int> dis_cnt(N);
    rep(i, N) {
        dis_cnt[dis[i]]++;
    }

    int max_happy = 0;
    dis_cnt.push_back(dis_cnt[0]);
    dis_cnt.push_back(dis_cnt[1]);
    rep(i, N) {
        max_happy = max(max_happy, dis_cnt[i] + dis_cnt[i + 1] + dis_cnt[i + 2]);
    }

    cout << max_happy << endl;
}