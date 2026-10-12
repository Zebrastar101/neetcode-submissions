class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(),nums.end());
        int seq=0;
        //sort(nums.begin(),nums.end());
        for(int n: nums){
            if(store.find(n-1)==store.end()){
                int streak=0;
            int cur=n;
            while( store.find(cur)!=store.end()){
                streak++;
                cur++;
            }
            seq=max(seq,streak);
            }
            
            
        }
        return seq;
    }
};
