#include<bits/stdc++.h>
using namespace std;
const double pi=3.14159;
int main(){
    int h,r;
    cin>>h>>r;
    double v=h*r*r*pi/1000;
    cout<<ceil(20/v);
}