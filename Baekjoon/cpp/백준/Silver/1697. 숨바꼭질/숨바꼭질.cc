#include <iostream>
#include <queue>
using namespace std;

int n, k, time;
int visit[100001];

void bfs(int n){
	queue<int> q;
	q.push(n);
	
	while(!q.empty()){
		int size = q.size();
		
		for(int i=0 ; i<size ; i++){
			int x = q.front();
			q.pop();
			if(x == k) return;
			visit[x]++;
			if(x+1 >= 0 && x+1 <= 100000 && visit[x+1] == 0) q.push(x+1);
			if(x-1 >= 0 && x-1 <= 100000 && visit[x-1] == 0) q.push(x-1);
			if(2*x >= 0 && 2*x <= 100000 && visit[2*x] == 0) q.push(2*x);
		}
		time++;
	}	
}

int main()
{
	cin >> n >> k;
	
	bfs(n);
	
	cout << time;
}