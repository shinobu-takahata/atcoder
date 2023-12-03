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

    cin >> N >> K;
    vector<int> A(N + 1);

    prep(i, N) cin >> A[i];

    long long int result = 0;
    prep(i, N) {
        // upperboundを用いて、
        // A[hoge] - A[i] > Kになる最初の位置を見つける
        int target = A[i] + K;
        auto it = upper_bound(A.begin() + i + 1, A.end(), target);
        int diff = distance(A.begin()+1+i, it);
        
        result += diff;
    }

    cout << result << endl;

    return 0;

}