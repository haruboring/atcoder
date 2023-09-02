#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<int, int>> VW(N);
    rep(i, N) cin >> VW[i].second >> VW[i].first;
    vector<int> X(M);
    rep(i, M) cin >> X[i];
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];

    multiset<int> available_boxes;
    rep(i, Q) {
        int l = L[i], r = R[i];
        available_boxes.clear();
        available_boxes.insert(-1);
        available_boxes.insert(10000000);
        rep(j, M) {
            if (j < l - 1 || r - 1 < j) available_boxes.insert(X[j]);
        }

        int all_value = 0;
        int cnt_value = 0;
        sort(all(VW), greater<pair<int, int>>());
        rep(i, N) {
            if (cnt_value == M) break;
            int value = VW[i].first;
            int weight = VW[i].second;
            auto use_box_weight = *available_boxes.lower_bound(weight);
            if (use_box_weight != -1 && use_box_weight != 10000000) {
                all_value += value;
                cnt_value++;
                available_boxes.erase(available_boxes.find(use_box_weight));
            }
        }
        cout << all_value << endl;
    }
}