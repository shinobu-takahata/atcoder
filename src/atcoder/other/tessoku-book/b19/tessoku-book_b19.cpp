#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define prep(i, n) for (int i = 1; i <= (int)(n); i++)


long long v[109];
long long w[109];
long long dp[109][100009];

int main() {
    int N, W;
    cin >> N >> W;

    prep(i, N) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < 109; i++) {
        for (int j = 0; j < 100009; j++) {
            dp[i][j] = 1000000009LL;
        }
    }

    // 現在いる(i, j)に対し、
    // i-1で、jが出来ていて、iを選ばない
    // i-1で、j-wiができていて、iを選ぶ
    dp[0][0] = 0;
    krep(i, 1, N+1) {
        krep(j, 0, 100009) {
            if(v[i] <= j)dp[i][j] = min(dp[i-1][j],dp[i-1][j - v[i]] + w[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    long long answer = 0;
    krep(i, 0, 100009) {
        if (dp[N][i] <= W) {
            answer = i;
        }
    }

    cout << answer << endl;
    return 0;
} 