#include<cstdio>
#define mx2(a,b) (a>b?a:b)
using namespace std;
class Tree;
class Tree{
public:
	class node{
	public:
		int data;
		node*fst;
		node*nt;
		node*fa;
		node(void);
		~node(void);
	};
	node*root;
	Tree(void);
	~Tree(void);
};
Tree::Tree(void){
	root=nullptr;
	return;
}
Tree::~Tree(void){
	delete root;
	return;
}
Tree::node::node(void){
	data=0;
	fst=nt=fa=nullptr;
	return;
}
Tree::node::~node(void){
	if(nt)delete nt;
	if(fst)delete fst;
	return;
}
//----------------------------
//****************************
//----------------------------
int diameter(Tree*);
void dia(Tree::node*,int&,int&);
int diameter(Tree*T){
	int a=0,b=0;
	dia(T->root,a,b);
	return a;
}
void dia(Tree::node*nw,int& large,int& height){
	int u,b;
	int us=0;
	for(auto i=nw->fst;i;i=i->nt){
		dia(i,u,b);
		if(b+1>=height){
			us=height-1;
			height=b+1;
		}
		large=mx2(large,u);
	}
	large=mx2(large,us+height);
	return;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",a+b);
}
