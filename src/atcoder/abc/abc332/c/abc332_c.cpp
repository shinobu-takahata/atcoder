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
    int N, M;
    string S;
    cin >> N >> M;
    cin >> S;

    int ts_life = M;
    int logo_life = 0;
    int result = 0;


    krep(i, 0, N) {
        if (S[i] == '0') {
            // 何の予定もない
            ts_life = M;
            logo_life = result;
            
        } else if (S[i] == '1') {
            // 食事
            if (ts_life == 0) {
                if (logo_life <= 0) {
                    result++;
                } else {
                    logo_life--;
                }
            } else {
                ts_life--;
            }
        } else {
            // 競プロ
            if (logo_life <= 0) {
                result++;
            } else {
                logo_life--;
            }
        }
    }

    cout << result << endl;

    return 0;

}