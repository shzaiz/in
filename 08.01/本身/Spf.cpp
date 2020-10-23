void SPFA(int s){
	Queue Q, int[] vis, int[]dis;
	vis[s] = 1;
	dis[s] = 0;
	Q.push(s);	
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		vis[u] = 0;
		for(i = head[u];i;i = e[i].nxt){
			v = e[i].to;
			if(dis[v]>dis[u]+e[i].val){
				dis[v] = dis[u]+e[i].val;
				if(!vis[v]){
					vis[v]= 1;
					Q.push(v);
				}
			}
		}
	}
}
