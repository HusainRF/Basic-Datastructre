/*
program to implement Breadth first traversal
*/
#include<stdio.h>

int a[20][20], q[20], visit[20], n, i, j, f = 0, r = -1;

void BFS(int v) {

for(i = 1; i <= n; i++)
if(a[v][i] && !visit[i])
q[++r] = i;
if(f <= r) {
visit[q[f]] = 1;
BFS(q[f++]);
}

}

void main() {
int v;
printf("Enter the number of vertices: ");
scanf("%d",&n);
for(i=1; i <= n; i++) {
q[i] = 0;
visit[i] = 0;
}
printf("\nEnter graph data in matrix form:\n");
for(i=1; i<=n; i++) {
for(j=1;j<=n;j++) {
scanf("%d", &a[i][j]);
}
}
printf("Enter the starting vertex: ");
scanf("%d", &v);
BFS(v);
printf("\nThe node which are reachable are:");
for(i=1; i <= n; i++) {
if(visit[i])
printf(" %d", i);
else {
printf("\nBFS is not possible. All nodes are not reachable!");
break;
}
}
}