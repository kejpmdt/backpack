#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
__gnu_pbds::tree<double,__gnu_pbds::null_type,std::less<double>,__gnu_pbds::rb_tree_tag,tree_order_statistics_node_update>tr;
int main(){
    int n;
    cin>>n;
    int x;
    int opt;
    for(int i=1;i<=n;++i){
        cin>>opt>>x;
        if(opt==1)tr.insert(x+(n+1)*1e-6);
        if(opt==2)tr.erase(tr.lower_bound(x));
        if(opt==3)cout<<(int)tr.order_of_key(x)+1<<'\12';
        if(opt==4)cout<<(int)*tr.find_by_order(x-1)<<'\12';
        if(opt==5)cout<<(int)*(--tr.lower_bound(x))<<'\12';
        if(opt==6)cout<<(int)*tr.upper_bound(x+1)<<'\12';
    }
}
/*

#include <cstdio>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<double, null_mapped_type, greater<double>, rb_tree_tag, tree_order_statistics_node_update> T;

int main()
{
	//freopen("3369.in", "r", stdin);
	//freopen("3369.out", "w", stdout);

	int q, opt, x;

	scanf("%d", &q);
	for (int i = 1; i <= q; ++ i)
	{
		scanf("%d%d", &opt, &x);
		if(opt == 1) 
			T.insert(x + i * 1e-6);
		//插入一个数
		if(opt == 2) 
			T.erase(T.lower_bound(x));
		//删除一个数
		if(opt == 3) 
			printf("%d\n", (int)T.order_of_key(x) + 1);
		//查询一个数的排名
		if(opt == 4) 
			printf("%d\n", (int)*T.find_by_order(x - 1));
		//查询第k小的数 返回的是一个迭代器 这里k是从0开始算的，意思是最小的数是第0小的
		if(opt == 5) 
			printf("%d\n", (int)round(*(-- T.lower_bound(x))));
		//查询一个数的前驱
		if(opt == 6) 
			printf("%d\n", (int)round(*T.lower_bound(x + 1)));
		//查询一个数的后继
	}

	return 0;
}
*/