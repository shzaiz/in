# include <bits/stdc++.h>
using namespace std;

struct Person {
	string A;
	int B, C;
} a[100000];

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].A >> a[i].B >> a[i].C;
		a[i].B++, a[i].C = a[i].C / 5 * 6;
		if (a[i].C > 600) a[i].C = 600;
		cout << a[i].A << " " << a[i].B << " " << a[i].C << endl;
	}
}