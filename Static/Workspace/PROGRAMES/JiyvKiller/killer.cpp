#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
int main(){
    bool pd=false;
    bool lst=false;
    freopen("err.txt","w",stderr);
    while(1){
        bool x=KEY_DOWN('P');
        if(pd)system("taskkill /im a.exe");
        if(x){
            if(lst)continue;
            else pd^=1;
            system("cls");
            cout<<pd;
        }
        lst=x;
        Sleep(100);
    }
}