class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> squares(9);
        for(int i=0; i<board.size();i++ ){
            unordered_set<int> rows;
            unordered_set<int> cols;
            

            for(int j=0; j<board.size();j++){
                int sq=(i/3)*3+(j/3);
                
                if(board[i][j]!='.'){
                    if(rows.contains(board[i][j])||squares[sq].contains(board[i][j])){
                        return false;
                    }
                    rows.insert(board[i][j]);
                    //cols.insert(board[j][i]);
                    squares[sq].insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    if(cols.contains(board[j][i])){
                        return false;
                    }
                    cols.insert(board[j][i]);
                }
                
                
            }
            

        }
        return true;
    }
};
