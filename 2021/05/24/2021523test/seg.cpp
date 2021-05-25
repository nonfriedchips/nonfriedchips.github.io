/*************************************************************************
    > File Name: seg/seg.cpp
    > Author: non_fried_chips
    > Mail: 15100009668@163.com 
    > Created Time: 2021年05月23日 星期日 09时04分08秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
int x, y;
struct node{
	int l, r;
	node(int a = 0, int b = 0){
		l = a, r = b;
	}
}ans;
void ask(int x, node & a){
	if(x == 1){
		a.l = 1, a.r = n;
		return;
	}
	ask(x>>1, a);
	if(x & 1) a.l  = (a.l + a.r >> 1)+1;
	else a.r = a.l + a.r >> 1;
}
int main(){
	freopen("seg.in", "r", stdin);
	freopen("seg.out", "w", stdout);
	scanf("%d%d", &n, &q);
	while(q--){
		scanf("%d%d", &x, &y);
		ask(y, ans);
		if(ans.l > x){
			printf("0\n");
		}else{
			ans.r = min(ans.r, x);
			printf("%lld\n", ((ll)(ans.l + ans.r) * (ll)(ans.r - ans.l+1))>>1);
		}
	}
}
