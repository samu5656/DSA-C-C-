#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isBalanced(string& s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;

                char t = st.top();
                st.pop();

                if ((ch == ')' && t != '(') ||
                    (ch == '}' && t != '{') ||
                    (ch == ']' && t != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    string s;
    cout << "Enter bracket string: ";
    cin >> s;

    Solution obj;

    if (obj.isBalanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
