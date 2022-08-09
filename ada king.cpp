#include<bits/stdc++.h>
using namespace std;
bool visited[10][10][10];
bool board[10][10];
int dfs(int x,int y, int moves)
{
    if(x==0 || x>8) return 0;
    if(y==0 || y>8) return 0;
    board[x][y] = true;
    visited[x][y][moves] = true;
    if(moves == 0 ) return 0;

    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(!visited[x+i][y+j][moves])
            {
                dfs(x+i,y+j,moves-1);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c,k,x,y,cnt=0;
        cin>>x>>y>>k;
        memset(visited, false, sizeof(visited));
        memset(board, false, sizeof(board));
        dfs(x,y,k);
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
            {
                if(board[i][j])
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
}
