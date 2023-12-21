#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> W(N);
    int sumW = 0;
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
        sumW += W[i];
    }

    // dp[i][j] は、最初の i 個のグッズを j 個の福袋に分けたときの最小分散を表す
    vector<vector<double>> dp(N + 1, vector<double>(D + 1, 1e9));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= D; ++j) {
            int sum = 0;
            for (int k = i; k >= 1; --k) {
                sum += W[k - 1];
                double mean = static_cast<double>(sum) / j;
                dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + (sumW - sum - mean * (D - j)) * (sumW - sum - mean * (D - j)) / (D * D));
            }
        }
    }

    cout.precision(15);
    cout << dp[N][D] << endl;

    return 0;
}
