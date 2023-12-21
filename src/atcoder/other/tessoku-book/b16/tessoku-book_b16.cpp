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


int h[100009];
int main() {
    int N;
    cin >> N;

    prep(i, N) cin >> h[i];

    int swap1[N+1], swap2[N+1] = {0};

    for (int i = 2; i <= N; i++) {
        swap1[i] = abs(h[i-1] - h[i]);
    }
    for (int i = 3; i <= N; i++) {
        swap2[i] = abs(h[i-2] - h[i]);
    }

    int dp[N+1] = {0};
    dp[1] = 0;
    dp[2] = swap1[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i-1] + swap1[i], dp[i-2] + swap2[i]);
    }

    cout << dp[N] << endl;

}