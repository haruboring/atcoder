#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> PCF(N, vector<int>(2));
    rep(i, N) {
        cin >> PCF[i][0] >> PCF[i][1];
        rep(j, PCF[i][1]) {
            int f;
            cin >> f;
            PCF[i].push_back(f);
        }
    }
    sort(all(PCF));
    reverse(all(PCF));
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (PCF[i][0] < PCF[j][0]) continue;
            set<int> fncs_i;
            rep(k, PCF[i].size() - 2) {
                fncs_i.insert(PCF[i][2 + k]);
            }
            set<int> fncs_j;
            rep(k, PCF[j].size() - 2) {
                fncs_j.insert(PCF[j][2 + k]);
            }

            bool a = true;
            for (int k = 2; k < PCF[i].size(); k++) {
                if (fncs_j.count(PCF[i][k]) == 0) {
                    a = false;
                    break;
                }
            }
            if (!a) continue;

            int cnt = 0;
            for (int k = 2; k < PCF[j].size(); k++) {
                if (fncs_i.count(PCF[j][k]) == 0) {
                    cnt++;
                }
            }

            if (PCF[i][0] > PCF[j][0]) {
                cout << "Yes" << endl;
                return 0;
            }
            if (cnt > 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}