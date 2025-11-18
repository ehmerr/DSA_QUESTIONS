class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        
        // Iterate while strictly less than the last index
        while (i < n - 1) {
            // If current bit is 1, it's a 2-bit char, skip next
            if (bits[i] == 1) {
                i += 2;
            } 
            // If current bit is 0, it's a 1-bit char, move next
            else {
                i++;
            }
        }
        
        // If i stops exactly at the last index, it's a 1-bit character
        return i == n - 1;
    }
};