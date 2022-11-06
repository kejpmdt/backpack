#include<cstdio>
using namespace std;
class Splay{
public:
	class node{
	private:
	public:
		int data,sum;
		int num;
		int l,r;
	}*nodes;
	int root;
private:
	const int maxsize;
	int nodenum;
	inline void maintain(int now){
		nodes[now].sum=nodes[now].num+nodes[nodes[now].l].sum+nodes[nodes[now].r].sum;
	}
	inline void newnode(int&now,int&data){
		nodes[now=++nodenum].data=data;
		nodes[nodenum].sum=nodes[nodenum].num=1;
	}
	inline void zig(int&now){
		int l=nodes[now].l;
		nodes[now].l=nodes[l].r;
		nodes[l].r=now;
		now=l;
		maintain(nodes[now].r),maintain(now);
	}
	inline void zag(int&now){
		int r=nodes[now].r;
		nodes[now].r=nodes[r].l;
		nodes[r].l=now;
		now=r;
		maintain(nodes[now].l),maintain(now);
	}
	void splay(int x,int&y){
		if(x==y)return;
		int&l=nodes[y].l,&r=nodes[y].r;
		if(x==l)zig(y);
		else if(x==r)zag(y);
		else{
			if(nodes[x].data<nodes[y].data){
				if(nodes[x].data<nodes[l].data){
					splay(x,nodes[l].l),zig(y),zig(y);
				}
				else {
					splay(x,nodes[l].r),zag(l),zig(y);
				}
			}
			else{
				if(nodes[x].data<nodes[r].data){
					splay(x,nodes[r].r),zag(y),zag(y);
				}
				else {
					splay(x,nodes[r].l),zig(r),zag(y);
				}
			}
		}
	}
	inline void delnode(int now){
		splay(now,root);
		if(nodes[now].num>1)--nodes[now].sum,++nodes[now].num;
		else if(nodes[root].r){
			int p=nodes[root].r;
			while(nodes[p].l)p=nodes[p].l;
			splay(p,nodes[root].r);
			nodes[nodes[root].r].l=nodes[root].l;
			root=nodes[root].r;
			maintain(root);
		}
		else root=nodes[root].l;
	}
	void ins(int&now,int&data){
		if(!now)newnode(now,data),splay(now,root);
		else if(data<nodes[now].data)ins(nodes[now].l,data);
		else if(data>nodes[now].data)ins(nodes[now].r,data);
		else ++nodes[now].sum,++nodes[now].num,splay(now,root);
	}
	void del(int now,int&data){
		if(nodes[now].data==data)delnode(now);
		else if(data<nodes[now].data)del(nodes[now].l,data);
		else del(nodes[now].r,data);
	}
public:
    void insert(int data){
        if(!root)newnode(root,data);
        else ins(root,data);
    }
    void remove(int data){
        del(root,data);
    }
	Splay(int spacesize):maxsize(spacesize){
		nodenum=0;
		nodes=new node[maxsize];
        root=0;
	}
	int getrank(int data){
		int now=root,rank=1;
		while(now){
			if(nodes[now].data==data){
				rank+=nodes[nodes[now].l].sum;
				splay(now,root);
				break;
			}
			if(data<=nodes[now].data){
				now=nodes[now].l;
			}
			else {
				rank+=nodes[nodes[now].l].sum+nodes[now].num;
				now=nodes[now].r;
			}
		}
		return rank;
	}
	int getnum(int rank){
		int now=root;
		while(now){
			int lsize=nodes[nodes[now].l].sum;
			if(lsize+1<=rank&&rank<=lsize+nodes[now].num){
				splay(now,root);
				break;
			}
			else if(lsize>=rank){
				now=nodes[now].l;
			}
			else{
				rank-=lsize+nodes[now].num;
				now=nodes[now].r;
			}
		}
		return nodes[now].data;
	}
};
Splay*Tree;
int main(){
	int n;
	scanf("%d",&n);
	int opt,x;
	Tree=new Splay(100005);
	for(int i=0;i<n;++i){
		scanf("%d%d",&opt,&x);
		if(opt==1){
			Tree->insert(x);
		}
		if(opt==2){
			Tree->remove(x);
		}
		if(opt==3){
			printf("%d\n",Tree->getrank(x));
		}
		if(opt==4){
			printf("%d\n",Tree->getnum(x));
		}
		if(opt==5){
			printf("%d\n",Tree->getnum(Tree->getrank(x)-1));
		}
		if(opt==6){
			printf("%d\n",Tree->getnum(Tree->getrank(x)+Tree->nodes[Tree->root].num));
		}
	}
	return 0;
}
