#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N, 0);
    vector<int> indices(N + 1, 0);  // 集合Sに含まれる要素のインデックスを記録するための配列
    unordered_set<int> S;

    int x;
    int setSize = 0;  // 集合Sの要素数を記録する変数

    for (int i = 0; i < Q; ++i) {
        cin >> x;

        if (S.find(x) != S.end()) {  // x is in S
            S.erase(x);
            setSize--;
        } else {  // x is not in S
            S.insert(x);
            setSize++;
        }

        // 集合Sに含まれる要素のインデックスを記録する
        indices[x] = 1;
    }

    // 数列Aの要素を更新する
    for (int i = 0; i < N; ++i) {
        A[i] = setSize;
    }

    // 集合Sに含まれる要素のみを走査して数列Aを更新する
    for (int i = 1; i <= N; ++i) {
        if (indices[i] == 1) {
            A[i - 1] += setSize;
        }
    }

    // 結果を出力する
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}