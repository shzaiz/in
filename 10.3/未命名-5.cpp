int get(int n,int l){
		long long ans=0;
	    memset(tmp,0,sizeof(tmp));
	    memset(c,0,sizeof(c));
	    for(int i=1;i<=n;i++){
	    	scanf("%d",&a[i]);
	    	lsh[i] = a[i];
	    	
	    }
	    sort(lsh+1 , lsh+n+1);
		int cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;
		for(int i=1; i<=n; i++)
			a[i] = (cnt+1)-(lower_bound(lsh+1 , lsh+cnt+1 , a[i]) - lsh);
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
      	    a[i]++;
           	tmp[i]=sum(a[i]-1);
            add(a[i],1); 
        }
        memset(c,0,sizeof(c));
        for(int i=n;i>=1;i--){
        	ans+=(long long)sum(a[i]-1)*tmp[i];
        	add(a[i],1);
        }
        printf("\n%lld\n",ans);
}