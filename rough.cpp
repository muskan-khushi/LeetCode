#include <vector>
#include <set>

class Solution {
public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) {
        int freq[10] = {0}; // Frequency array for digits
        for (int digit : digits) {
            freq[digit]++;
        }
        
        std::vector<int> result;

        // Loop for hundreds, tens, and even units
        for (int i = 1; i <= 9; ++i) { // Hundreds place (no leading zero)
            if (freq[i] > 0) {
                freq[i]--;
                for (int j = 0; j <= 9; ++j) { // Tens place
                    if (freq[j] > 0) {
                        freq[j]--;
                        for (int k = 0; k <= 8; k += 2) { // Units place (even digits only)
                            if (freq[k] > 0) {
                                result.push_back(i * 100 + j * 10 + k);
                            }
                        }
                        freq[j]++; // Restore frequency for tens
                    }
                }
                freq[i]++; // Restore frequency for hundreds
            }
        }
        
        return result;
    }
};

