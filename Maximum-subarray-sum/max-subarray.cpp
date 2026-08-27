#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> multiplyMatrix(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B
) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();
    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible.\n";
        return {};
    }
    vector<vector<int>> C(
        rowsA,
        vector<int>(colsB, 0)
    );
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "[ ";
        for (int value : row) {
            cout << value << " ";
        }
        cout << "]\n";
    }
}
bool verifyResult(
    const vector<vector<int>>& actual,
    const vector<vector<int>>& expected
) {
    return actual == expected;
}
void runTest(
    const string& testName,
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    const vector<vector<int>>& expected
) {
    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);
    vector<vector<int>> result = multiplyMatrix(A, B);
    cout << "\nResult:\n";
    printMatrix(result);
    cout << "\nExpected Result:\n";
    printMatrix(expected);  
    cout <<"\n";
    if (verifyResult(result, expected)) {
        cout << "\nVerification: PASS\n";
    } else {
        cout << "\nVerification: FAIL\n";
    }
}
int main() {
    vector<vector<int>> A1 = {
        {5}
    };
    vector<vector<int>> B1 = {
        {4}
    };
    vector<vector<int>> expected1 = {
        {20}
    };
    runTest(
        "Test Case 1: 1 x 1 Matrices",
        A1,
        B1,
        expected1
    );
    vector<vector<int>> A2 = {
        {1, 2},
        {3, 4}
    };
    vector<vector<int>> B2 = {
        {5, 6},
        {7, 8}
    };
    vector<vector<int>> expected2 = {
        {19, 22},
        {43, 50}
    };
    runTest(
        "Test Case 2: 2 x 2 Matrices",
        A2,
        B2,
        expected2
    );
    vector<vector<int>> A3 = {
        {1, 2},
        {3, 4}
    };
    vector<vector<int>> identity = {
        {1, 0},
        {0, 1}
    };
    vector<vector<int>> expected3 = {
        {1, 2},
        {3, 4}
    };
    runTest(
        "Test Case 3: Identity Matrix",
        A3,
        identity,
        expected3
    );
    vector<vector<int>> zeroMatrix = {
        {0, 0},
        {0, 0}
    };
    vector<vector<int>> expected4 = {
        {0, 0},
        {0, 0}
    };
    runTest(
        "Test Case 4: Zero Matrix",
        A3,
        zeroMatrix,
        expected4
    );
    vector<vector<int>> A5 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> B5 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    vector<vector<int>> expected5 = {
        {30, 24, 18},
        {84, 69, 54},
        {138, 114, 90}
    };
    runTest(
        "Test Case 5: 3 x 3 Matrices",
        A5,
        B5,
        expected5
    );
    vector<vector<int>> A6 = {
        {2, 1, 3},
        {4, 2, 1},
        {1, 3, 2}
    };
    vector<vector<int>> B6 = {
        {1, 2, 1},
        {2, 1, 3},
        {3, 2, 2}
    };
    vector<vector<int>> expected6 = {
        {13, 11, 11},
        {11, 12, 12},
        {13, 9, 14}
    };
    runTest(
        "Test Case 6: Non-Power-of-2 Matrix",
        A6,
        B6,
        expected6
    );
    return 0;
}