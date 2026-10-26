class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> vals;
        //std::sort(nums.begin(), nums.end());
        dfs( results, nums,vals, 0, 0, target);
        return results;
    }
    void dfs(vector<vector<int>>& results, const vector<int> nums, vector<int>& vals, int i,int sum, const int& target){
        //base case
        if(sum==target){
            results.push_back(vals);
            return;
        }
        else if(i<nums.size()&&sum<target){
            vals.push_back(nums[i]);
            //sum+=nums[i];
            dfs(results,nums,vals,i,sum+nums[i],target);
            vals.pop_back();
            dfs(results,nums,vals,i+1,sum,target);
        }
        return;
    }
};
