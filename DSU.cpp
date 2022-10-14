#include<bits/stdc++.h>
using namespace std;
int parent[100000];
int rank1[100000];
void makeSet()
{
    for(int i = 0; i <= 100000; i++)
    {
        parent[i] = i;
        rank1[i] = 0;
    }
}

int findPar(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}

void union1(int u, int v)
{
    u = findPar(u);
    v = findPar(v);

    if(rank1[u]<rank1[v])
    {
        parent[u] = v;
    }
    else if(rank1[v] < rank1[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank1[u]++;

    }
}

  

int main()
{
    makeSet();
    int m;
    cin >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        union1(u, v);
    }

    if(findPar(5) != findPar(6))
    {
        cout << "Different Component";
    }else cout << "Same Component";

    return 0;
}