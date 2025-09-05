class Solution {
public:

int findPivotIndex(vector<int>& nums){

 int n = nums.size();
    int start = 0;
    int end = n - 1;
    
    int ans = -1;


   while(start<=end){

    int mid = start+(end-start)/2;

if(start == end){
    return mid;
}

     if (mid+1 < n && nums[mid] > nums[mid+1]){
        return mid;
     }
       if(nums[mid]<nums[start]){
        end = mid - 1;
     }
     else{
        start = mid + 1;
     }
}
return -1;
}

int binarySearch( int start, int end, vector<int>& nums, int target) {

    while(start<=end){
        int mid = (start+(end-start)/2);

        if(target==nums[mid])
        return mid;

        else if(target>nums[mid]){
            start = mid+1;
        }
        else
        end = mid-1;
    }
    return -1;
}




    int search(vector<int>& nums, int target) {
        int n = nums.size();
    
        int pivot = findPivotIndex(nums);
        
        if(target >= nums[0] && target <= nums[pivot]){
            int ans = binarySearch(0, pivot,nums,target);
            return ans;
        }
        else{ int ans = binarySearch(pivot+1, n-1,nums,target);
            return ans;

        }
        return -1;
    }
};