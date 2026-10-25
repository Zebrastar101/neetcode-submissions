class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index=-1;
        for( int i =0; i< matrix.size();i++){
            if(target<=matrix[i][matrix[i].size()-1]&&target>=matrix[i][0]){
                index=i;
                break;
            }
        }
        if(index==-1){return false;}
        int l= 0;
        int r= matrix[index].size()-1;
        while(l<=r){
                int mid = l + (r-l)/2;
                if(matrix[index][mid]==target){
                    return true;
                }
                else if(target<matrix[index][mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
        }
        return false;
    }
};
