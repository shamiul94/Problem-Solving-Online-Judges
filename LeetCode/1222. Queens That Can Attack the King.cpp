class Solution
{
public:
    enum piece
    {
        QUEEN,
        KING,
        EMPTY
    };

    vector<vector<int> > queensAttacktheKing(vector<vector<int> > &queens, vector<int> &king)
    {

        vector<pair<int, int> > directions = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};

        vector<vector<piece> > board(8, vector<piece>(8, EMPTY));

        for (int i = 0; i < queens.size(); i++)
        {
            board[queens[i][0]][queens[i][1]] = QUEEN;
        }

        vector<vector<int> > attackers;

        for (int directionIdx = 0; directionIdx < directions.size(); directionIdx++)
        {
            pair<int, int> currDirection = directions[directionIdx];

            int x = king[0];
            int y = king[1];

            for (int step = 0; step < 8; step++)
            {
                x = x + currDirection.first;
                y = y + currDirection.second;

                if (x < 0 || y < 0 || x >= 8 || y >= 8)
                {
                    break;
                }

                if (board[x][y] == QUEEN)
                {
                    attackers.push_back(vector<int>{x, y});
                    break;
                }
            }
        }

        return attackers;
    }
};