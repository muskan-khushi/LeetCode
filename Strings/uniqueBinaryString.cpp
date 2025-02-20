#include <bits/stdc++.h>
using namespace std;

class Solution{
string findDifferentBinaryString(vector<string>& nums) {
    unordered_set<int> st;

    // Convert each binary string to an integer and store in a set
    for (string& num : nums) {
        st.insert(stoi(num, 0, 2));
    }

    int n = nums.size();

    // Try all possible binary numbers from 0 to 2^n - 1
    for (int number = 0; number < (1 << n); number++) {
        if (st.find(number) == st.end()) {
            // Generate binary string of length 'n'
            string result = bitset<16>(number).to_string();
            return result.substr(16 - n, n);
        }
    }

    return "";
}
};


class Solution1 {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
                int n = nums.size();
        
                string result;
        
                for(int i=0; i<n; i++){
                    char ch = nums[i][i];
        
                    result += (ch == '0') ? "1" : "0";
                }
                return result;
    }
};