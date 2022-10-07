

#include<bits/stdc++.h>
using namespace std;
#define MAX  132000
#define Left st, (st+en)/2 , nd+nd
#define Right (st+en)/2+1 , en, nd+nd+1

const int N = (1<<18);
int tree[2*N], arr[N+5];
bool oor;

bool build(int st, int en, int nd){
    if(st==en){
        tree[nd]=arr[st];
        return 1;
    }
    oor = build(Left);
    oor = build(Right);
    if(oor){
       tree[nd] = (tree[nd+nd] | tree[nd+nd+1]);
    }
    else{
       tree[nd] = (tree[nd+nd] ^ tree[nd+nd+1]);
    }

    return !oor;
}

bool update(int st, int en, int nd, int idx, int value){
    if(st==en){
        tree[nd]=value;
        return 1;
    }
    int m = (st+en)/2;
    if(idx<=m)
       oor = update(Left, idx, value);
    else
       oor = update(Right, idx, value);
    if(oor){
       tree[nd] = (tree[nd+nd] | tree[nd+nd+1]);
    }
    else{
       tree[nd] = (tree[nd+nd] ^ tree[nd+nd+1]);
    }

    return !oor;
}


int main()
{
    int n, m, a, b;
    cin>>n>>m;
    int tm = 1;
    for(int i=1 ; i<=n ; i++) tm *= 2; n = tm;
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    build(0, n-1, 1);
    for(int i=1 ; i<=m ; i++){
        cin>>a>>b;
        int idx=a, value = b;
        update(0, n-1, 1, idx-1, value);
        cout<<tree[1]<<"\n";

    }




return 0;
}

