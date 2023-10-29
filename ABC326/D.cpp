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
    string R, C;
    cin >> R >> C;

    if (N == 3) {
        vector<vector<char>> A(3, vector<char>(3));

        vector<vector<char>> B(3, vector<char>(0));

        rep(i, 3) {
            set<char> st = {'A', 'B', 'C'};
            A[i][0] = R[i];
            st.erase(R[i]);

            B[i].push_back(*st.begin());
            st.erase(st.begin());
            B[i].push_back(*st.begin());
            st.erase(st.begin());
        }

        rep(rev, 1 << 3) {
            bitset<3> bs(rev);
            rep(i, 3) {
                if (bs[i]) {
                    A[i][1] = B[i][1];
                    A[i][2] = B[i][0];
                } else {
                    A[i][1] = B[i][0];
                    A[i][2] = B[i][1];
                }
            }

            bool ok = true;
            rep(i, 3) {
                set<char> st;
                rep(j, 3) {
                    st.insert(A[j][i]);
                }
                if (st.size() != 3) ok = false;
            }
            rep(i, 3) {
                rep(j, 3) {
                    if (C[i] != A[j][i]) ok = false;
                    break;
                }
            }

            if (ok) {
                cout << "Yes" << endl;
                rep(i, 3) {
                    rep(j, 3) {
                        cout << A[i][j];
                    }
                    cout << endl;
                }
                return 0;
            }
        }

        cout << "No" << endl;
    }
    if (N == 4) {
        vector<vector<char>> A(N, vector<char>(3));

        vector<vector<char>> B(N, vector<char>(0));
        rep(i, N) {
            set<char> st = {'A', 'B', 'C'};
            A[i][0] = R[i];
            st.erase(R[i]);

            B[i].push_back(*st.begin());
            st.erase(st.begin());
            B[i].push_back(*st.begin());
            st.erase(st.begin());
        }

        rep(rev, 1 << 4) {
            bitset<4> bs(rev);
            rep(i, 4) {
                if (bs[i]) {
                    A[i][1] = B[i][1];
                    A[i][2] = B[i][0];
                } else {
                    A[i][1] = B[i][0];
                    A[i][2] = B[i][1];
                }
            }
            vector<int> es = {0, 1, 2, 3};
            do {
                vector<vector<char>> AA(4, vector<char>(4));
                rep(i, 4) {
                    int cnt = 0;
                    rep(j, 4) {
                        if (es[i] == j) {
                            cnt++;
                            AA[i][j] = '.';
                        } else {
                            AA[i][j] = A[i][j - cnt];
                        }
                    }
                }

                bool ok = true;

                rep(i, 4) {
                    set<char> st;
                    rep(j, 4) {
                        st.insert(AA[j][i]);
                    }
                    if (st.size() != 4) ok = false;
                }
                rep(i, 4) {
                    rep(j, 4) {
                        if (AA[j][i] == '.') continue;
                        if (AA[j][i] != C[i]) ok = false;
                        break;
                    }
                }

                if (ok) {
                    cout << "Yes" << endl;
                    rep(i, 4) {
                        rep(j, 4) {
                            cout << AA[i][j];
                        }
                        cout << endl;
                    }
                    return 0;
                }
            } while (next_permutation(all(es)));
        }
        cout << "No" << endl;
    }
    if (N == 5) {
        vector<vector<char>> A(5, vector<char>(3));

        vector<vector<char>> B(5, vector<char>(0));

        rep(i, 5) {
            set<char> st = {'A', 'B', 'C'};
            A[i][0] = R[i];
            st.erase(R[i]);

            B[i].push_back(*st.begin());
            st.erase(st.begin());
            B[i].push_back(*st.begin());
            st.erase(st.begin());
        }

        rep(rev, 1 << 5) {
            bitset<5> bs(rev);
            rep(i, 5) {
                if (bs[i]) {
                    A[i][1] = B[i][1];
                    A[i][2] = B[i][0];
                } else {
                    A[i][1] = B[i][0];
                    A[i][2] = B[i][1];
                }
            }

            vector<int> es = {0, 1, 2, 3, 4};
            do {
                vector<int> es1 = {0, 1, 2, 3, 4};
                do {
                    bool cn = false;
                    rep(i, 5) {
                        if (es[i] == es1[i]) cn = true;
                    }
                    if (cn) continue;

                    vector<vector<char>> AA(5, vector<char>(5));
                    rep(i, 5) {
                        int cnt = 0;
                        rep(j, 5) {
                            if (es[i] == j || es1[i] == j) {
                                cnt++;
                                AA[i][j] = '.';
                            } else {
                                AA[i][j] = A[i][j - cnt];
                            }
                        }
                    }

                    bool ok = true;
                    rep(i, 5) {
                        set<char> st;
                        int cnt_d = 0;
                        rep(j, 5) {
                            if (AA[j][i] == '.') cnt_d++;
                            st.insert(AA[j][i]);
                        }
                        if (st.size() != 4 || cnt_d != 2) ok = false;
                    }
                    rep(i, 5) {
                        rep(j, 5) {
                            if (AA[j][i] == '.') continue;
                            if (AA[j][i] != C[i]) ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        cout << "Yes" << endl;
                        rep(i, 5) {
                            rep(j, 5) {
                                cout << AA[i][j];
                            }
                            cout << endl;
                        }
                        return 0;
                    }
                } while (next_permutation(all(es1)));
            } while (next_permutation(all(es)));
        }
        cout << "No" << endl;
    }
}
