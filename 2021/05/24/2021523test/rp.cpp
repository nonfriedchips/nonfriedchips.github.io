/*************************************************************************
    > File Name: rp/rp.cpp
    > Author: non_fried_chips
    > Mail: 15100009668@163.com 
    > Created Time: 2021年05月23日 星期日 07时58分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int unsigned int
int n, q;
int x, y;
int ax, ay;
int ans;
#define lowbit(x) ((x) & -(x))
inline int highbit(int a){
	int res;
	while(a){
		res = a;
		a -= lowbit(a);
	}
	return res;
}
signed main(){
	freopen("rp.in", "r", stdin);
	freopen("rp.out", "w", stdout);
	scanf("%u%u", &n, &q);
	for(int i = 1; i <= q; i++){
		scanf("%u%u", &x, &y);
		ans = 0;
		ax = highbit(x), ay = highbit(y);
		if(ax < ay) swap(ax, ay), swap(x, y);
		while(ax > ay){
			ax >>= 1;
			x >>= 1;
			++ans;
		}
		while(x != y){
			x >>= 1;
			y >>= 1;
			ans+=2;
		}
		printf("%u\n", ans);
	}
}
