#include<algorithm>
class Solution {
public:
    int missingNumber(vector<int>& nums){
         
         sort(nums.begin(),nums.end());

         int n = nums.size();
         int start = 0;
         int end = n-1;

        int ans = n;

        while(start<=end){
            int mid = start+(end-start)/2;

         if(nums[mid]==mid){
            start = mid + 1;
         }

         else if(nums[mid]>mid){
            ans = mid;
            end = mid -1;
         }
        }

        return ans;




    }
};