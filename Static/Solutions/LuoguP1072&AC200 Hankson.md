本题是一道非常不错的数论题目，知识点主要用到：

- 唯一拆分定理。
- 最大公约数 `gcd` 与最小公倍数 `lcm` 的定义。

我们先来看一下题目：

> 有一个数 $x$，你知道 $\gcd(x,a)=b,\operatorname{lcm}(x,c)=d$，让你求 $x$ 可能的个数。

首先，由于 $\gcd$ 与 $\operatorname{lcm}$ 的特点，我们将其进行唯一拆分，存到 `set` 里面。

这里安利一下我的常用代码：

```c++
map<int,int>cf(int x){
    map<int,int>res;
    res.clear();
    for(int i=2;i*i<=x;++i)while(x%i==0)++res.insert({i,0}).first->second,x/=i;
    if(x>1)++res.insert({x,0}).first->second;
    return res;
}
```

存到 `map` 和 `set` 是同理的。

然后，我们判断一下，因为无论如何，最小公倍数是倍数，最大公约数是约数，所以：

> 不存在任何一个数，使得 $\operatorname{lcm}$ 不是 $\gcd$ 的倍数。

也就是说，当 $d$ 不是 $b$ 的倍数时，$x$ 不存在。

之后，我们遍历一下所有的质因子，进行逐一判断。

如果 $\gcd$ 的某一质因子次数与另一个数的相同，那么 $x$ 的次数只要比这个次数大即可。

$\operatorname{lcm}$ 同理。

但是，如果不同，那么 $x$ 的次数就必须是这个了，没得选择。

如果 $\gcd$ 的限制和 $\operatorname {lcm}$ 的限制冲突，则 $x$ 不存在。

所以，我们得到如下代码：

```c++
#include<bits/stdc++.h>
using namespace std;
map<int,int>cf(int x){
    map<int,int>res;
    res.clear();
    for(int i=2;i*i<=x;++i)while(x%i==0)++res.insert({i,0}).first->second,x/=i;
    if(x>1)++res.insert({x,0}).first->second;
    return res;
}
int main(){
    int n;
    cin>>n;
    int a0,a1,b0,b1;
    while(n--){
        cin>>a0>>a1>>b0>>b1;
        auto ca0=cf(a0),ca1=cf(a1);
        auto cb0=cf(b0),cb1=cf(b1);
        if(b1%a1!=0){
            cout<<0<<endl;
            continue;
        }
        int ans=1;
        for(auto i:cb1){
            if(cb0[i.first]!=cb1[i.first]||ca0[i.first]!=ca1[i.first]){
                if(cb0[i.first]!=cb1[i.first]&&ca0[i.first]!=ca1[i.first]&&cb1[i.first]!=ca1[i.first]){
                    ans=0;
                    break;
                }
                continue;
            }
            ans*=(cb1[i.first]-ca1[i.first]+1);
        }
        cout<<ans<<endl;
    }
}

```

善用 `auto`，从我做起。