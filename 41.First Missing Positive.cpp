class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        while(index < n) {
            if(nums[index] <= 0 || nums[index] > n) {
            index++;
            continue;
            }
            int correct = nums[index]-1;
            if(nums[index] != nums[correct]){
               swap(nums[index] , nums[correct]);
            }
            else {
                index++;
            }
        }
        for(int i = 0; i < n; i++) {
        if(nums[i] != i+1)
        return i+1;
        }
     return n+1;
    }
};
