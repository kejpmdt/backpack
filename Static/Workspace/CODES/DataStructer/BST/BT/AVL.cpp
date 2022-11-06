#include<cstdio>
#define mx2(a,b) (a>b?a:b)
//----------------------------------
class AVL{
	public:
		class node{
			public:
				int data;
				int num;
				int height;
				int size;
				int balance;
				node*fa;
				node*lc;
				node*rc;
				bool pd;
				node(void);
				~node(void);
				void zag(void);
				void zig(void);
				int rank(void);
				void recheck(void);
				void show(const int);
		};
		node*gen;
		node*us;
		AVL(void);
		~AVL(void);
		node* newnode(int);
		void push(int);
		void del(int);
		int rank(int);
		int ranker(int);
		void findbyrank(int);
		void findbyvalue(int);
		node*fronter(int);
		node*nexter(int);
		void refindgen(void);
		void upcheck(node*);
		void show(void);
};
void connect(AVL::node*,AVL::node*,bool);
int read(void);
int main();
AVL Tree1;
AVL::node*checker;
int main(){
	int n,opt,x;
	n=read();
	while(n--){
		opt=read();x=read();
		if(opt==1)Tree1.push(x);
		if(opt==2)Tree1.del(x);
		if(opt==3)printf("%d\n",Tree1.rank(x));
		if(opt==4)printf("%d\n",Tree1.ranker(x));
		if(opt==5)printf("%d\n",Tree1.fronter(x)->data);
		if(opt==6)printf("%d\n",Tree1.nexter(x)->data);
	}
	return 0;
}
inline void connect(AVL::node*a,AVL::node*b,bool x){
	if(x)a->lc=b;
	else a->rc=b;
	b->pd=x;
	b->fa=a;
	a->recheck();
	b->recheck();
	return;
}
inline int read(void){
	int ans=0;
	bool f=false;
	char us=getchar();
	while(us<'0'||us>'9'){
		f|=(us=='-');
		us=getchar();
	}
	while(us>='0'&&us<='9'){
		ans=(ans<<1)+(ans<<3)+(us^48);
		us=getchar();
	}
	return f?-ans:ans;
}
AVL::node::node(void){
	fa=nullptr;
	lc=nullptr;
	rc=nullptr;
	num=1;
	height=1;
	size=1;
	balance=0;
}
AVL::node::~node(void){
	while(1){
		if(!lc&&!rc)break;
		if(!lc)zag();
		if(!rc)zig();
		if(lc&&rc)
			if(lc->size<rc->size)zag();
			else zig();
	}
	if(fa){
		if(pd)fa->lc=nullptr;
		else fa->rc=nullptr;
		checker=fa;
	}
	else checker=nullptr;
	return;
}
inline void AVL::node::zig(void){
	if(!lc)return;
	if(fa)
		if(pd)fa->lc=lc;
		else fa->rc=lc;
	lc->fa=fa;
	fa=lc;
	fa->pd=pd;
	lc=fa->rc;
	if(lc){
		lc->fa=this;
		lc->pd=true;
	}
	fa->rc=this;
	pd=false;
	recheck();
	fa->recheck();
}
inline void AVL::node::zag(void){
	if(!rc)return;
	if(fa)
		if(pd)fa->lc=rc;
		else fa->rc=rc;
	rc->fa=fa;
	fa=rc;
	fa->pd=pd;
	rc=fa->lc;
	if(rc){
		rc->fa=this;
		rc->pd=false;
	}
	fa->lc=this;
	pd=true;
	recheck();
	fa->recheck();
}
inline int AVL::node::rank(void){
	int ans=0;
	AVL::node* us=this;
	if(lc)ans+=lc->size;
	while(us->fa){
		if(us->pd==false){
			ans+=us->fa->size;
			ans-=us->size;
		}
		us=us->fa;
	}
	return ans+1;
}
inline void AVL::node::recheck(void){
	height=0;
	size=num;
	balance=0;
	if(lc){
		size+=lc->size;
		balance+=lc->height;
		height=mx2(height,lc->height);
	}
	if(rc){
		size+=rc->size;
		balance-=rc->height;
		height=mx2(height,rc->height);
	}
	++height;
	return;
}
void AVL::node::show(const int x){
	for(int i=0;i<x;++i)printf("|  ");
	printf("%c %5d%5d%5d%3d%5d%3d%3d\n",(pd?'L':'R'),data,num,height,balance,size,lc?1:0,rc?1:0);
	if(lc)lc->show(x+1);
	if(rc)rc->show(x+1);
	return;
}
AVL::node* AVL::newnode(int x){
	node*us=new node;
	us->data=x;
}
AVL::AVL(void){
	gen=nullptr;
	us=nullptr;
}
AVL::~AVL(void){
	us=gen;
	while(us){
		if(!us->lc&&!us->rc){
			if(us->fa){
				us=us->fa;
				if(us->lc)delete us->lc;
				else delete us->rc;
			}
			else{
				delete gen;
				gen=nullptr;
				break;
			}
			break;
		}
		if(us->lc)us=us->lc;
		if(us->rc)us=us->rc;
	}
	return;
}
inline void AVL::push(int x){
	if(!gen){
		gen=newnode(x);
		return;
	}
	us=gen;
	while(1)
		if(us->data==x){
			++us->num;
			upcheck(us);
			break;
		}
		else if(us->data>x)
			if(us->lc)us=us->lc;
			else{
				us->lc=newnode(x);
				us->lc->fa=us;
				us->lc->pd=true;
				upcheck(us->lc);
				break;
			}
		else
			if(us->rc)us=us->rc;
			else{
				us->rc=newnode(x);
				us->rc->fa=us;
				us->rc->pd=false;
				upcheck(us->rc);
				break;
			}
	return;
}
inline void AVL::del(int x){
	findbyvalue(x);
	--us->num;
	--us->size;
	checker=us;
	upcheck(checker);
	if(us->num==0){
		if(us->fa)delete us;
		else{
			if(us->lc)gen=us->lc;
			if(us->rc)gen=us->rc;
			if(!us->lc&&!us->rc)gen=nullptr;
			delete us;
			refindgen();
		}
		if(checker)upcheck(checker);
	}
}
inline void AVL::findbyvalue(int x){
	us=gen;
	while(1)
		if(us->data==x)break;
		else if(us->data>x)us=us->lc;
		else us=us->rc;
	return;
}
inline void AVL::findbyrank(int x){
	us=gen;
	while(us){
		if(us->lc&&us->lc->size>=x){
			us=us->lc;
			continue;
		}
		if(us->lc&&us->lc->size<x)x-=us->lc->size;
		if(us->num>=x)break;
		if(us->rc){
			x-=us->num;
			us=us->rc;
			continue;
		}
		if(us->num<x&&!us->rc)break;
	}
	return;
}
AVL::node*AVL::fronter(int x){
	us=gen;
	node* us1;
	while(1)
		if(us->data>=x)
			if(!us->lc)break;
			else us=us->lc;
		else{
			us1=us;
			if(!us->rc)break;
			else us=us->rc;
		}
	return us1;
}
AVL::node*AVL::nexter(int x){
	us=gen;
	node* us1;
	while(1)
		if(us->data<=x)
			if(!us->rc)break;
			else us=us->rc;
		else{
			us1=us;
			if(!us->lc)break;
			else us=us->lc;
		}
	return us1;
}
inline void AVL::refindgen(void){
	while(gen)
		if(gen->fa)gen=gen->fa;
		else break;
	return;
}
inline void AVL::upcheck(AVL::node*x){
	checker=x;
	checker->recheck();
	while(checker->fa){
		checker=checker->fa;
		checker->recheck();
		if(checker->balance==2)
			if(checker->lc->balance==1)checker->zig();
			else {
				checker->lc->zag();
				checker->zig();
			}
		if(checker->balance==-2)
			if(checker->rc->balance==-1)checker->zag();
			else {
				checker->rc->zig();
				checker->zag();
			}
	}
	refindgen();
}
inline int AVL::rank(int x){
	findbyvalue(x);
	return us->rank();
}
inline int AVL::ranker(int x){
	findbyrank(x);
	return us->data;
}
void AVL::show(void){
	printf("===\\\n");
	if(gen)gen->show(1);
	printf("===/\n");
	return;
}
