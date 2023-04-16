#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<set<int>> number_in_box(N + 1);
    map<pair<int, int>, int> dup_number_in_box;
    map<int, set<int>> box_include_number;
    rep(_, Q) {
        int flag, i, j;
        cin >> flag;
        if (flag == 1) {
            cin >> i >> j;
            number_in_box[j].insert(i);
            dup_number_in_box[make_pair(j, i)]++;
            box_include_number[i].insert(j);
        } else if (flag == 2) {
            cin >> i;
            for (auto a : number_in_box[i]) {
                rep(k, dup_number_in_box[make_pair(i, a)]) {
                    cout << a << " ";
                }
            }
            cout << endl;
        } else {
            cin >> i;
            for (auto kk : box_include_number[i]) {
                cout << kk << " ";
            }
            cout << endl;
        }
    }
}
