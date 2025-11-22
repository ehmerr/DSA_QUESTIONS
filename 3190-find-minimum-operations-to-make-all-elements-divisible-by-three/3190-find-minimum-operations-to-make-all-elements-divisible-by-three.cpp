class Solution {
public:
    /**
     * Finds the minimum number of operations required to make all elements 
     * in the array nums divisible by three.
     * * @param nums The input vector of integers.
     * @return The minimum total operations.
     */
    int minimumOperations(std::vector<int>& nums) {
        int total_operations = 0;

        // Iterate through each number in the array
        for (int num : nums) {
            // Calculate the remainder when the number is divided by 3
            int remainder = num % 3;

            // If the remainder is 0, the number is already divisible by 3 (0 operations).
            // If the remainder is 1 (e.g., 4), 1 operation makes it divisible (4-1=3).
            // If the remainder is 2 (e.g., 5), 1 operation makes it divisible (5+1=6).
            
            if (remainder != 0) {
                // If remainder is 1 or 2, we need exactly 1 operation.
                total_operations++;
            }
        }

        return total_operations;
    }
};