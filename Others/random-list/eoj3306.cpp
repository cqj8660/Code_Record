#include <bits/stdc++.h>

using namespace std;
const long long maxn = 5e5 + 10;
map<long long, long long> mp;
long long f[maxn], a[maxn];
int main(){
	long long p, n1, n2, n3, n4;
	scanf("%lld%lld%lld%lld%lld", &p, &n1, &n2, &n3, &n4);
	//cout << n4 * 25 + n3 * 10 + n2 * 5 + n1 << endl;
	bool flag = true;
	if(n1 < p % 5) cout << "Impossible" << endl;
	else if(n1 >= p) {
		cout << p << endl;
	}
	else if(n2 * 5 + n1 >= p) {
		while(n1 % 5 != p % 5){
			n1--;
		}
		cout << n1 + (p - n1) / 5 << endl;
	}
	else if(n3 * 10 + n2 * 5 + n1 >= p){
		while(n1 % 5 != p % 5){
			n1--;
		}
		long long pp = p - n1;
		if(n2 == 0){
			if(pp % 10 == 0){
				cout << n1 + pp / 10 << endl;
			}
			else {
				if(n4 > 0){
					if(pp >= 25){
						pp -= 25;
						cout << n1 + 1 + pp / 10 << endl;
					}
					else if(pp >= 5 && n1 >= 5){
						pp += 5;
						cout << n1 - 5 + pp / 10 << endl;
					}
					else flag = false;
				}
				else if(pp >= 5 && n1 >= 5){
					pp += 5;
					cout << n1 - 5 + pp / 10 << endl;
				}
				else flag = false;
			}
		}
		else {
			if(pp % 10 && n2 % 2 == 0) n2--;
			else if(pp % 10 == 0 && n2 % 2) n2--;
			cout << n1 + n2 + (pp - n2 * 5) / 10 << endl;
		}
	}
	else if(n4 * 25 + n3 * 10 + n2 * 5 + n1 >= p){
		//cout << "ll" << endl;
		while(n1 % 5 != p % 5){
			n1--;
		}
		long long pp = p - n1;
		long long cnt = 0;
		while(n3 * 10 + n2 * 5 < pp){
			while(pp < 25){
				pp += 5;
				if(n1 >= 5) n1 -= 5;
				else flag = false;
			}
			pp -= 25;
			cnt++;
		}
		//cout << pp << endl;
		//cout << cnt << endl;
		n4 = n4 - cnt;
		if(n2 == 0){
			if(pp % 10 == 0){
				cout << n1 + pp / 10 + cnt << endl;
			}
			else {
				if(n4 > 0){
					if(pp >= 25){
						pp -= 25;
						cout << n1 + 1 + pp / 10 + cnt << endl;
					}
					else if(pp >= 5 && n1 >= 5){
						pp += 5;
						cout << n1 - 5 + pp / 10 + cnt << endl;
					}
					else flag = false;
				}
				else if(pp >= 5 && n1 >= 5){
						pp += 5;
						cout << n1 - 5 + pp / 10 + cnt << endl;
				}
				else flag = false;
			}
		}
		else {
			if(n2 * 5 >= pp) cout << n1 + pp / 5 + cnt << endl;
			else{
				if(pp % 10 && n2 % 2 == 0) n2--;
				else if(pp % 10 == 0 && n2 % 2) n2--;
				cout << n1 + n2 + (pp - n2 * 5) / 10 + cnt << endl;
			}
		}
	}
	else flag = false;
	if(flag == false) cout << "Impossible" << endl;
}
