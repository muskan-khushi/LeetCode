// 2094. Finding 3-Digit Even Numbers
// You are given an integer array digits, where each element is a digit. 
// The array may contain duplicates.
// You need to find all the unique integers that follow the given requirements:
// - The integer consists of the concatenation of three digits from digits in any arbitrary order.
// - The integer does not have leading zeros.
// - The integer is even.
// Return a sorted array of the unique integers.


#include <bits/stdc++.h>
using namespace std;

//brute force approach
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> uniqueNumbers;

        int n = digits.size();
        for (int i=0; i<n; i++){
            if (digits[i] == 0) continue;
            for (int j=0; j<n; j++){
                if (j==i) continue;
                for (int k=0; k<n; k++){
                    if (k==i || k==j) continue;
                    int number = digits[i]*100 + digits[j]*10 + digits[k];
                    if (number % 2 == 0){
                    uniqueNumbers.insert(number);
                    }
                }
            }
        }
        vector<int> result(uniqueNumbers.begin(), uniqueNumbers.end());
        return result;
    }
};


// Optimized approach
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int digit : digits) {
            freq[digit]++;
        }

        set<int> result;

        for (int i = 1; i <= 9; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;

            for (int j = 0; j <= 9; j++) {
                if (freq[j] == 0) continue;
                freq[j]--;

                for (int k = 0; k <= 8; k += 2) {
                    if (freq[k] == 0) continue;

                    result.insert(i * 100 + j * 10 + k);
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return vector<int>(result.begin(), result.end());
    }
};

