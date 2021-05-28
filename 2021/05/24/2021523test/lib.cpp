/*************************************************************************
    > File Name: lib/lib.cpp
    > Author: non_fried_chips
    > Mail: 15100009668@163.com 
    > Created Time: 2021年05月23日 星期日 09时18分41秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+5;
char opt[15];
typedef long long ll;
ll num[N];
ll x;
int t, a, b, ans;
bool rem[N];
#define ls (p << 1)
#define rs (p << 1 | 1)
void pushdown(int p){
	if(rem[p]){
		rem[ls] = rem[rs] = 1;
		num[ls] = num[rs] = 0;
		rem[p] = 0;
	}
}
void change(ll a, int id, int s, int t, int p){
	if(s == t){
		num[p] += a;
		return;
	}
	int mid = s + t >> 1;
	pushdown(p);
	if(mid >= id) change(a, id, s, mid, ls);
	else change(a, id, mid+1, t, rs);
	num[p] = num[ls] + num[rs];
}
void remove(int id, int s, int t, int p){
	if(t <= id){
		rem[p] = 1;
		num[p] = 0;
		return;
	}
	int mid = s + t >> 1;
	pushdown(p);
	remove(id, s, mid, ls);
	if(mid < id) remove(id, mid+1, t, rs);
	num[p] = num[ls] + num[rs];
}
ll query(int l, int r, int s, int t, int p){
	if(l <= s && t <= r){
		return num[p];
	}
	int mid = s + t >> 1;
	pushdown(p);
	ll res = 0;
	if(mid >= l) res += query(l, r, s, mid, ls);
	if(mid < r) res += query(l, r, mid+1, t, rs);
	return res;
}
int lis(ll a, int s, int t, int p){
	if(s == t){
		return s;
	}
	int mid = s + t >> 1;
	pushdown(p);
	if(num[rs] >= a) return lis(a, mid+1, t, rs);
	return lis(a - num[rs], s, mid, ls);
}
int main(){
	freopen("lib.in", "r", stdin);
	freopen("lib.out", "e", stdout);
	scanf("%d", &n);
	while(~scanf("%s", opt)){
		if(opt[0] == 'Q') return 0;
		if(opt[0] == 'A'){
			scanf("%d%lld", &t, &x);
			change(x, t, 1, n, 1);
		}else if(opt[0] == 'R'){
			scanf("%d", &t);
			if(t == 1){
				printf("0\n");
			}else{
				printf("%lld\n", query(1, t-1, 1, n, 1));
				remove(t-1, 1, n, 1);
			}
		}else if(opt[0] == 'C'){
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(a, b, 1, n, 1));
		}else{
			scanf("%lld", &x);
			if(num[1] < x) printf("No\n");
			else printf("%d\n", lis(x, 1, n, 1));
		}
	}
}



