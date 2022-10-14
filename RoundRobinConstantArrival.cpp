#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> m;
void ganttChart()
{
    
    cout << endl << "Gantt Chart" << endl;
    cout << " ";
    for (int i = 0; i < n; i++)
    {
        cout << "----------------";
    }
    cout << endl;
    for (auto i : m)
    {
        cout << "|\tP" << i.first << "\t";
    }
    cout << "|" << endl;

    cout << 0;
    for (auto i : m)
    {
        cout << "---------------"  << i.second;
    }
}

int main()
{
    
    
    map<int, int> m_burst;
    int current_time = 0;
    int avgWaitingTime = 0;
    cout << "Enter number of processes: ";
    cin >> n;
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++)
    {
        int p_id; 
        cout << "Enter process ID: ";
        cin >> p_id;
        
        int bt;
        cout << "Enter burst time: ";
        cin >> bt;
        m_burst[p_id] = bt;
        pair<int, int> p;
        p.first = p_id;
        p.second = bt;
        
        q.push({p_id, bt});
        
    }
    int tq; 
    cout << "Enter time quantum: ";
    cin >> tq;
    
    while(!q.empty())
    {
        pair<int, int> p_temp = q.front();
        q.pop();
        if(p_temp.second <= tq)
        {
            current_time += p_temp.second;
            m[p_temp.first] = current_time;
        }
        else
        {
            p_temp.second -= tq;
            current_time += tq;
            q.push({p_temp.first, p_temp.second});
        } 
    }
    
    cout << "P. Id" << "\t\t" << "Burst Time" << "\t\t" << "Completion Time\t\t" << "Waiting Time"<< endl;
    for(auto i : m)
    {
        cout << i.first << "\t\t" << m_burst[i.first] << "\t\t\t" << i.second << "\t\t\t" << i.second-m_burst[i.first] << endl;
        avgWaitingTime += i.second-m_burst[i.first];
    }

    cout << endl << "Average Waiting Time: " << avgWaitingTime/n;
    ganttChart();

    return 0;
}