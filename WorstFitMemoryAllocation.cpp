#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
int main()
{
    int num_memBlock, num_proc;
    cout << "Enter no. of memory blocks available: ";
    cin >> num_memBlock;

    cout << "Enter no. of processes available: ";
    cin >> num_proc;
    int mem_block[num_memBlock], proc_size[num_proc];
    cout << "Enter size of each block: \n";
    for (int i = 0; i < num_memBlock; i++)
    {
        cin >> mem_block[i];
    }
    cout << "Enter processess size: \n";

    for (int i = 0; i < num_memBlock; i++)
    {
        cin >> proc_size[i];
    }
    int ans[num_proc];
    memset(ans, -1, sizeof(ans));
    int hash[num_memBlock]{0};
    for (int i = 0; i < num_proc; i++)
    {
        bool f = 0;
        int ind = -1;
        int temp1 = INT_MIN;
        for (int j = 0; j < num_memBlock; j++)
        {
            int temp = mem_block[j] - proc_size[i];
            if (temp >= 0 && temp1 <= temp && hash[j] == 0)
            {
                ind = j;
                temp1 = temp;
            }
        }
        if (ind != -1)
        {
            hash[ind] = 1;
            ans[i] = ind + 1;
        }
    }
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < num_proc; i++)
    {
        int p = ans[i];
        string s;
        if (ans[i] == -1)
            s = {"Not Allocated"};
        else
            s = to_string(ans[i]);
        cout << i + 1 << "\t\t" << proc_size[i] << "\t\t" << s << endl;
    }
    return 0;
}
