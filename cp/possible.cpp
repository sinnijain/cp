#include <bits/stdc++.h> 
#include <string>

using namespace std; 

int ansp(int g_count , int t_count , int a_count , int c_count )
{

    int t=(g_count+a_count+t_count+c_count)/4;
    int ans;

    if(a_count>=t)
    {
        ans+=a_count-t;
    }

    if(g_count>=t)
    {
        ans+=g_count-t;
    }

    if(t_count>=t)
    {
        ans+=t_count-t;
    }

    if(c_count>=t)
    {
        ans+=c_count-t;
    }

    return ans;
}

int ispossible(int g_count , int t_count , int a_count , int c_count , int ans)
{

    

    int t=(g_count+t_count+a_count+c_count+ans)/4;

    if(a_count>t)
    {
        return 0;
    }

    if(g_count>t)
    {
        return 0;
    }

    if(t_count>t)
    {
        return 0;
    }

    if(c_count>t)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}



// int anspossible(int g_count , int t_count , int a_count , int c_count , int ans)
// {
//     int t=(g_count+t_count+a_count+c_count+ans)/4;
//     int ans1;
//     if(a_count<=t)
//     {
//         ans1+=t-a_count;
//     }

//     if(g_count<=t)
//     {
//         ans1+=t-g_count;
//     }

//     if(t_count<=t)
//     {
//         ans1+=t-t_count;
//     }

//     if(c_count<=t)
//     {
//         ans1+=t-c_count;
//     }

//     return ans1;  
// }


int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int final_ans;
    int g_count=0;
    int t_count=0;
    int a_count=0;
    int c_count=0;
    int t=n/4;
    int ans;

    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            a_count++;   
        }
        else if(s[i]=='T')
        {
            t_count++;   
        }

        else if(s[i]=='C')
        {
            c_count++;   
        }

        else if(s[i]=='G')
        {
            g_count++;   
        }
    }

    if(ispossible(g_count, t_count, a_count, c_count, 0)==1)
    {
        // final_ans=anspossible(g1_count, t1_count, a1_count, c1_count, j);
        // cout << "........." << g_count << t_count << a_count << c_count << "........."<<endl;
        cout << 0;
        return 0;
    }

    //cout << g_count << t_count << a_count << c_count;

    ans=ansp(g_count , t_count , a_count , c_count);
    //cout << ans;

    int g1_count;
    int t1_count;
    int a1_count;
    int c1_count;

    for(int j=ans;j<=n;j++)
    {
        
        
        
        for(int i=0 ; i<(n-j+1) ; i++)
        {

            g1_count=g_count;
            t1_count=t_count;
            a1_count=a_count;
            c1_count=c_count;
            // cout << g1_count << t1_count << a1_count << c1_count << j << endl;

            for(int k=i;k<j+i;k++)
            {
                if(s[k]=='A')
                {
                    a1_count--;   
                }

                else if(s[k]=='T')
                {  
                    t1_count--;   
                }

                else if(s[k]=='C')
                {
                    c1_count--;   
                }

                else if(s[k]=='G')
                {
                    g1_count--;   
                }

           }

            // cout << g1_count << t1_count << a1_count << c1_count << j << endl;
            // cout << "a"<<endl;

            

            if(ispossible(g1_count, t1_count, a1_count, c1_count, j)==1)
                {
                    // final_ans=anspossible(g1_count, t1_count, a1_count, c1_count, j);
                    // cout << "........." << g1_count << t1_count << a1_count << c1_count << "........."<<endl;
                    cout << j;
                    return 0;
                }

        }

        

        
    }
}
