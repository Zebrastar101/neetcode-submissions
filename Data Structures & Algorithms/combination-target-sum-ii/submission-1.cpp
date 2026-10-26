class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>> results;
        //vector<vector<int>> results;
        vector<int> vals;
        std::sort(nums.begin(), nums.end());
        dfs( results, nums,vals, 0, 0, target);
        return vector<vector<int>>(results.begin(),results.end());
    }
    void dfs(set<vector<int>>& results, const vector<int> nums, vector<int>& vals, int i,int sum, const int& target){
        //base case
        if(sum==target){
            results.insert(vals);
            return;
        }
        else if(i<nums.size()&&sum<target){
            vals.push_back(nums[i]);
            //sum+=nums[i];
            dfs(results,nums,vals,i+1,sum+nums[i],target);
            vals.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
            }
            //dfs(candidates, target, i + 1, cur, total);
            dfs(results,nums,vals,i+1,sum,target);
        }
        return;
    }
};
