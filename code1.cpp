#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    char c;
    cin.get(c);
    while(t--)
    {
        char p[10002],hay[101000];
        cin>>p>>hay;

        int lp = strlen(p);
        int lh = strlen(hay);

        int p_abc[26] = {0}; // stores the frequency of each character in needle.
        int f = 0;
        for(int i=0;i<lp;i++)
            p_abc[p[i]-'a']++;

        int checker_abc[26] = {0}; // stores frequency of each character in haystack

        for(int i=0;i<lp;i++)
        {
            checker_abc[hay[i]-'a']++;
        }

        for(int i=lp;i<lh;i++)
        {
            //first check if found;
            int found = 1;
            for(int k=0;k<26;k++)
            {
                if(p_abc[k] != checker_abc[k])
                {
                    found = 0;break;
                }
            }
            if(found)
            {
                f=1;break;
            }

            checker_abc[hay[i-lp]-'a']--;
            checker_abc[hay[i]-'a']++;
        }
        int found = 1;
        for(int k=0;k<26 && !f;k++)
            {
                if(p_abc[k] != checker_abc[k])
                {
                    found = 0;break;
                }
            }
            if(found) f=1;

        if(!f)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    return 0;
    }
