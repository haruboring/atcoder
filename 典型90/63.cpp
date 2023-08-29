#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int comb(int a, int b) {
    if (a < b) swap(a, b);

    int ans = 1;

    for (int i = a; i > a - b; i--) ans *= i;
    for (int i = 1; i <= b; i++) ans /= i;

    return ans;
}
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> P[i][j];

    int ans = -1;
    map<int, int> mp;

    rep(i, H) {
        mp.clear();
        vector<int> row(0);
        row.push_back(i);
        rep(j, W) {
            set<int> st;
            for (auto r : row) {
                st.insert(P[r][j]);
            }
            if (st.size() == 1) {
                mp[*st.begin()]++;
            }
        }
        for (auto m : mp) {
            ans = max(ans, m.second);
        }
    }
    debug(ans);

    rep(i, H - 1) {
        repp(j, i + 1, H) {
            mp.clear();
            vector<int> row(0);
            row.push_back(i);
            row.push_back(j);
            rep(k, W) {
                set<int> st;
                for (auto r : row) {
                    st.insert(P[r][k]);
                }
                if (st.size() == 1) {
                    mp[*st.begin()]++;
                }
            }
            for (auto m : mp) {
                ans = max(ans, 2 * m.second);
            }
        }
    }
    debug(ans);

    rep(i, H - 2) {
        repp(j, i + 1, H - 1) {
            repp(k, j + 1, H) {
                mp.clear();
                vector<int> row(0);
                row.push_back(i);
                row.push_back(j);
                row.push_back(k);
                rep(l, W) {
                    set<int> st;
                    for (auto r : row) {
                        st.insert(P[r][l]);
                    }
                    if (st.size() == 1) {
                        mp[*st.begin()]++;
                    }
                }
                for (auto m : mp) {
                    ans = max(ans, 3 * m.second);
                }
            }
        }
    }
    debug(ans);

    rep(i, H - 3) {
        repp(j, i + 1, H - 2) {
            repp(k, j + 1, H - 1) {
                repp(l, k + 1, H) {
                    mp.clear();
                    vector<int> row(0);
                    row.push_back(i);
                    row.push_back(j);
                    row.push_back(k);
                    row.push_back(l);
                    rep(m, W) {
                        set<int> st;
                        for (auto r : row) {
                            st.insert(P[r][m]);
                        }
                        if (st.size() == 1) {
                            mp[*st.begin()]++;
                        }
                    }
                    for (auto m : mp) {
                        ans = max(ans, 4 * m.second);
                    }
                }
            }
        }
    }
    debug(ans);

    rep(i, H - 4) {
        repp(j, i + 1, H - 3) {
            repp(k, j + 1, H - 2) {
                repp(l, k + 1, H - 1) {
                    repp(m, l + 1, H) {
                        mp.clear();
                        vector<int> row(0);
                        row.push_back(i);
                        row.push_back(j);
                        row.push_back(k);
                        row.push_back(l);
                        row.push_back(m);
                        rep(n, W) {
                            set<int> st;
                            for (auto r : row) {
                                st.insert(P[r][n]);
                            }
                            if (st.size() == 1) {
                                mp[*st.begin()]++;
                            }
                        }
                        for (auto m : mp) {
                            ans = max(ans, 5 * m.second);
                        }
                    }
                }
            }
        }
    }
    debug(ans);

    rep(i, H - 5) {
        repp(j, i + 1, H - 4) {
            repp(k, j + 1, H - 3) {
                repp(l, k + 1, H - 2) {
                    repp(m, l + 1, H - 1) {
                        repp(n, m + 1, H) {
                            mp.clear();
                            vector<int> row(0);
                            row.push_back(i);
                            row.push_back(j);
                            row.push_back(k);
                            row.push_back(l);
                            row.push_back(m);
                            row.push_back(n);
                            rep(o, W) {
                                set<int> st;
                                for (auto r : row) {
                                    st.insert(P[r][o]);
                                }
                                if (st.size() == 1) {
                                    mp[*st.begin()]++;
                                }
                            }
                            for (auto m : mp) {
                                ans = max(ans, 6 * m.second);
                            }
                        }
                    }
                }
            }
        }
    }
    debug(ans);

    rep(i, H - 6) {
        repp(j, i + 1, H - 5) {
            repp(k, j + 1, H - 4) {
                repp(l, k + 1, H - 3) {
                    repp(m, l + 1, H - 2) {
                        repp(n, m + 1, H - 1) {
                            repp(o, n + 1, H) {
                                mp.clear();
                                vector<int> row(0);
                                row.push_back(i);
                                row.push_back(j);
                                row.push_back(k);
                                row.push_back(l);
                                row.push_back(m);
                                row.push_back(n);
                                row.push_back(o);
                                rep(p, W) {
                                    set<int> st;
                                    for (auto r : row) {
                                        st.insert(P[r][p]);
                                    }
                                    if (st.size() == 1) {
                                        mp[*st.begin()]++;
                                    }
                                }
                                for (auto m : mp) {
                                    ans = max(ans, 7 * m.second);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    debug(ans);

    rep(i, H - 7) {
        repp(j, i + 1, H - 6) {
            repp(k, j + 1, H - 5) {
                repp(l, k + 1, H - 4) {
                    repp(m, l + 1, H - 3) {
                        repp(n, m + 1, H - 2) {
                            repp(o, n + 1, H - 1) {
                                repp(p, o + 1, H) {
                                    mp.clear();
                                    vector<int> row(0);
                                    row.push_back(i);
                                    row.push_back(j);
                                    row.push_back(k);
                                    row.push_back(l);
                                    row.push_back(m);
                                    row.push_back(n);
                                    row.push_back(o);
                                    row.push_back(p);
                                    rep(q, W) {
                                        set<int> st;
                                        for (auto r : row) {
                                            st.insert(P[r][q]);
                                        }
                                        if (st.size() == 1) {
                                            mp[*st.begin()]++;
                                        }
                                    }
                                    for (auto m : mp) {
                                        ans = max(ans, 8 * m.second);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    debug(ans);

    cout << ans << endl;
}
