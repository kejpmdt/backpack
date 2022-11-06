#include<cstdio>
using namespace std;
template<class T>:
class Splay{
public:
	node* root;
	void add(T*,int);
	node* findbydata(T*);
	class node{
	public:
		T* data;
		int sum;
		int weight;
		node*fa;
		node*lc;
		node*rc;
		Splay*belong;
		node(T*,int,Splay*);
		~node(void);
		void maintain(void);
		int get(void);
		void Splay(node*);
		void rotate(void);
		void add(T*,int);
		node*fnidbydata(T*);
	private:
	};
private:
};
void Splay::add(T*data,int num){
	if(!root)root=new node(data,1,this);
	else return root->add(data,num);
}
node* Splay::findbydata(T*data){
	if(!root)return nullptr;
	return root->findbydata(data);
}
Splay::node::node(T* newdata,int addnum,Splay*anc):data(newdata),weight(addnum),belong(anc){};
Splay::node::~node(void){
}
void Splay::node::maintain(void){
	sum=weight;
	if(lc)sum+=lc->sum;
	if(rc)sum+=rc->sum;
	return;
}
int Splay::node::get(void){
	if(fa->lc==this)return 1;
	else return 0;
}
void Splay::node::Splay(node*to=nullptr){
	while(fa!=to){
		if(fa->fa==to)rotate();
		else if(get()!=fa->get())rotate(),rotate();
		else fa->rotate(),rotate();
	}
}
void Splay::node::rotate(void){
	if(!fa)return;
	if(get()){
		if(rc){
			rc->fa=fa;
			fa->lc=rc;
		}
		rc=fa;
		fa=fa->fa;
		rc->fa=this;
		if(fa){
			if(fa->lc==rc)fa->lc=this;
			else fa->rc=this;
		}
	}
	else{
		if(lc){
			lc->fa=fa;
			fa->rc=lc;
		}
		lc=fa;
		fa=fa->fa;
		lc->fa=this;
		if(fa){
			if(fa->rc==lc)fa->rc=this;
			else fa->lc=this;
		}
	}
}
void Splay::node::add(T*newdata,int addnum){
	if(*newdata==*data){
		weight+=addnum;
		Splay();
	}
	if(*newdata<*data){
		if(!lc)lc=new node(newdata,addnum,belong);
		else return lc->add(newdata,addnum);
	}
	else {
		if(!rc)rc=new node(newdata,addnum,belong);
		else return rc->add(newdata,addnum);
	}
}
node* Splay::node::findbydata(T*finddata){
	if(*finddata==*data){
		Splay();
		return this;
	}
	if(*finddata<*data){
		if(!lc)return nullptr;
		return lc->dinfbydata(finddata);
	}
	else{
		if(!rc)return nullptr;
		return rc->dinfbydata(finddata);
	}
}








