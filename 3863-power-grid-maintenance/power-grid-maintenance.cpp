#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    // ==== CONFIG (adjust per constraints) ====
    static const int MAXC = 200000 + 5;
    static const int MAXE = 200000 + 5;
    static const int MAXQ = 200000 + 5;

    // ===== DSU (arrays) =====
    int parentArr[MAXC], sizeArr[MAXC];
    void dsu_init(int n){
        for(int i=0;i<=n;i++){ parentArr[i]=i; sizeArr[i]=1; }
    }
    int dsu_find(int x){
        while(parentArr[x]!=x){ parentArr[x]=parentArr[parentArr[x]]; x=parentArr[x]; }
        return x;
    }
    void dsu_unite(int a,int b){
        a=dsu_find(a); b=dsu_find(b);
        if(a==b) return;
        if(sizeArr[a]<sizeArr[b]){ int t=a; a=b; b=t; }
        parentArr[b]=a; sizeArr[a]+=sizeArr[b];
    }

    // ===== Treap (ordered set of ints) =====
    struct TNode{
        int key, pri, l, r;
    };
    TNode pool[MAXC*2]; // enough if each node appears once; adjust if needed
    int poolPtr=0;

    int newNode(int key){
        ++poolPtr;
        pool[poolPtr].key = key;
        pool[poolPtr].pri = ((rand()<<16) ^ rand()); // simple RNG
        pool[poolPtr].l = pool[poolPtr].r = 0;
        return poolPtr;
    }

    void split(int root, int key, int &L, int &R){
        if(!root){ L=R=0; return; }
        if(pool[root].key <= key){
            split(pool[root].r, key, pool[root].r, R);
            L = root;
        }else{
            split(pool[root].l, key, L, pool[root].l);
            R = root;
        }
    }
    int merge(int A, int B){
        if(!A||!B) return A?A:B;
        if(pool[A].pri > pool[B].pri){
            pool[A].r = merge(pool[A].r, B);
            return A;
        }else{
            pool[B].l = merge(A, pool[B].l);
            return B;
        }
    }
    int insertNode(int root, int key){
        int L,R; split(root, key, L, R);
        // ensure uniqueness: check if key already exists (optional)
        // We can merge L with a single node (if not already present)
        // To enforce set behavior, split L at key-1 to see if key already in R.
        // Simpler (and fine here): always insert; duplicates won't happen in our use.
        int M = newNode(key);
        return merge(merge(L,M), R);
    }
    int eraseNode(int root, int key){
        if(!root) return 0;
        if(pool[root].key == key){
            return merge(pool[root].l, pool[root].r);
        }else if(key < pool[root].key){
            pool[root].l = eraseNode(pool[root].l, key);
            return root;
        }else{
            pool[root].r = eraseNode(pool[root].r, key);
            return root;
        }
    }
    int getMinKey(int root){
        if(!root) return -1;
        while(pool[root].l) root = pool[root].l;
        return pool[root].key;
    }

    // One treap root per DSU root id
    int treapRoot[MAXC];

    char online[MAXC];

    int edgesU[MAXE], edgesV[MAXE];
    int qType[MAXQ], qX[MAXQ];

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        int m = (int)connections.size();
        int qn = (int)queries.size();
        for(int i=0;i<m;i++){
            edgesU[i] = connections[i][0];
            edgesV[i] = connections[i][1];
        }
        for(int i=0;i<qn;i++){
            qType[i] = queries[i][0];
            qX[i]    = queries[i][1];
        }
        dsu_init(c);
        for(int i=0;i<m;i++){
            dsu_unite(edgesU[i], edgesV[i]);
        }
        for(int i=0;i<=c;i++){ treapRoot[i]=0; online[i]=0; }
        poolPtr = 0;
        for(int v=1; v<=c; v++){
            int r = dsu_find(v);
            treapRoot[r] = insertNode(treapRoot[r], v);
            online[v]=1;
        }

        vector<int> out; out.reserve(qn);
        for(int i=0;i<qn;i++){
            int t = qType[i], x = qX[i];
            int r = dsu_find(x);
            if(t==1){
                if(online[x]) out.push_back(x);
                else{
                    int mn = getMinKey(treapRoot[r]);
                    out.push_back(mn == 0 ? -1 : (mn==-1? -1 : mn));
                }
            }else{ // t == 2
                if(online[x]){
                    online[x]=0;
                    treapRoot[r] = eraseNode(treapRoot[r], x);
                }
            }
        }
        return out;
    }
};

