class Solution {
public:
    string longestPalindrome(string s) {
        int ridx=0;
        int rl=0;
        for( int i=0; i<s.size(); i++){
            int l=i;
            int r=i;
            while( l>=0 && r<s.size()&& s[l]==s[r]){
                if(r-l+1>rl){
                    ridx=l;
                    rl=r-l+1;
                }
                l-=1;
                r+=1;
            }
            l=i;
            r=i+1;
            while( l>=0 && r<s.size()&&s[l]==s[r]){
                if(r-l+1>rl){
                    ridx=l;
                    rl=r-l+1;
                }
                l-=1;
                r+=1;
            }

        }
        return s.substr(ridx,rl);
    }
};
