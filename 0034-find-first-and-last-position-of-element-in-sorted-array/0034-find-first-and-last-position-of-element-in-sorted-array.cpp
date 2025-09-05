class Solution {
public:
int firstOccurance(vector<int>& nums, int target){

int n = nums.size();
int start = 0;
int end = n-1;
int ans = -1;

while(start<=end){
    int mid = start+(end-start)/2;

   if(target==nums[mid])
   {
            ans = mid;
            end = mid - 1;
   }

  else if(target>nums[mid])
   {
    start = mid +1;
   }
   else
   {
    end = mid - 1;
   }
}
return ans;
}


int LastOccurance(vector<int>& nums, int target){

int n = nums.size();
int start = 0;
int end = n-1;
int ans = -1;

while(start<=end){
    int mid = start+(end-start)/2;

   if(target==nums[mid]){
            ans = mid;
            start = mid + 1;
   }

  else if(target>nums[mid]){
    start = mid + 1;
   }
   else{
    end = mid - 1;
   }
}
return ans;
}

vector<int> searchRange(vector<int>& nums, int target){

vector<int> ans;

int a = firstOccurance(nums,target);
int b = LastOccurance(nums,target);

ans.push_back(a);
ans.push_back(b);

return ans;



}
};