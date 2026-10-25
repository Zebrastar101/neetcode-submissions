class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max=0;
        for( int i=0; i<piles.size();i++){
            max=std::max(piles[i],max);
        }
        int l=1;
        int r=max;
        int k=0;
        int res=0;
        while(l<=r){
            k=(l+r)/2;
            long long tot=0;
            for( int p: piles){
                tot += static_cast<int>(std::ceil(static_cast<double>(p) / k));
            }
            if(tot<=h){
                r=k-1;
                res=k;
            }
            else{
                l=k+1;
            }
            
        }
        return res;
    }
    
};
