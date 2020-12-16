#include<stdio.h>
#include<stdlib.h>
int A[10][10],n,d[10],p[10];
void bell(){
	int i,u,v;
	for(i=1;i<n;i++){
		for(u=0;u<n;u++){
			for(v=0;v<n;v++){
				if(d[v] > d[u] +A[u][v]){
					d[v] = d[u] + A[u][v];
					p[v] = u;
				}
			}
		}
	}
	for(u=0;u<n;u++){
		for(v=0;v<n;v++){
			if(d[v] > d[u] + A[u][v]){
				printf("negative edge");
			}
		}
	}
}
int main(){
	int s,des;
	printf("enter the no of vertices: ");
	scanf("%d",&n);
	printf("enter the source and destination: ");
	scanf("%d",&s);
	scanf("%d",&des);
	printf("enter the adjacency matrix");
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);

	int source;
	for(source=0;source<n;source++){
		for(i=0;i<n;i++){
			d[i] = 999;
			p[i] = -1;
		}
		d[source] = 0;
		bell();
		if(source == s)
		{printf("router %d\n",source);
		for(i=0;i<n;i++){
			if (i != source){
				j = i;
				while(p[j] != -1){
					//printf("%d <- ",j);
					j = p[j];
				}
			}
			if(i==des)
			printf("%d\tcost %d\n\n",i,d[i]);
		}}
	}
	return 0;
}