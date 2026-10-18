class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0; i<nums.size()-1;i++){
            if(i>0 &&nums[i-1]==nums[i]){
                continue;
            }
            int target=-nums[i];
            int l=i+1, r=nums.size()-1;
            while(l<r){
            int sum=nums[l]+nums[r];
            if(sum<target){
                l++;
            }
            else if(sum>target){
                r--;
            }
            else{
                result.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                }
            }
        }
        }
        return result;
    }
};
