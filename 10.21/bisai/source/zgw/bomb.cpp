#include <bits/stdc++.h>
using namespace std;
#define N 50000005
char str[20005][1005];
int t[N][2];
int cnt = 1;
int maxlcp = -1;
int insert(string s){
    int len = s.length();int p = 0;bool unfound = 1;
    for (int i = 0; i < len; i++) {
        if (!t[p][s[i] - '0']) {
            t[p][s[i] - '0'] = ++cnt;
            if (unfound)  maxlcp = max(maxlcp, i),unfound = 0;
            
        }
        p = t[p][s[i] - '0'];
    }
}
int chk(string s1, string s2){
    int len1 = s1.length();
    int len2 = s2.length();
    int i = 0;
    for (; s1[i % len1] == s2[i % len2]; i++)
        ;
    // printf("%d",i);
    return i;
}
int main(){
#ifdef KINGXBZAKIOI
    freopen("D:/Testcases/in.ac", "r", stdin);
    freopen("D:/Testcases/out.ac", "w", stdout);
#else
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);
#endif
    int x;
    cin >> x;
    int ans = -1;
    cin >> str[1];
    for (int i = 2; i <= x; i++) {
        cin >> str[i];
        int l = strlen(str[i]);
        for (int k = l; k < 1005; k++) {
            str[i][k] = str[i][k % l];
        }
        //  printf("%s\n",str[i].c_str());
        insert(str[i]);
    }
    printf("%d\n", maxlcp);
}


// #include<bits/stdc++.h>
// using namespace std;
// string a[20001];
// string o;
// int maxx,ans,n;
// int main()
// {
//     #ifdef ONLINE_JUDGE
//     freopen("D:/Testcases/in.ac","r",stdin);
//     freopen("D:/Testcases/out.ac","w",stdout);
//     #else
//     freopen("bomb.in","r",stdin);
// 	freopen("bomb.out","w",stdout);
//     #endif
	
// 	cin>>n;
// 	for(int i=1;i<=n;i++)
// 	{
// 		cin>>a[i];
// 		o=a[i];
// 		int la=a[i].size();
// 		int gn=1000/la;
// 		if(1000%la!=0)gn++;
// 		for(int j=1;j<=gn;j++)a[i]=a[i]+o;
// 	}
	
// 	sort(a+1,a+n+1);
// 	for(int i=1;i<n;i++)
// 	{
// 		int len=0;
// 		int maxx=0;
// 		int la=a[i].size();
// 		int lla=a[i+1].size();
// 		while(a[i][len%la]==a[i+1][len%lla])
// 		{
// 			maxx++;
// 			len++;
// 		} 
// 		ans=max(ans,maxx);
// 	}
// 	cout<<ans<<endl;
//  } 
