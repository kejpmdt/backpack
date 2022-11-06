#include<cstdio>
using namespace std;
inline int read(void){
    static int ans;
    static bool f;
    static char us=getchar();
    ans=0;
    f=false;
    while(us<48||us>57){
        f|=(us==45);
        us=getchar();
    }
    while(us>47&&us<58){
        ans=(ans<<1)+(ans<<3)+(us^48);
        us=getchar();
    }
    return f?-ans:ans;
}
bool put(int x){
    return putchar(x>9?put(x/10),x%10|48:x%10|48),true;
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1)printf("I\nI\n+ 1 2\n+ 3 3\n- 4\nO 5\n");
    if(n==2)printf("I\n< 1 4\n+ 1 2\n- 3\nS 4\nO 5\n");
    if(n==3)printf("I\n< 1 100\nS 2\nC 3 -0.5\n< 4 1\nO 5\n");
    if(n==4)printf("I\n- 1\nM 1 2\n O 3\n");
    if(n==5)printf("I\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\nI\n< 1 1\n+ 33 2\n< 34 1\n+ 35 3\n< 36 1\n+ 37 4\n< 38 1\n+ 39 5\n< 40 1\n+ 41 6\n< 42 1\n+ 43 7\n< 44 1\n+ 45 8\n< 46 1\n+ 47 9\n< 48 1\n+ 49 10\n< 50 1\n+ 51 11\n< 52 1\n+ 53 12\n< 54 1\n+ 55 13\n< 56 1\n+ 57 14\n< 58 1\n+ 59 15\n< 60 1\n+ 61 16\n< 62 1\n+ 63 17\n< 64 1\n+ 65 18\n< 66 1\n+ 67 19\n< 68 1\n+ 69 20\n< 70 1\n+ 71 21\n< 72 1\n+ 73 22\n< 74 1\n+ 75 23\n< 76 1\n+ 77 24\n< 78 1\n+ 79 25\n< 80 1\n+ 81 26\n< 82 1\n+ 83 27\n< 84 1\n+ 85 28\n< 86 1\n+ 87 29\n< 88 1\n+ 89 30\n< 90 1\n+ 91 31\n< 92 1\n+ 93 32\nO 94\n");
    if(n==6)printf("I\n> 1 1\n< 2 1\n- 3\n+ 1 4\n> 2 1\n< 6 1\n- 7\n+ 5 8\n> 6 1\n< 10 1\n- 11\n+ 9 12\n> 10 1\n< 14 1\n- 15\n+ 13 16\n> 14 1\n< 18 1\n- 19\n+ 17 20\n> 18 1\n< 22 1\n- 23\n+ 21 24\n> 22 1\n< 26 1\n- 27\n+ 25 28\n> 26 1\n< 30 1\n- 31\n+ 29 32\n> 30 1\n< 34 1\n- 35\n+ 33 36\n> 34 1\n< 38 1\n- 39\n+ 37 40\n> 38 1\n< 42 1\n- 43\n+ 41 44\n> 42 1\n< 46 1\n- 47\n+ 45 48\n> 46 1\n< 50 1\n- 51\n+ 49 52\n> 50 1\n< 54 1\n- 55\n+ 53 56\n> 54 1\n< 58 1\n- 59\n+ 57 60\n> 58 1\n< 62 1\n- 63\n+ 61 64\n> 62 1\n< 66 1\n- 67\n+ 65 68\n> 66 1\n< 70 1\n- 71\n+ 69 72\n> 70 1\n< 74 1\n- 75\n+ 73 76\n> 74 1\n< 78 1\n- 79\n+ 77 80\n> 78 1\n< 82 1\n- 83\n+ 81 84\n> 82 1\n< 86 1\n- 87\n+ 85 88\n> 86 1\n< 90 1\n- 91\n+ 89 92\n> 90 1\n< 94 1\n- 95\n+ 93 96\n> 94 1\n< 98 1\n- 99\n+ 97 100\n> 98 1\n< 102 1\n- 103\n+ 101 104\n> 102 1\n< 106 1\n- 107\n+ 105 108\n> 106 1\n< 110 1\n- 111\n+ 109 112\n> 110 1\n< 114 1\n- 115\n+ 113 116\n> 114 1\n< 118 1\n- 119\n+ 117 120\n> 118 1\n< 122 1\n- 123\n+ 121 124\n> 122 1\n< 126 1\n- 127\n+ 125 128\n");

    return 0;
}