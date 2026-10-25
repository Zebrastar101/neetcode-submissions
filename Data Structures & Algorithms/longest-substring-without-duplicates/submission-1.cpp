class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){return 0;}
        unordered_set<char> elements;
        int l=0;
        int r=1;
        int count=1;
        int max=count;
        elements.insert(s[l]);
        while(l<=r&&r<s.size()&&l<s.size()){
            if(elements.find(s[r])==elements.end()){
                count+=1;
                elements.insert(s[r]);
                r++;
            }
            else{
                elements.erase(s[l]);
                l++;
                max=std::max(max,count);
                count-=1;    
            }
        }
        return std::max(max,count);
    }
};
