/**
 * LeetCode 916: Word Subsets
 *
 * We are given two arrays A and B of words. Each word is a string of lowercase letters.
 *
 * Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.
 * For example, "wrr" is a subset of "warrior", but is not a subset of "world".
 *
 * Now say a word a from A is universal if for every b in B, b is a subset of a.
 *
 * Return a list of all the universal words in A. You can return the words in any order.
 *
 * Example 1:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 * Output: ["facebook","google","leetcode"]
 *
 * Example 2:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 * Output: ["apple","google","leetcode"]
 *
 * Example 3:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 * Output: ["facebook","google"]
 *
 * Example 4:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
 * Output: ["google","leetcode"]
 *
 * Example 5:
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
 * Output: ["facebook","leetcode"]
 *
 * Note:
 * 1. 1 <= A.length, B.length <= 10000
 * 2. 1 <= A[i].length, B[i].length <= 10
 * 3. A[i] and B[i] consist only of lowercase letters.
 * 4. All words in A[i] are unique: there isn't any word which is repeated in the array A.
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
    //to store the maximum(combined) frequency requirement of each character (a-z)
    vector<int> maxFreq(26, 0);

    //combine the character requirements from words2
    for(int i=0; i<words2.size(); i++){
        vector<int> freq(26, 0); //freq of characters in the current word
        for (int j=0; j<words2[i].size(); j++){
            freq[words2[i][j] - 'a']++;
        }

        //update the max requirement for each character
        for (int k=0; k<26; k++){
            if (freq[k] > maxFreq[k]){
                maxFreq[k] = freq[k];
            }
        }
    }

    
    //to store the ans
    vector<string> ans;

    //check each word in words1
    for (int i=0; i<words1.size(); i++){
        vector<int> freq(26, 0); //freq of characters in the current word
        for (int j=0; j<words1[i].size(); j++){
            freq[words1[i][j] - 'a']++; //count character frequency
        }
       
        //check if the word satisfies all the maxFreq requirements
        bool isUniversal = true;
        for (int k=0; k<26; k++){
            if (freq[k] < maxFreq[k]){
                isUniversal = false;
                break;
            }
        }

        if (isUniversal){
            ans.push_back(words1[i]);
        }

    }
return ans;
    
}