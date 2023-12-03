#include <bits/stdc++.h>
using namespace std;

#define krep(i, k, n) for (int i = k; i < (int)(n); i++)
#define prep(i, n) for (int i = 1; i <= (int)(n); i++)
#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)

int main() {
    int N;
    cin >> N;
    pair<int, int> A[N+1]; // 値と元のインデックスを保持するための配列
    long long results[N+1]; // 結果を格納するための配列

    prep(i, N) {
        cin >> A[i].first; // 入力
        A[i].second = i;   // インデックスを保存
    }

    // ソートする前に、元の配列を別の配列にコピーします。
    int original[N+1];
    prep(i, N) {
        original[i] = A[i].first;
    }

    // first要素に基づいて配列をソートする
    sort(A+1, A+N+1);

    // 累積和を計算する
    long long prefSum[N+1] = {0}; // 累積和の配列
    prep(i, N) {
        prefSum[i] = prefSum[i-1] + A[i].first; // 累積和を計算
    }

    // 元の配列に基づいてそれぞれの要素を超える要素の和を計算
    prep(i, N) {
        auto it = upper_bound(A+1, A+N+1, make_pair(original[i], INT_MAX));
        // 累積和から範囲の合計を求める
        results[i] = prefSum[N] - prefSum[it - (A+1)];
    }

    // 元の順番で結果を出力
    prep(i, N) {
        cout << results[i] << ' ';
    }
    cout << endl;

    return 0;
}
