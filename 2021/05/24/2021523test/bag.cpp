/*************************************************************************
    > File Name: bag/bag-zhengjie.cpp
    > Author: non_fried_chips
    > Mail: 15100009668@163.com 
    > Created Time: 2021年05月23日 星期日 10时43分52秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n, m, k, half;
ll m1;
typedef long long ll;
const int N = 1e5+5;
ll left_sum, right_sum;
priority_queue <int> left_chose;
multiset <int> right_chose;
multiset <int>::iterator iter;
priority_queue <int, vector<int>, greater<int> > rest;
priority_queue <int, vector<int>, greater<int> > del;
struct node{
	int v, w;
	bool operator < (const node & other)const{
		return w > other.w;
	}
}a[N];
int main(){
	freopen("bag.in", "r", stdin);
	freopen("bag.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &a[i].v, &a[i].w);
	}
	sort(a+1, a+n+1);
	half = k >> 1;
	m1 = (ll)m;
	for(int i = 1; i <= half; i++){
		left_chose.push(a[i].v);
		left_sum += (ll)a[i].v;
	}
	for(int i = half+2; i <= n; i++){
		rest.push(a[i].v);
	}
	for(int i = 1; i <= half; i++){
		right_sum += (ll)rest.top();
		right_chose.insert(rest.top());
		rest.pop();
	}
	for(int i = half+1; i <= n-half; i++){
		if(left_sum + right_sum + (ll)a[i].v <= m1){
			printf("%d\n", a[i].w);
			return 0;
		}
		if(a[i].v < left_chose.top()){
			left_sum -= (ll)left_chose.top();
			left_chose.pop();
			left_chose.push(a[i].v);
			left_sum += (ll)a[i].v;
		}
		iter = right_chose.find(a[i+1].v);
		if(iter == right_chose.end()){
			del.push(a[i+1].v);
		}else{
			right_sum -= (ll)*iter;
			right_chose.erase(iter);
			while(del.size() && rest.top() == del.top()){
				rest.pop(); del.pop();
			}
			right_chose.insert(rest.top());
			right_sum += (ll)rest.top();
			rest.pop();
		}
	}
	printf("-1\n");
}
