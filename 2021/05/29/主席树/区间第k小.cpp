#include<bits/stdc++.h>
using std::cin;
using std::cout;
const int N = 2e5+5;
int n, m;
int a[N], mp[N], len;
int st[N*20], l[N*20], r[N*20], root[N], num;
int x, y, z;
int change(int a, int s, int t, int p){
    int u = ++num;
    l[u] = l[p];
    r[u] = r[p];
    st[u] = st[p] + 1;
    int mid = s + t >> 1;
    if(s < t){
        if(mid >= a) l[num] = change(a, s, mid, l[p]);
        else r[num] = change(a, mid+1, t, r[p]);
    }
    return u;
}
int query(int opt, int s, int t, int a, int b){
    if(s == t)
        return s;
    int mid = s + t >> 1;
    if(st[l[b]] - st[l[a]] >= opt) return query(opt, s, mid, l[a], l[b]);
    return query(opt-(st[l[b]] - st[l[a]]), mid+1, t, r[a], r[b]);
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; mp[i] = a[i];
    }
    std::sort(mp+1, mp+n+1);
    len = std::unique(mp+1, mp+n+1) - mp - 1;
    for(int i = 1; i <= n; i++){
        root[i] = change(std::lower_bound(mp+1, mp+len+1, a[i]) - mp, 1, n, root[i-1]);
    }
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        cout << mp[query(z, 1, n, root[x-1], root[y])] << '\n';
    }
    cout.flush();
}