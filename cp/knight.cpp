//https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
#include <bits/stdc++.h>
using namespace std;

int Knight(int n,int a,int b)
{
    int level[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            level[i][j]=-1;
        }
    }


    level[0][0]=0;
    queue< pair<int, int> > q;
    q.push( make_pair(0,0));
    
    while(!q.empty())
    {
        pair<int , int> p =  q.front(); 
        q.pop();

        int x=p.first;
        int y=p.second;
        
        if(x+a<n && x+a>=0 && y+b>=0 && y+b<n && level[x+a][y+b]==-1)
        {
            level[x+a][y+b]=level[x][y]+1;
            q.push( make_pair(x+a,y+b));
        }

        if(x+a<n && x+a>=0 && y-b>=0 && y-b<n && level[x+a][y-b]==-1)
        {
            level[x+a][y-b]=level[x][y]+1;
            q.push( make_pair(x+a,y-b));
        }

        if(x-a<n && x-a>=0 && y+b>=0 && y+b<n && level[x-a][y+b]==-1)
        {
            level[x-a][y+b]=level[x][y]+1;
            q.push( make_pair(x-a,y+b));
        }

        if(x-a<n && x-a>=0 && y-b>=0 && y-b<n && level[x-a][y-b]==-1)
        {
            level[x-a][y-b]=level[x][y]+1;
            q.push( make_pair(x-a,y-b));
        }

        if(x+b<n && x+b>=0 && y+a>=0 && y+a<n && level[x+b][y+a]==-1)
        {
            level[x+b][y+a]=level[x][y]+1;
            q.push( make_pair(x+b,y+a));
        }

        if(x+b<n && x+b>=0 && y-a>=0 && y-a<n && level[x+b][y-a]==-1)
        {
            level[x+b][y-a]=level[x][y]+1;
            q.push( make_pair(x+b,y-a));
        }

        if(x-b<n && x-b>=0 && y+a>=0 && y+a<n && level[x-b][y+a]==-1)
        {
            level[x-b][y+a]=level[x][y]+1;
            q.push( make_pair(x-b,y+a));
        }

        if(x-b<n && x-b>=0 && y-a>=0 && y-a<n && level[x-b][y-a]==-1)
        {
            level[x-b][y-a]=level[x][y]+1;
            q.push( make_pair(x-b,y-a));
        }
        
        
        
    }
    
    
    
    return level[n-1][n-1];
}

int main() 
{
   
    int n;
    cin>>n;
    
    
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n-1;j++)
        {
            cout<<Knight(n,i,j)<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}