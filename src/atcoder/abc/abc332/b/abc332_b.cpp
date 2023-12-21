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
    int K, G, M;
    cin >> K >> G >> M;

    int now_glass = 0;
    int now_cup = 0;
    krep(i, 0, K) {
        if (now_glass == G) {
            now_glass = 0;
        } else if (now_cup == 0)  {
            now_cup = M;
        } else {
            int tarinai = (G - now_glass);
            if (now_cup >= tarinai) {
                now_glass += tarinai;
                now_cup -= tarinai;
            } else {
                now_glass += now_cup;
                now_cup = 0;
            }
        }
    }

    cout << now_glass << " " << now_cup << endl;

    return 0;

}