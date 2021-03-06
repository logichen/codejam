#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

#include "pedge.h"

int n,e,d[20],f[20],t,cnd[20];

int SortFunction(const void *a,const void *b)
{
   int i=*((int *)a);
   int j=*((int *)b);
   if(f[i]<f[j]) return 1;
   if(f[i]>f[j]) return -1;
   return 0;
}

void Topo(int node)
{
  int i,v;
  static int j=0;
  d[node]=++t;
  cnd[j++]=node;
  i=NodeHead[node];
  while(i!=NIL)
  {
    v=EdgeList[i].dst;
    if(d[v]==0) Topo(v);
    i=EdgeList[i].next;
  }
  f[node]=++t;
 }
calcir()
{
   int a,b;
   for(a=1;a<=n;a++)
     for(b=1;b<=n;b++)

}
main()
{
 int i,src,dst,nd[20];
 clrscr();
 freopen("dfs.in","r",stdin);
 scanf("%d%d",&n,&e);
 for(i=0;i<=n;i++)
 {
    d[i]=f[i]=NIL;
    nd[i]=i;
 }
 EdgeInit(n);
 for(i=1;i<=2*e;i+=2)
 {
   scanf("%d%d",&src,&dst);
   InsertEdge(src,dst,NIL,i);
   InsertEdge(dst,src,NIL,i+1);
 }
 t=0;
 for(i=1;i<=n;i++)
 {
   if(d[i]==0) Topo(i);calcir();
 }
 qsort((void *) (nd+1),n,sizeof(nd[0]),SortFunction);
 for(i=1;i<=n;i++)
 {
   printf("%d\n",*(nd+i));
 }
 fclose(stdin);
 printf("\nOK");
}