// Count connected components and printing

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

vector<int> adj[N];
bool vis[N+1];

vector<vector<int>> cc;
vector<int> temp;

void dfs(int vertex)
{
	vis[vertex] = true;
	temp.push_back(vertex);
	
	for(int child:adj[vertex])
	{
		if(!vis[child]) dfs(child);
	}
}

int main()
{
	
	int v,e;
	cin>>v>>e;
	
	for(int i=1;i<=e;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		
	    adj[v1].push_back(v2);
	    adj[v2].push_back(v1);
	}
	
	int count = 0;
	for(int i=1;i<=v;i++)
	{
		
		
		
		if(!vis[i])
		{ temp.clear();
			dfs(i);
			count++;
			cc.push_back(temp);	
		}
	}
	cout<<cc.size()<<endl;
	
	for(auto ver:cc)
	{
		for(int x:ver)
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
