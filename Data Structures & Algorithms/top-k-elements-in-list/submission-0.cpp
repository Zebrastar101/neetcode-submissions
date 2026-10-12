class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        //vector<int> k(k){0};
        //unordered_map<int,vector<int>> bucket;
        vector<vector<int>> bucket(nums.size() + 1);
        for(int i=0; i<nums.size();i++){
            count[nums[i]]+=1;
        }
        for(auto& pair:count){
            int val=pair.first;
            int freq=pair.second;
            bucket[freq].push_back(val);
        }
        vector<int> result;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
