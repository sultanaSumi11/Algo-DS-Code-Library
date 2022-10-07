#include<bits/stdc++.h>
using namespace std;
#define MAX  100000
#define Left st, (st+en)/2 , nd+nd
#define Right (st+en)/2+1 , en, nd+nd+1


int tree[4*MAX], arr[MAX+5];

void build(int st, int en, int nd){
    if(st==en){
        tree[nd]=arr[st];
        return;
    }
    build(Left);
    build(Right);
    tree[nd] = tree[nd+nd] + tree[nd+nd+1];
}

int query(int st, int en, int nd, int L, int R){
    if(R<st || L>en) return 0;
    if(L<=st && R>=en) return tree[nd];
    return query(Left, L, R)+query(Right, L, R);
}

void update(int st, int en , int nd, int idx, int value){
    if(idx<st || idx>en) return;
    if(st==idx && en==idx){
        tree[nd]=value;
        return;
    }
    update(Left, idx, value);
    update(Right, idx, value);
    tree[nd] = tree[nd+nd] + tree[nd+nd+1];
}

int main()
{
    int n, Q, a, b;
    char ch;
    cin>>n;
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    cin>>Q;
    build(0, n-1 , 1);
    for(int i=1 ; i<=Q ; i++){
        cin>>ch>>a>>b;
        if(ch=='1'){
            int idx = a;
            int value=b;
            update(0, n-1, 1, idx, value);
        }
        else{
            int L = a;
            int R = b;
            int ans = query(0, n-1, 1, L, R);
            cout<<ans<<'\n';
        }
    }




return 0;
}
