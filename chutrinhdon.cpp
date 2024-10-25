#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll nmax=10e5+5;
ll n,m,a,b,st,en,trace[nmax];
bool avalid[nmax];
vector <int> dsk[nmax];
vector <int> lk;

bool dfs( int u)
{
	avalid[u]=1;
	for(int v:dsk[u])
	    if(avalid[v]==0)
		{
			trace[v]=u;
			if(dfs(v))return true;
			
		}
		else if(v!=trace[u]){
				st=v;en=u;
				return true;
			}
	
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	cin>>a>>b;
    	dsk[a].push_back(b);
    	dsk[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	    sort(dsk[i].begin(),dsk[i].end());
	    
	    
	memset(avalid,0,n);
	for(int i=1;i<=n;i++)
	if(avalid[i]==0)
		if(dfs(i)==1)
		{
			cout<<"YES\n";
			lk.clear();
			lk.push_back(st);
			while(en!=st)
			{
				lk.push_back(en);
				en=trace[en];
			}
			for(int v:lk)cout<<v<<" ";
			return 0;
	}
			cout<<"NO\n";

    return 0;
}

