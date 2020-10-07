#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
    int p, l, r;
};

Node T[MAX];
int n, D[MAX];

void print(int u) {
    int i, c;
    cout << "node: " << u << ": ";
    cout << "parent: " << T[u].p << ", ";
    cout << "depth: " << D[u] << ", ";

    if (T[u].p == NIL) cout << "root, ";
    else if (T[u].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
        if (i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

void rec(int u, int p) {
    D[u] = p; /* rootノードのdepthに0を設定する */
    if ( T[u].r != NIL ) rec(T[u].r, p);
    if ( T[u].l != NIL ) rec(T[u].l, p+1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++ ) T[i].p = T[i].l = T[i].r = NIL;

    for (int i = 0; i < n; i++) {
        int id, k, c, l;
        cin >> id;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            if (j == 0) T[i].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = id;
        }
    }

    int r;
    for (int i = 0; i < n; i++) {
        if (T[i].p == NIL) r = i;
    }
    rec(r, 0);

    for (int i = 0; i < n; i++) print(i);

    return 0;
}
