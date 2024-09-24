#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(vector<vector<int>>& board)
{
    int sum = 0;
    // 가로
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 3; j++)
            temp += board[i][j];

        if (sum == 0) sum = temp;
        else if (temp != sum) return false;
    }

    //세로
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 3; j++)
            temp += board[j][i];

        if (temp != sum) return false;
    }

    //대각선1
    int temp = 0;
    for (int i = 0; i < 3; i++)
        temp += board[i][i];
    
    if(temp != sum) return false;

    //대각선2
    temp = 0;
    for (int i = 0; i < 3; i++)
        temp += board[i][2 - i];

    if (temp != sum) return false;

    return true;
}

int calc(vector<vector<int>>& board, vector<vector<int>>& temp)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sum += abs(board[i][j] - temp[i][j]);

    return sum;
}

int main()
{
    int answer = 1000;

    vector<vector<int>> board(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];

    vector<int> order(9, 0);
    for (int i = 1; i <= 9; i++)
        order[i-1] = i;

    do {

        vector<vector<int>> temp(3, vector<int>(3));
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                temp[i][j] = order[i*3 + j];

        if (ok(temp)) answer = min(answer, calc(board, temp));

    } while (next_permutation(order.begin(), order.end()));

    cout << answer;
}