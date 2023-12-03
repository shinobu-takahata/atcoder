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
    int M, D;
    int y, m, d;
    cin >> M >> D;
    cin >> y >> m >> d;

    if (d > D) {
        d = 1;
        m++;
    }

    if (m > M) {
        m = 1;
        y++;
    }
    d++;
    if (d > D) {
        d = 1;
        m++;
    }

    if (m > M) {
        m = 1;
        y++;
    }

    cout << y << " " << m << " " << d << endl;
    return 0;

}