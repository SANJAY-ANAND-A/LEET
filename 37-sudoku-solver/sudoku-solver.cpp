class Solution {
public:
vector<unordered_set<char>> rows= vector<unordered_set<char>>(9);
vector<unordered_set<char>> cols = vector<unordered_set<char>>(9);
vector<unordered_set<char>> boxes=vector<unordered_set<char>>(9);
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                char c = board[i][j];
                if(c == '.') continue;
                int box = i/3*3+j/3;
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
            }
        }
        solve(board,0,0);
    }
    bool solve(vector<vector<char>> &board, int i, int j)
    {
        if(i == 9) return  true;
        if(j == 9) return solve(board,i+1,0);
        if(board[i][j]!='.') return(solve(board,i,j+1));
        for(char c = '1'; c <='9' ; c++)
        {
                int box = i/3*3+j/3;
            if(!rows[i].count(c)&&!cols[j].count(c)&&!boxes[box].count(c)){ 
                board[i][j]=c;
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[box].insert(c);
                if(solve(board,i,j+1)) return true;
                board[i][j]='.';
                rows[i].erase(c);
                cols[j].erase(c);
                boxes[box].erase(c);
            }
            
        }
        return false;
    }
    
    // bool check(vector<vector<int>> &board; int i ; int j ; char c)
    // {
    //     int box = i/3*3+j/3;
    //     if(rows[i].count(c)||cols[j].count(box)||boxes[box].count(c))
    // }
};