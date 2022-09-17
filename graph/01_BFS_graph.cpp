/* 
In this program we going to code the BFS(breadth first search ) of graph 
it is same as levelorder traversal of trees

so there is 2 main or essitial things i.e,
1. visite
2. exploring 

-> here order and and (bfs) dosent matter, the thing matter's is to visit each node 
-> here we are using adjacency matrix for represnting the edges and adjacent vertex
that all  let get started
*/
#include<bits/stdc++.h>

using namespace std;

// one thing can also be done that we initalise every varible/ array/ even matrix globally 
// so we don't have to pass it again and again

void BFS(int G[][8] , int start ,int n)
{
    queue<int > Q;
        int visited[8]={0}; 
    cout<< start << " ";
    Q.push(start);
     visited[start]=1; // this is teken because to make account of , which element are visited and which are not
    while(!Q.empty())
    {
         start = Q.front();
        Q.pop();

        for(int i = 1; i < n; i++)
        {
          if(G[start][i] == 1 && visited[i] == 0)
          {
              cout<< i << " ";
              visited[i]=1;
              Q.push(i);
          }
        }
    }
}

int main()
{
   int G[8][8]{
    {0, 0, 0, 0, 0, 0, 0, 0},   
    {0, 0, 1, 1, 1, 0, 0 ,0},
    {0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},    
   };
  // calling function BFS  for trversal/ visting a tree
 // in this function we pass 2nd parameter as start vertex
   BFS(G,2,8);
     
     return 0;
}