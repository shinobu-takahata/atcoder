#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int before_cnt = N / 2;
    int after_cnt = N - before_cnt;
    long long before[1 << before_cnt] = {0};
    long long after[1 << after_cnt] = {0};

    // 前半部分
    for (int i = 0; i < (1 << before_cnt); ++i) {
        long long sum = 0;
        for (int j = 0; j < before_cnt; ++j) {
            if (i & (1 << j)) {
                sum += A[j];
            }
        }
        before[i] = sum;
    }

    // 後半部分
    for (int i = 0; i < (1 << after_cnt); ++i) {
        long long sum = 0;
        for (int j = 0; j < after_cnt; ++j) {
            if (i & (1 << j)) {
                sum += A[before_cnt + j];
            }
        }
        after[i] = sum;
    }

    sort(after, after + (1 << after_cnt));

    for (int i = 0; i < (1 << before_cnt); ++i) {
        int result = upper_bound(after, after + (1 << after_cnt), K - before[i]) - after;
        if (result > 0 && before[i] + after[result - 1] == K) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
