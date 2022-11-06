#include<cstdio>
using namespace std;
class Graph{
   private:
      const int MAX_N;
      const int MAX_M;
   public:
      Graph(int n,int m):MAX_N(n),MAX_M(m){
         nodes=new node[MAX_N+1];
         fst=new int[MAX_N+1];
         nt=new int[MAX_M+1];
         to=new int[MAX_M+1];
         v=new int[MAX_M+1];
      }
      void init(int n,int m);
      void addline(int i,int u,int t,int w=1){
         to[i]=t;
         nt[i]=fst[u];
         fst[u]=i;
         v[i]=w;
      }
      int *fst;
      int *nt;
      int *to;
      int *v;
      class node{
         public:
      }*nodes;
};
