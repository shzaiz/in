#include <bits/stdc++.h>
using namespace std;
int _[55] = {0,
19,20,21,4,5,6,7,8,9, //前 
28,29,30,13,14,15,16,17,18, // 后 
10,11,12,22,23,24,25,26,27, // 左 
1,2,3,31,32,33,34,35,36, // 右 
39,42,45,38,41,44,37,40,43, // 上 
46,47,48,49,50,51,52,53,54};

int __[55]={0,1,2,39,4,5,42,7,8,45, //前 
54,11,12,51,14,15,48,17,18,// 后 
19,20,21,22,23,24,25,26,27, // 左 
30,33,36,29,32,35,28,31,34, // 右 
37,38,16,40,41,13,43,44,10, // 上 
46,47,3,49,50,6,52,53,9 // 下 
};
int ___[55]={0,1,2,48,4,5,51,7,8,54,45,11,12,42,14,15,39,17,18,19,20,21,22,23,24,25,26,27,34,31,28,35,32,29,36,33,30,37,38,3,40,41,6,43,44,9,46,47,16,49,50,13,52,53,10};
int ____[55]={0,
19,20,21,4,5,6,7,8,9, //前 
28,29,30,13,14,15,16,17,18, // 后 
10,11,12,22,23,24,25,26,27, // 左 
1,2,3,31,32,33,34,35,36, // 右 
39,42,45,38,41,44,37,40,43, // 上 
46,47,48,49,50,51,52,53,54, // 下 
};
int ______[55]={0,28,29,30,4,5,6,7,8,9,19,20,21,13,14,15,16,17,18,1,2,3,22,23,24,25,26,27,10,11,12,31,32,33,34,35,36,43,40,37,44,41,38,45,42,39,46,47,48,49,50,51,52,53,54};

int num[55] = {};
int prv[55];
int seq[55]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54}; 
int a1[55]={0,1,2,39,4,5,42,7,8,45,10,11,48,13,14,51,16,17,54,19,20,21,22,23,24,25,26,27,30,33,36,29,32,35,28,31,34,37,38,12,40,41,15,43,44,18,46,47,3,49,50,6,52,53,9 // 下 
};
int a2[55]={0,1,2,48,4,5,51,7,8,54,10,11,39,13,14,42,16,17,45,19,20,21,22,23,24,25,26,27,34,31,28,35,32,29,36,33,30,37,38,3,40,41,6,43,44,9,46,47,12,49,50,15,52,53,18};
int a3[55]={0,
19,20,21,4,5,6,7,8,9,28,29,30,13,14,15,16,17,18,10,11,12,22,23,24,25,26,27,1,2,3,31,32,33,34,35,36,43,40,37,44,41,38,45,42,39,46,47,48,49,50,51,52,53,54
};
int a4[55]={0,28,29,30,4,5,6,7,8,9,19,20,21,13,14,15,16,17,18,1,2,3,22,23,24,25,26,27,10,11,12,31,32,33,34,35,36,39,42,45,38,41,44,37,40,43,46,47,48,49,50,51,52,53,54};
void translate(int A[55]){
	int seqq[55];
	for(int i=1;i<55;i++){
		seqq[i] = seq[i];
	}
	int ans[55];
	for(int i=1;i<55;i++){
		ans[i] = seqq[A[i]];
	}
	for(int i=1;i<55;i++){
		seq[i] = ans[i];
	}
}
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
//	translate(a4);
	string s;
	cin>>s;
	int len = s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='1') translate(a2);
		else if(s[i]=='2') translate(a1);
		else if(s[i]=='3') translate(a3);
		else if(s[i]=='4') translate(a4); 
	}
	for(int i=0;i<(54/3);i++){
		int s; cin>>s;
		num[i*3+1] = s/100;
		num[i*3+2] = s/10%10;
		num[i*3+3] = s%10;
	}
	for(int i=1;i<=54;i++){//? 
		cout<<num[seq[i]]<<(i%3==0?"\n":""); //样例有锅…… 
	}
	
}
