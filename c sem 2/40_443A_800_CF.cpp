#include<bits/stdc++.h>
using namespace std;

int main()
{    int i,j,flag=0,a=0;
    string str;
    getline(cin, str);
    int len;
    len=str.size();
    for(i=0;i<len-1;i++)
    { flag=0;
        if(isalpha(str[i]))
        {  
            for(j=i-1;j>0;j--)
            {  if(isalpha(str[j]))
                    if(str[i]==str[j])
                    {
                        flag=1;
                       break;
                    }                
            }
            if(flag==0)
              a++;
        }   
    }
cout<<a;
    return 0;
}