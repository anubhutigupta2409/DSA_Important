#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
  bool solve(vector<int>adj[],int n)
    {
        vector<int>deg(n,0);
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(auto x : adj[i])
                deg[x]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            count++;
            for(auto &x : adj[temp])
            {
                deg[x] = deg[x]-1;
                if(deg[x]==0)
                    q.push(x);
            }
        }
        return (count==n);
    }
  bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
  {
      // Code here
      vector<int>adj[N];
      for(auto it=prerequisites.begin();it!=prerequisites.end();it++)
      {
          int first = (*it).first;
          int second = (*it).second;
          adj[second].push_back(first);
      }
      return (solve(adj,N));
  }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
