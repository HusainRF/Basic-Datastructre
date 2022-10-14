#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num_memBlock, num_proc;
    cout << "Enter no. of memory blocks available: ";
    cin >> num_memBlock;

    cout << "Enter no. of processes available: ";
    cin >> num_proc;
    int mem_block[num_memBlock], proc_size[num_proc];
    cout << "Enter size of each block : \n";

    for (int i = 0; i < num_memBlock; i++)
    {
        cin >> mem_block[i];
    }

    cout << "Enter processess size : \n";

    for (int i = 0; i < num_memBlock; i++)
    {
        cin >> proc_size[i];
    }
    int ans[num_proc];
    int hash[num_memBlock]{0};
    for (int i = 0; i < num_proc; i++)
    {
        bool f = 0;
        for (int j = 0; j < num_memBlock; j++)
        {
            if (proc_size[i] <= mem_block[j] && hash[j] == 0)
            {
                hash[j] = 1;
                ans[i] = j + 1;
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            ans[i] = -1;
        }
    }
    cout << "Process No.\tProcess Size\tBlock No.\t" << endl;
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