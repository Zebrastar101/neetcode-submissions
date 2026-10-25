class Solution {
public:
    int characterReplacement(string s, int k) {
       int l=0; 
       //int r=0;
       int res=0;
       //int count=1;
       unordered_map<char,int> freq;
       for(int r=0;r<s.size();r++){
            freq[s[r]]+=1;
            
            while ((r - l + 1) - max_freq(freq) > k) {
                freq[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);

       }
       return res;
    }
    
int max_freq(const std::unordered_map<char, int>& freq) {
    int max_val = 0;
    
    // Using a modern range-based for loop for cleaner code
    for (const auto& pair : freq) {
        max_val = std::max(max_val, pair.second);
    }
    
    return max_val;
}
};
