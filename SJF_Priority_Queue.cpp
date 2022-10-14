#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;// {burst time, pid}
    map<int, vector<int>> m; // process : {burst time, completion time}
    int current_time = 0;
    float avgWaitingTime = 0;
    int np;
    cout << "Enter number of processes: ";
    cin >> np;
    for (int i = 0; i < np; i++)
    {
        pair<int, int> ptemp;
        cout << "PID" << i+1 << ": ";
        cin >> ptemp.second;
        cout << "Burst Time: ";
        cin >> ptemp.first;
        pq.push(ptemp);
        m[ptemp.second].push_back(ptemp.first);
    }

    while(!pq.empty())
    {
        pair<int, int> pt = pq.top();
        pq.pop();

        current_time += pt.first;

        m[pt.second].push_back(current_time);

    }
    cout << "Process\t\tBurst Time\t\tCompletion Time\t\tWaiting Time" << endl;
    for(auto i : m)
    {
        cout << i.first << "\t\t" << i.second[0] << "\t\t\t" << i.second[1] << "\t\t\t" << i.second[1]-i.second[0] << endl;
        avgWaitingTime += i.second[1]-i.second[0];
    }
    cout << endl << "Gantt Chart" << endl;
    cout << " ";
    for (int i = 0; i < np; i++)
    {
        cout << "----------------";
    }
    cout << endl;
    for (int i = 0; i < np; i++)
    {
        cout << "|\tP" << i+1 << "\t";
    }
    cout << "|" << endl;

    cout << 0;
    for (auto i : m)
    {
        cout << "---------------"  << i.second[1];
    }

    cout << endl << "Average Waiting Time: " << avgWaitingTime/np;
    
    
    
    return 0;
}