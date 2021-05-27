#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int tag[N], son[N][2], fa[N], size[N];
int n, m;
int l, r;
int root;
#define ls son[p][0]
#define rs son[p][1]
inline void pushup(int p){ size[p] = size[ls] + size[rs] + 1; }
inline void pushdown(int p){
    if(tag[p]){
        swap(ls, rs);
        tag[ls] ^= 1, tag[rs] ^= 1;
        tag[p] = 0;
    }
}
inline bool is_left(int p) { return son[fa[p]][0] == p; }
void rotate(int p){
    pushdown(fa[p]), pushdown(p);
    bool flag = is_left(p);
    int f = fa[p], gr = fa[f], so = son[p][flag];
    fa[so] = f;
    fa[p] = gr;
    son[gr][is_left(f)^1] = p;
    fa[f] = p;
    son[p][flag] = f;
    son[f][flag^1] = so;
    pushup(f), pushup(p);
}
int find(int rank, int p){
    // printf("%d\n", p);
    // getchar();
    pushdown(p);
    if(rank == size[ls]+1) return p;
    if(size[ls] >= rank) return find(rank, ls);
    return find(rank - size[ls] - 1, rs);
}
void splay(int p, int opt){
    while(1){
        // printf("%d\n", fa[p]);
        // getchar();
        if(opt == 1){
            if(fa[p] == 0) return;
            if(fa[fa[p]] == 0){
                rotate(p);
                return;
            }
        }else{
            if(fa[fa[p]] == 0) return;
            if(fa[fa[fa[p]]] == 0){
                rotate(p);
                return;
            }
        }
        pushdown(fa[p]), pushdown(p);
        if(is_left(p) == is_left(fa[p])) rotate(fa[p]);
        else rotate(p);
        rotate(p);
    }
}
int build(int s, int t, int f){
    if(t < s) return 0;
    if(s == t){
        fa[s] = f;
        size[s] = 1;
        return s;
    }
    int mid = s + t >> 1;
    son[mid][0] = build(s, mid-1, mid);
    son[mid][1] = build(mid+1, t, mid);
    fa[mid] = f;
    size[mid] = size[son[mid][0]] + size[son[mid][1]] + 1;
    return mid;
}
void print(int p){
    if(p == 0) return;
    pushdown(p);
    print(ls);
    if(p > 1 && p < n+2) printf("%d ", p - 1);
    print(rs);
}
void pu(int p){
    if(p == 0) return;
    pushdown(p);
    pu(ls);
    pu(rs);
}
int main(){
    scanf("%d%d", &n, &m);
    root = build(1, n+2, 0);
    while(m--){
        scanf("%d%d", &l, &r);
        root = find(l, root);
        splay(root, 1);
        splay(find(r+2, root), 2);
        tag[son[son[root][1]][0]] ^= 1;
        // print(root);
        // pu(root);
    }
    print(root);
}