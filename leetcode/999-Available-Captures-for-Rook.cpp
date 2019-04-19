#include <vector>
using namespace std;


class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size(), n=board[0].size();
        // step 1 - find the position of Rook
        for(int row=0;row<m;++row){
            for(int col=0;col<n;++col){
                if(board[row][col]=='R'){
                    // step 2 - check row and column, find available pawn
                    int ans = 0;
                    int i;
                    for(i=row-1;i>=0 && board[i][col]=='.';--i);
                    if(i>=0 && board[i][col]=='p')++ans;
                    for(i=row+1;i<n && board[i][col]=='.';++i);
                    if(i<n && board[i][col]=='p')++ans;
                    for(i=col-1;i>=0 && board[row][i]=='.';--i);
                    if(i>=0 && board[row][i]=='p')++ans;
                    for(i=col+1;i<m && board[row][i]=='.';++i);
                    if(i<n && board[row][i]=='p')++ans;
                    return ans;
                }
            }
        }
        return 0;
    }
};