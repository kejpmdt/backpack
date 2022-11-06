#include <cstdio>
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
	node*gen;
	Tree(void);
	~Tree(void);
};
Tree::Tree(void){
	gen=nullptr;
	return;
}
Tree::~Tree(void){
	delete gen;
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
int main(){
}