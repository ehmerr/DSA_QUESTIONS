#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // 1. Precompute factorials
        vector<int> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        // 2. Create list of available numbers (as a string)
        string numbers = "";
        for (int i = 1; i <= n; ++i) {
            numbers += to_string(i);
        }

        // 3. Convert k to 0-indexing
        k--;

        string result = "";

        // 4. Loop from n down to 1
        for (int i = n; i >= 1; --i) {
            // i = number of digits remaining
            
            // 5. Find which block k falls into
            // The block size is (i-1)!
            int block_size = factorial[i - 1];
            int index = k / block_size;

            // 6. Get the digit and append to result
            result += numbers[index];

            // 7. Remove the digit from available numbers
            // erase() is O(n), making the total solution O(n^2)
            numbers.erase(numbers.begin() + index);

            // 8. Update k to be the new k *within* that block
            k = k % block_size;
        }

        return result;
    }
};