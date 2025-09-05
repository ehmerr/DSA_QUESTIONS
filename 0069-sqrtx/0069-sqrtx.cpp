class Solution {
public:
    int mySqrt(int x) {
        //defining search space
        int start = 1;
        int end = x;
        int ans = 0;

        while(start<=end){
             long long int mid = start+(end-start)/2;
             long long int product = mid * mid;

             if(product == x){
                return mid;
             }
             else if(product>x){
                end = mid - 1;
             }
             else{
                ans = mid;
                start = mid + 1;
             }
        }
        return ans;
    }
};