    #include<bits/stdc++.h>
    using namespace std;
    int p1=1000000,p2=0;
    char buf[1000005],wb[1000005];
    #define gc getchar
    long long getint() {
        long long ret=0,flag=1;
        char c=gc();
        while(c<'0'||c>'9') {
            if(c=='-')flag=-1;
            c=gc();
        }
        while(c<='9'&&c>='0') {
            ret=(ret<<3)+(ret<<1)+c-'0';
            c=gc();
        }
        return ret*flag;
    }
    void pc(char x) {
        if(p2>=1000000)fwrite(wb,1,1000000,stdout),p2=0;
        wb[p2++]=x;
    }
    void wrt(long long x) {
        if(x<0)pc('-'),x=-x;
        int c[24]= {0};
        if(!x)return pc('0'),void();
        while(x)c[++c[0]]=x%10,x/=10;
        while(c[0])pc(c[c[0]--]+'0');
    }
    #define mod (long long)(1e9+7)
    char c[100005];
    long long ans=0,sum=0;
    long long ksm(long long a,long long b) {
        long long ret=1;
        while(b) {
            if(b&1)ret=ret*a%int(1e9+7);
            a=a*a%int(1e9+7);
            b>>=1;
        }
        return ret;
    }
    int main() {
        scanf("%s",c+1);
        int len=strlen(c+1);
        long long data=0;
        for(int i=1; i<=len; i++) {
            int val=(c[len-i+1]-48);
            ans=(ans+val*ksm(10,i-1)%mod*(1ll*(len-i)*(len-i-1)/2%mod+len-i)%mod)%mod;
            ans=(ans+val*data%mod)%mod;
            data=(data+i*ksm(10,i-1)%mod)%mod;
        }
        wrt(ans),pc('\n');
        fwrite(wb,1,p2,stdout);
        return 0;
    }