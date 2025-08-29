class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

//first leetcode question i have done myself

         vector<int> ans;  
         ans.clear();
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i , j};
                }
            }
        }
        return {};
    }
};