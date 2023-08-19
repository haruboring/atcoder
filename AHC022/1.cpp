#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

struct Pos {
    int y, x;
};

struct Judge {
    void set_temperature(const vector<vector<int>>& temperature) {
        for (const vector<int>& row : temperature) {
            for (int i = 0; i < row.size(); i++) {
                cout << row[i] << (i == row.size() - 1 ? "\n" : " ");
            }
        }
        cout.flush();
    }

    int measure(int i, int y, int x) {
        cout << i << " " << y << " " << x << endl;  // endl does flush
        int v;
        cin >> v;
        if (v == -1) {
            cerr << "something went wrong. i=" << i << " y=" << y << " x=" << x << endl;
            exit(1);
        }
        return v;
    }

    void answer(const vector<int>& estimate) {
        cout << "-1 -1 -1" << endl;
        for (int e : estimate) {
            cout << e << endl;
        }
    }
};

struct Solver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;

    Solver(int L, int N, int S, const vector<Pos>& landing_pos) : L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    vector<vector<int>> create_temperature() {
        vector<vector<int>> temperature(L, vector<int>(L, -1));
        // set the temperature to i * 10 for i-th position
        for (int i = 0; i < N; i++) {
            // 1000まで。Nは60 ~ 100
            temperature[landing_pos[i].y][landing_pos[i].x] = ((i % 72) * 14);
            if (i >= 72) break;
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (temperature[i][j] == -1) {
                    temperature[i][j] = N * 7;
                }
            }
        }
        return temperature;
    }

    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);
        for (int i_in = 0; i_in < N; i_in++) {
            // you can output comment
            cout << "# measure i=" << i_in << " y=0 x=0" << endl;

            int measured_value = judge.measure(i_in, 0, 0);

            int it = (measured_value + 7) / 14;
            estimate[i_in] = min(max(it, 0), N - 1);
        }
        return estimate;
    }
};

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<Pos> landing_pos(N);
    for (int i = 0; i < N; i++) {
        cin >> landing_pos[i].y >> landing_pos[i].x;
    }

    Solver solver(L, N, S, landing_pos);
    solver.solve();
}

/*
# MEMO

標準偏差について考える必要性がある
g++-13 -std=c++17 -I.. 1.cpp -o tools/a.out && cd tools && cargo run --release --bin tester ./a.out < in/0011.txt > out.txt && cd ..
幅大きめ→誤差を無視できるようにした、でもその文差がデカくなって配置コスト大
配置コストを削減してみる。間を埋めるように配置する→これだと評価下がった→配置コストを下げれば良さそう



*/
