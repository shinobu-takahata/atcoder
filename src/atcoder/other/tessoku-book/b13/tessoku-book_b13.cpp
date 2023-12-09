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
    int N, K;
    int sum[100009] = {0};
    cin >> N >> K;

    int A;
    sum[0] = 0;
    prep(i, N) {
        // 入力と累積和
        cin >> A;
        sum[i] = sum[i - 1] + A;
    }

    int now_col = 1;
    int result = 0;
    prep(i, N) {
        if (i != 1) now_col = now_col - 1;

        while(now_col <= N && sum[now_col] - sum[i-1] <= K) {
            now_col++;
        }
        result += (now_col - i);
    }


    cout << result << endl;

    return 0;

}