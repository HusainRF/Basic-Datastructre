#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2,s3;
    int l1,l2,l3,flag=0;
    int a1[26]={0},a2[26]={0},a=0;
    cin>>s1;
    l1=s1.size();
    cin>>s2;
    l2=s2.size();
    cin>>s3;
    l3=s3.size();

    for(int i=0;i<26;i++)
    { a=0;
       for(int j=0;j<l1;j++)
       {
           if(s1[j]=='A'+i)
           {
               a1[j]=a++;
           }
       }
       for(int j=0;j<l2;j++)
       {
           if(s2[j]=='A'+i)
           {
               a1[j]=a++;
           }
       }
    }
    for(int i=0;i<26;i++)
    { a=0;
       for(int j=0;j<l3;j++)
       {
           if(s3[j]=='A'+i)
           {
               a2[j]=a++;
           }
       }
    }
    for(int i=0;i<26;i++)
    {
        if(a1[i]!=a2[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"YES";
    else 
    cout<<"NO";
    
}