#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> par(200'000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (ry < rx) swap(rx, ry);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

template <class T>
void dfs_combination(vector<T> &arr, int idx, int r, vector<T> &pattern, vector<vector<T>> &result) {
    if (r == 0) {
        result.push_back(pattern);
        return;
    }
    if ((idx + r) > arr.size()) {
        return;
    }

    // select
    pattern.push_back(arr[idx]);
    dfs_combination(arr, idx + 1, r - 1, pattern, result);
    pattern.pop_back();
    // not select
    dfs_combination(arr, idx + 1, r, pattern, result);
}
template <class T>
vector<vector<T>> combination(vector<T> &arr, int r) {
    if (arr.size() < r) {
        printf("combination ERROR: r is larger than arr.size()\n");
        exit(1);
    }

    vector<T> pattern;
    vector<vector<T>> result;
    dfs_combination(arr, 0, r, pattern, result);
    return result;
}

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];

    vector<vector<pair<int, int>>> G(N);
    rep(i, M) {
        A[i]--;
        B[i]--;
        G[A[i]].push_back(make_pair(B[i], -C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }

    init(N);
    rep(i, N) {
        for (auto [j, c] : G[i]) {
            unite(i, j);
        }
    }

    map<int, set<int>> mp;
    rep(i, N) {
        mp[root(i)].insert(i);
    }

    set<int> dep;
    for (auto [c, s] : mp) {
        if (s.size() == 1) {
            dep.insert(*s.begin());
        }
    }

    map<int, int> first;
    rep(i, N) {
        if (!dep.count(i)) {
            first[root(i)] = i;
        }
    }

    if (dep.size() == 1) {
        first[root(*dep.begin())] = *dep.begin();
        dep.clear();
    }

    set<int> fs;
    for (auto [c, s] : first) fs.insert(s);
    debug(fs.size());

    vector<int> orders(0);
    rep(i, N) orders.push_back(i);
    vector<vector<int>> combs = combination(orders, first.size());
    debug(combs.size());

    map<int, set<int>> mp2;
    rep(i, combs.size()) {
        do {
            vector<int> num(N, -1);
            int tmp = 0;
            queue<pair<int, int>> q;
            for (auto x : fs) {
                num[x] = combs[i][tmp];
                q.push(make_pair(x, combs[i][tmp]));
                tmp++;
            }

            bool ok = true;

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [j, c] : G[x]) {
                    if (num[j] == -1) {
                        num[j] = y + c;
                        if (y + c < 0 || y + c >= N) {
                            ok = false;
                            break;
                        }
                        q.push(make_pair(j, y + c));
                    }
                }
            }

            set<int> st;
            int cnt = 0;
            rep(j, N) {
                if (dep.count(j)) continue;
                st.insert(num[j]);
                cnt++;
            }
            if (st.size() != cnt) ok = false;

            if (ok) {
                rep(j, N) {
                    if (dep.count(j)) continue;
                    mp2[j].insert(num[j]);
                }
            }
        } while (next_permutation(all(combs[i])));
    }

    rep(i, N) {
        if (dep.count(i)) {
            cout << -1 << " ";
        } else {
            if (mp2[i].size() == 1) {
                cout << *mp2[i].begin() + 1 << " ";
            } else {
                cout << -1 << " ";
            }
        }
    }

    cout << endl;
}
