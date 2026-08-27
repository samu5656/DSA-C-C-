#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 5; //Number of processes
    int r = 3; //Number of resources
    vector<vector<int>> alloc = {{0, 0, 1}, //Allocation Matrix
                                 {3, 0, 0}, 
                                 {1, 0, 1}, 
                                 {2, 3, 2}, 
                                 {0, 0, 3}}; 

    vector<vector<int>> max = {{7, 6, 3},  //MAX Matrix
                                {3, 2, 2},
                                {8, 0, 2},
                                {2, 1, 2},
                                {5, 2, 3}};

    vector<int> avail = {1, 0, 0}; //Available Resources

    vector<int> f(n, 0);
    vector<int> ans(n);
    int ind = 0;
    vector<vector<int>> need(n, vector<int>(r));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    cout << "The SAFE Sequence is as follows\n";
    for (int i = 0; i < n - 1; i++) {
        cout << " P" << ans[i] << " ->";
    }
    cout << " P" << ans[n - 1] << endl;

    return 0;
}