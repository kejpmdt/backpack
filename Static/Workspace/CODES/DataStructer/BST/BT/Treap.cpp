#include<cstdio>
using namespace std;
class Treap;
class Treap{
	public:
		class node{
			public:
				int data;
				unsigned int weight;
				int size;
				int num;
				bool pd;
				node*lc;
				node*rc;
				node*fa;
				node(void);
				~node(void);
				void zig(void);
				void zag(void);
				int rank(void);
				void recheck(void);
				void show(const int);
				unsigned int mrand(void);
		};
		Treap(void);
		~Treap(void);
		node*gen;
		node*us;
		node*us1;
		void push(int);
		void del(int);
		void findbyvalue(int);
		void findbyrank(int);
		node*fronter(int);
		node*nexter(int);
		void refindgen(void);
		void upcheck(node*);
		int rank(int);
		int ranker(int);
		node*newnode(int);
		void show(void);
};
Treap::node*checker;
void connect(Treap::node*,Treap::node*,bool);
int read(void);
int main();
Treap Tree1;
int main(){
	if(true){
		freopen("us.txt","r",stdin);
		freopen("Treap.txt","w",stdout);
	}
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
inline void connect(Treap::node*a,Treap::node*b,bool x){
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
Treap::node* Treap::newnode(int x){
	Treap::node*us=new Treap::node;
	us->data=x;
	us->num=1;
	us->size=1;
	return us;
}
Treap::node::node(void){
	weight=mrand();
	fa=lc=rc=nullptr;
}
Treap::node::~node(void){
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
inline void Treap::node::zig(void){
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
inline void Treap::node::zag(void){
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
inline unsigned int Treap::node::mrand(void){
	static unsigned int seed=1;
	seed=seed*48271ll%21448473647;
	return seed;
}
inline int Treap::node::rank(void){
	int ans=0;
	Treap::node* us=this;
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
inline void Treap::node::recheck(void){
	size=num;
	if(lc)size+=lc->size;
	if(rc)size+=rc->size;
}
void Treap::node::show(const int x){
	for(int i=0;i<x;++i)printf("|  ");
	printf("%c %5d%5d%15u%5d%3d%3d\n",(pd?'L':'R'),data,num,weight,size,lc?1:0,rc?1:0);
	if(lc)lc->show(x+1);
	if(rc)rc->show(x+1);
	return;
}
Treap::Treap(void){
	gen=nullptr;
	us=nullptr;
	us1=nullptr;
}
Treap::~Treap(void){
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
inline void Treap::push(int x){
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
inline void Treap::del(int x){
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
inline void Treap::findbyvalue(int x){
	us=gen;
	while(1)
		if(us->data==x)break;
		else if(us->data>x)us=us->lc;
		else us=us->rc;
	return;
}
inline void Treap::findbyrank(int x){
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
Treap::node*Treap::fronter(int x){
	us=gen;
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
Treap::node*Treap::nexter(int x){
	us=gen;
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
inline void Treap::refindgen(void){
	while(gen)
		if(gen->fa)gen=gen->fa;
		else break;
	return;
}
inline void Treap::upcheck(node*x){
	Treap::node*us=x;
	while(us->fa)
		if(us->fa->weight>=us->weight)break;
		else
			if(us->fa->fa)
				if(us->pd)us->fa->zig();
				else us->fa->zag();
			else{
				gen=us;
				if(us->pd)us->fa->zig();
				else us->fa->zag();
			}
	us->recheck();
	while(us->fa){
		us->fa->recheck();
		us=us->fa;
	}
	refindgen();
	return;
}
inline int Treap::rank(int x){
	findbyvalue(x);
	return us->rank();
}
inline int Treap::ranker(int x){
	findbyrank(x);
	return us->data;
}
void Treap::show(void){
	printf("===\\\n");
	if(gen)gen->show(1);
	printf("===/\n");
	return;
}
