class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
         int end = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin()-1;

         if(st < nums.size() && nums[st] == target) {
             return {st, end};
         }           
         return {-1, -1};
    }
};
