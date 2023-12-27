#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define prep(i, n) for (int i = 1; i <= (int)(n); i++)


long long v[109];
long long w[109];
long long dp[109][100009] = {0};

int main() {
    int N, W;
    cin >> N >> W;

    prep(i, N) {
        cin >> w[i] >> v[i];
    }

    // 現在いる(i, j)に対し、
    // i-1で、jが出来ていて、iを選ばない
    // i-1で、j-wiができていて、iを選ぶ
    dp[0][0] = 0;
    krep(i, 1, N+1) {
        krep(j, 0, W+1) {
            if (j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]); 
        }
    }

    long long answer = 0;
    krep(i, 0, W+1) {
        answer = max(answer, dp[N][i]);
    }

    cout << answer << endl;
    return 0;
} 