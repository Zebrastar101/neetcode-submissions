class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> vals;
        backTrack(results, nums,vals,0);
        return results;
    }
    void backTrack(vector<vector<int>>& results, const vector<int> nums,vector<int>&vals,int i){
        //base case
        if(i>=nums.size()){
            results.push_back(vals);
            return;
        }
        //back track
        vals.push_back(nums[i]);
        backTrack(results, nums, vals, i+1);
        vals.pop_back();
        backTrack(results, nums, vals, i+1);
    }
};
