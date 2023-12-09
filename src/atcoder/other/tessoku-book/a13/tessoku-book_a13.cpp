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
    vector<int> R(N + 1);

    prep(i, N) cin >> A[i];

    long long int result = 0;
    krep(i, 1, N) {
        if (i == 1) R[i] = 1;
        else R[i] = R[i - 1];

        while(R[i] < N && A[R[i]+1] - A[i] <= K) {
            R[i]++;
        }
    }

    krep(i, 1, N) {
        result += R[i] - i;
    }
    cout << result << endl;

    return 0;

}