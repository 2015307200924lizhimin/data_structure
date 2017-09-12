#include<bits/stdc++.h>
using namespace std;
struct List
{
    int sz;
    int *elem;
    List(int _sz)
    {
        sz=_sz;
        elem=new int[sz];
    }
};
void List_insert(List ls,int x,int p)
{
    for(int i=ls.sz;i>x;i--)
    {
        ls.elem[i]=ls.elem[i-1];
    }
    ls.sz++;
    ls.elem[x]=p;
    return ;
}
void List_delete(List &ls,int x)
{
    for(int i=x;i<ls.sz-1;i++)
    {
        ls.elem[i]=ls.elem[i+1];
    }
    ls.sz--;
    return ;
}
int List_find(List ls,int x)
{
    return ls.elem[x];
}
void List_clear(List& ls)
{
    delete[] ls.elem;
    return ;
}
int joseph(List &a,int k)
{
    int i=k-1;
    int cnt=0;
    int mod=a.sz;
    bool vis[mod];
    memset(vis,false,sizeof(vis));
    while(cnt<mod-1)
    {
        cnt++;
        vis[i%mod]=true;
        cout<<a.elem[i%mod]<<" ";
        i+=k;
    }
    cout<<endl;
    for(int i=0;i<mod;i++)
    {
        if(!vis[i])
            return a.elem[i];
    }
}
int main()
{
    List a(10);
    for(int i=0;i<10;i++)
    {
        a.elem[i]=i;
    }
    cout<<joseph(a,3)<<endl;
    return 0;
}
