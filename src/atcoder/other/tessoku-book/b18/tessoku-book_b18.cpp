#include <bits/stdc++.h>
using namespace std;

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)


int main() {
    int N, S;
    cin >> N >> S;

    int A[N+1];
    prep(i, N) cin >> A[i];

    bool dp[N+1][S+1] = {false};

    dp[0][0] = true;
    for (int i = 1; i <= S; i++) {
        dp[0][i] = false;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j >= A[i]) {
                if (dp[i-1][j] || dp[i-1][j-A[i]]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            } else {
                if (dp[i-1][j]) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }

        }
    }

    vector<int> result;
    if (dp[N][S] == true) {
        for (int i = N; i > 0; i--) {
            if (dp[i-1][S] == false) {
                result.push_back(i);
                S -= A[i];
            }
        }
    } else {
        cout << -1 << endl;
        return 0;
    }

    reverse(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    return 0;

} 