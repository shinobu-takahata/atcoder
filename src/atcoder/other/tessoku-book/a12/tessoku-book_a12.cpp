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

int N, K;
int A[100009];
bool check(long mid) {
    long sum = 0;
    prep(i, N) sum += mid / A[i];
    if (sum >= K) return true;
    return false; 
}

int main() {
    cin >> N >> K;
    prep(i, N) cin >> A[i];
    long left = 1;
    long right = 1000000000;

    while(left < right) {
        long mid = (left + right) / 2;
        bool answer = check(mid);
        if (!answer) left = mid + 1;
        if (answer) right = mid;  
    }

    cout << left << endl;

    return 0;

}