class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>value;
        int size=nums.size();
        int diff;
        unordered_map<int,int>m;
        for(int i=0;i<size;i++){
            diff=target-nums[i];
            if(m.find(diff)!=m.end() && m.find(diff)->second!=i){
                value.push_back(i);
                value.push_back(m.find(diff)->second);
                return value;
            }
            m[nums[i]]=i;
        }
        return value;
    }
};
