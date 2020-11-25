/*
PROG: alice
AUTH: Nettle
STAT: AC
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAXL 109

int m[ MAXL ][ MAXL ], s[ MAXL ], N, M, Ans;
bool use[ MAXL ], step[ MAXL ];

void swap(int &a, int &b)
{
int c = a;
    a = b; b = c;
    return ;
}

void Xor(int l, int r)
{
    for (int i = 1; i <= N; i++)
        m[r][i] ^= m[l][i];
    s[r] ^= s[l];
    return ;
}

void DFS(int dep, int cnt)
{
	int flag;
    if (cnt >= Ans) return ;
    if (dep == 0) {
        if (cnt < Ans) {
			Ans = cnt;
			memcpy(step, use, sizeof(step));
		}
        return ;
    }
    if (m[dep][dep]) {
        flag = s[dep];
        for (int i = dep + 1; i <= N; i++)
            if (m[dep][i]) flag ^= use[i];
        use[dep] = flag;
        if (flag) DFS(dep - 1, cnt + 1);
            else DFS(dep - 1, cnt);
        return ;
    }
    use[dep] = true;
    DFS(dep - 1, cnt + 1);
    use[dep] = false;
    DFS(dep - 1, cnt);
    return ;
}

int main()
{
	freopen("alice.in", "r", stdin);
	freopen("alice.out", "w", stdout);
	
	int a, b;
	bool flag;
	
    scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &s[i]);
		s[i] ^= 1, m[i][i] = 1;
	}
    while (M--) {
        scanf("%d %d", &a, &b);
        m[a][b] = m[b][a] = 1;
    }
	
    for (int i = 1; i <= N; i++) {
        flag = false;
        for (int j = i; j <= N; j++)
            if (m[j][i]) {
                for (int t = 1; t <= N; t++)
                    swap(m[i][t], m[j][t]);
                swap(s[i], s[j]);
                flag = true;
                break;
            }
        if (!flag) continue;
        for (int j = i + 1; j <= N; j++)
            if (m[j][i]) Xor(i, j);
    }
	
	int check(0);
	for (int i = 1; i <= N; i++) {
		check = 0;
		for (int j = 1; j <= N; j++)
			check |= m[i][j];
 	}
    Ans = MAXL;
    DFS(N, 0);
    printf("%d\n", Ans);
	int cnt(0);
	for (int i = 1; i <= N; i++)
		if (step[i]) {
			if (++cnt != 1) printf(" ");
			printf("%d", i);
		}
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
    return 0;
}
