#include <iostream>
#include <vector>
using namespace std;

// 2つのベクトルが単一のスワップ操作で一致するかをチェックする関数
bool isSingleSwapEqual(const vector<int>& a, const vector<int>& b, vector<int>& diff) {
    diff.clear();
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            diff.push_back(i);
        }
    }
    if (diff.size() == 0) return true;  // すでに一致している
    if (diff.size() != 2) return false; // 2つ以上の差異がある
    return a[diff[0]] == b[diff[1]] && a[diff[1]] == b[diff[0]];
}

// 列をスワップする関数
void swapColumns(vector<vector<int>>& grid, int col1, int col2) {
    for (auto& row : grid) {
        swap(row[col1], row[col2]);
    }
}

// 行をスワップする関数
void swapRows(vector<vector<int>>& grid, int row1, int row2) {
    swap(grid[row1], grid[row2]);
}

// スワップ回数を計算する関数
int countSwaps(vector<vector<int>>& A, const vector<vector<int>>& B) {
    int H = A.size(), W = A[0].size(), swaps = 0;
    vector<int> diff;

    // 列のスワップ
    for (int j = 0; j < W; ++j) {
        vector<int> colA(H), colB(H);
        for (int i = 0; i < H; ++i) {
            colA[i] = A[i][j];
            colB[i] = B[i][j];
        }
        if (isSingleSwapEqual(colA, colB, diff) && !diff.empty()) {
            swaps++;
            swapColumns(A, diff[0], diff[1]);
        }
    }

    // 行のスワップ
    for (int i = 0; i < H; ++i) {
        if (isSingleSwapEqual(A[i], B[i], diff) && !diff.empty()) {
            swaps++;
            swapRows(A, diff[0], diff[1]);
        }
    }

    // 最終チェック
    return (A == B) ? swaps : -1;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> gridA(H, vector<int>(W)), gridB(H, vector<int>(W));

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> gridA[i][j];

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> gridB[i][j];

    cout << countSwaps(gridA, gridB) << endl;

    return 0;
}
