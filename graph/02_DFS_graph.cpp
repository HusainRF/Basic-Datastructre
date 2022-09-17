/* 
In this program we going to code the DFS(depth first search) of graph
it is same as preorder traversal of trees(if we know the tree) 

so there is 2 main or essitial things i.e,
1. visite
2. exploring

-> here order and and (dfs) dosent matter, the thing matter's is to visit each node 
-> here we are using adjacency matrix for represnting the edges and adjacent vertex
that all  let get started
*/
#include<bits/stdc++.h>

using namespace std;

// one thing can also be done that we initalise every varible/ array/ even matrix globally 
// so we don't have to pass it again and again

void DFS(int G[][8] ,int start, int n)
{
   static int visited[8] = {0};
   if(visited[start] == 0)
   {      visited[start]=1;
        cout<< start << " " ;
       for(int i=1 ; i < n ; i++)
       {   
           if(G[start][i]==1 && visited[i]==0)
                 DFS( G, i, 8);     
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

  // calling function DFS  for trversal/ visting a tree
  // in this function we pass 2nd parameter as start vertex
   DFS(G,1,8);
     
   return 0;
}