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


int N;
double mid;

double calc(double mid) {
    double answer = (mid * mid * mid) + mid;
    return answer;
}

int main() {
    cin >> N;

    double left = 1;
    double right = 100;

    while(right - left > 0.0000001) {
        mid = (left + right) / 2.0;

        double answer = calc(mid);
        // 答えの範囲はもっと小さい方にある↓
        if (answer > N*1.0) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << fixed << setprecision(6);
    cout << mid << endl;
    return 0;

}