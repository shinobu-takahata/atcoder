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
    int N, S, M, L;
    cin >> N >> S >> M >> L;
    // 最低コストを格納する変数を初期化
    int min_cost = INT_MAX;

    // 6個入りパックの最大個数を計算 (N/6の切り上げ)
    int max_s = (N + 5) / 6;

    // 各パックの組み合わせを試す
    for (int s = 0; s <= max_s; ++s) {
        for (int m = 0; m <= (N + 7) / 8; ++m) {
            for (int l = 0; l <= (N + 11) / 12; ++l) {
                if (s * 6 + m * 8 + l * 12 >= N) {
                    int cost = s * S + m * M + l * L;
                    min_cost = min(min_cost, cost);
                }
            }
        }
    }

    cout << min_cost << endl;

    return 0;

}