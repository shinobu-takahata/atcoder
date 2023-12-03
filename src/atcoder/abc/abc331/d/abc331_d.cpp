#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> P(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            P[i][j] = (row[j] == 'B') ? 1 : 0;
        }
    }


    // 累積和の計算
    vector<vector<int>> cumsum(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cumsum[i][j] = P[i - 1][j - 1] + cumsum[i - 1][j] + cumsum[i][j - 1] - cumsum[i - 1][j - 1];
        }
    }

    // クエリの処理
    for (int q = 0; q < Q; ++q) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        // 黒マスの数を計算
        int blackCount = cumsum[C][D]+cumsum[A-1][B-1] - cumsum[A-1][D] - cumsum[C][B-1];
        cout << blackCount << endl;
    }

    return 0;
}
