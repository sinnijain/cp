#include <bits/stdc++.h>
using namespace std;
map<string,bool> mp;
map<string,vector<string>> str;
map<string,string> pda;





void state(string ss,queue<string> &qp)
{
    int index;
    for(int i=0;i<7;i++)
    {
        if(ss[i]=='_')
        {
            index=i;
            break;
        }
    }

    string s;
    s=ss;
    if((index-1)>=0 && ss[index-1]=='L')
    {
        swap(ss[index],ss[index-1]);
        if(mp.find(ss) == mp.end())
        {
          mp[ss]=false;
          str[s].push_back(ss);
          qp.push(ss);
          pda[ss]=s;
        }
      
    }

    ss=s;

    if((index-2)>=0 && ss[index-2]=='L')
    {
      swap(ss[index],ss[index-2]);
       if(mp.find(ss) == mp.end())
       {
            mp[ss]=false;
            str[s].push_back(ss);
            qp.push(ss);
            pda[ss]=s;
       }
 
    }

    ss=s;
    
    if((index+1)<7 && ss[index+1]=='R')
    {
        swap(ss[index],ss[index+1]);
        if(mp.find(ss) == mp.end())
        {
        mp[ss]=false;
        str[s].push_back(ss);
        qp.push(ss);
         pda[ss]=s;
        }
  
    }
    ss=s;
       if((index+2) < 7 && ss[index+2]=='R')
    {
        swap(ss[index],ss[index+2]);
        if(mp.find(ss) == mp.end())
        {
        mp[ss]=false;
        str[s].push_back(ss);
        qp.push(ss);
         pda[ss]=s;
        }
  
    }
    
}








void Bfs(string st)
{
    queue<string> qu;
    qu.push(st);
    
    while(!qu.empty())
    {
     string ss=qu.front();
     if(ss=="RRR_LLL")
     break;
     qu.pop();
     mp[ss]=true;
     state(ss,qu);
    }
    
    
    
}


int main() 
{
	string st="LLL_RRR";
    Bfs(st);
    vector<pair<string,string>> RR;
    int vl=0;
    string it="RRR_LLL";

    while(1)
    {
            pair<string,string> stk;
            stk.first=pda[it];
            stk.second=it;
            RR.push_back(stk);
            vl++;
    
        if(pda[it]=="LLL_RRR")
            break;

        it=pda[it];

    }

    cout<<"total state is : "<<vl;
    cout<<endl;



    for(int i=RR.size()-1;i>=0;i--)
    {
        cout<<RR[i].first<<" "<<RR[i].second<<endl;
    }

	return 0;
}