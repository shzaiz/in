#include <bits/stdc++.h>
typedef long long ll;
#define pair <int, int> P
#define sc(N) scanf("%lld", &N);
using namespace std;
int N;
string s;
int A[100005];

int main()
{
    cin >> s;
    int n = s.length();
    int j = 0;
    for (int i = 0; i < n;) {
        // cout<<i<<endl;
        if (s[i] == 'R') {
            while (s[i + j] == 'R') {
                j++;
            }

            int k = i + j;
            i = i + j;
            while (j > 0) {
                if (j & 1)
                    A[k - 1]++;
                else
                    A[k]++;
                j--;
            }

        } else
            i++;
    }

    for (int i = n - 1; i >= 0;) {
        //cout<<i<<endl;
        j = 0;
        if (s[i] == 'L') {
            while (s[i - j] == 'L') {
                j++;
            }
            //i=i-j;
            int k = i - j;
            i = i - j;
            while (j > 0) {
                if (j & 1)
                    A[k + 1]++;
                else
                    A[k]++;
                j--;
            }

        } else
            i--;
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << '\n';
    return 0;
}