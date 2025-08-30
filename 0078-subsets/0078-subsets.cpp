class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        
        // Start the backtracking process from the first element (index 0).
        generateSubsets(nums, 0, currentSubset, result);
        
        return result;
    }
    
private:
    void generateSubsets(const vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Add the current combination to the result list.
        result.push_back(currentSubset);
        
        // Explore all choices from the current index onwards.
        for (int i = index; i < nums.size(); ++i) {
            // Include the current element.
            currentSubset.push_back(nums[i]);
            
            // Recurse to generate subsets starting with the current element.
            generateSubsets(nums, i + 1, currentSubset, result);
            
            // Backtrack: remove the current element to explore subsets without it.
            currentSubset.pop_back();
        }
    }
};