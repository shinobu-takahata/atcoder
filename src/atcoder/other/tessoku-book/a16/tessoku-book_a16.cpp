#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)


char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
} 

int alphabet_to_int(char s) {
    return s - 'a';
}


int main() {
    int N;
    cin >> N;

    int A[N+1];
    int B[N+1];

    for (int i = 2; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 3; i <= N; i++) {
        cin >> B[i];
    }

    int dp[N+1] = {0};
    dp[1] = 0;
    dp[2] = A[2];
    for (int i = 3; i <= N; i++) {
        int total_route_a = dp[i-1] +  A[i];
        int total_route_b = dp[i-2] + B[i];
        dp[i] = min(total_route_a, total_route_b);
    }

    cout << dp[N] << endl;
}