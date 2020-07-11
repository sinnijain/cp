//https://www.hackerrank.com/challenges/gridland-metro/problem
#include <bits/stdc++.h>
#include <math.h>
#include<tuple>
using namespace std;


int main() 
{
    int n,m,k;
    int a,b;
    int r;
    cin >> n >> m >> k;
    

    long tcount=(long)n*(long)m;

    if (!k) 
    {
        cout << tcount;
        return 0;
    }

    vector < tuple<int,int,int> > track;

    for(int i=0;i<k;i++)
    {
        int r,c1,c2;
        cin >> r >> c1 >> c2;
        tracl.push_back(make_tuple(r,c1,c2));
    }

    sort(track.begin(),track.end());

    vector< tuple<int,int,int>> :: iterator it=track.begin();

    while(it!=track.end())
    {
        int cr=get<0>(*it);
        //current start and end
        int x=0;
        int y=0;

        while(it!=track.end() && cr==get<0>(*it))
        {
            //first time this row occuring
            if(x==0)
            {
                x=get<1>(*it);
                y=get<2>(*it);
                it++;
                continue;
            }

            //merging rows
            if(get<1>(*it)<=y+1 && get<2>(*it)>y )
            {
                y=get<2>(*it);
                it++;
            }

            //disjoint rows
            else if(get<1>(*it)>(cy+1))
            {
                tcount-=(y-x+1);
                x=get<1>(*it);
                y=get<2>(*it);
                it++;
            }


        }
        tcount-=(y-x+1);

    }

    cout << tcount;
}