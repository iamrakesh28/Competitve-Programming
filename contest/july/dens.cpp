#include <iostream>

typedef long long ll;

using namespace std;

const int N = 2e5 + 5;

struct Node {
  ll val;
  int l, r;
} t1[N << 2], t2[N << 2];
int a[N], h[N];

// use sparse table later
int find_max(int l, int r) {
  int hi = -1; return hi;
  for (int i = l; i <= r; ++i)
    hi = max(hi, h[i]);
  return hi;
}

void build1(int v, int l, int r) {
  if (l == r) {
    t1[v] = {a[l], l, r};
    return;
  }
  int mid = (l + r) >> 1;
  build1(2 * v + 1, l, mid);
  build1(2 * v + 2, mid + 1, r);
  if (h[t1[2 * v + 1].r] >= h[t1[2 * v + 2].r]) {
    t1[v] = t1[2 * v + 1];
    //cout<<t1[v].val<<" "<<t1[v].l+1<<" "<<t1[v].r+1<<endl;
    return;
  }
  int li = t1[2 * v + 2].l, ri = t1[2 * v + 2].r, ind;
  ind = ri;
  for (int i = li; i < ri; ++i) {
    if (h[t1[2 * v + 1].r] < h[i]) {
      ind = i;
      break;
    }
  }
  ll sum = 0;
  int cur = h[t1[2 * v + 1].r];
  for (int i = ind; i <= ri; ++i)
    if (cur < h[i]) {
      cur = h[i];
      sum += a[i];
    }
  t1[v] = {t1[2 * v + 1].val + sum, t1[2 * v + 1].l, t1[2 * v + 2].r};
  //cout<<t1[v].val<<" "<<t1[v].l+1<<" "<<t1[v].r+1<<endl;
  return;
}

void build2(int v, int l, int r) {
  if (l == r) {
    t2[v] = {a[l], l, r};
    return;
  }
  int mid = (l + r) >> 1;
  build2(2 * v + 1, l, mid);
  build2(2 * v + 2, mid + 1, r);
  if (h[t2[2 * v + 2].l] >= h[t2[2 * v + 1].l]) {
    t2[v] = t2[2 * v + 2];
    //cout<<t2[v].val<<" "<<t2[v].l+1<<" "<<t2[v].r+1<<endl;
    return;
  }
  int li = t2[2 * v + 1].l, ri = t2[2 * v + 1].r, ind;
  ind = li;
  for (int i = ri; i > li; --i) {
    if (h[t2[2 * v + 2].l] < h[i]) {
      ind = i;
      break;
    }
  }
  ll sum = 0;
  int cur = h[t2[2 * v + 2].l];
  for (int i = ind; i >= li; --i)
    if (cur < h[i]) {
      cur = h[i];
      sum += a[i];
    }
  t2[v] = {t2[2 * v + 2].val + sum, t2[2 * v + 1].l, t2[2 * v + 2].r};
  //cout<<t2[v].val<<" "<<t2[v].l+1<<" "<<t2[v].r+1<<endl;
  return;
}

int pos1(int l, int r, int ht) {
  int ind = r;
  return l;
  for (int i = l; i < r; ++i)
    if (h[i] > ht) {
      ind = i;
      break;
    }
  return ind;
}

Node query1(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {-1, 0, 0};
  if (l == tl && tr == r)
    return t1[v];
  int mid = (tl + tr) >> 1;
  Node node1 = query1(2 * v + 1, tl, mid, l, min(mid, r));
  //Node node2 = query1(2 * v + 2, mid + 1, tr, max(l, mid + 1), r);
  if (node1.val == -1)
    return query1(2 * v + 2, mid + 1, tr, max(l, mid + 1), r);
  //if (node1.val == -1)
  //  return node2;
  //Node node2 = query1(2 * v + 2, mid + 1, tr, max(l, mid + 1), r);
  //if (node1.val == -1)
  //  return node2;
  //if (h[node1.r] >= h[node2.r])
  //  return node1;
  //int ps = pos1(node2.l, node2.r, h[node1.r]);
  //cout<<tl<<" "<<tr<<" "<<l+1<<" "<<r+1<<" "<<ps+1<<endl;
  //Node node3 = query1(v, tl, tr, ps, node2.r);
  Node node3 = query1(v, tl, tr, max(l + 1, mid + 2), r);
  return {node1.val + node3.val, node1.l, node3.r};
}

int pos2(int l, int r, int ht) {
  int ind = l;
  return r;
  for (int i = r; i > l; --i)
    if (h[i] > ht) {
      ind = i;
      break;
    }
  return ind;
}

Node query2(int v, int tl, int tr, int l, int r) {
  //cout<<tl+1<<" "<<tr+1<<" "<<l+1<<" "<<r+1<<endl;
  if (l > r)
    return {-1, 0, 0};
  if (l == tl && tr == r)
    return t2[v];
  int mid = (tl + tr) >> 1;
  Node node1 = query2(2 * v + 1, tl, mid, l, min(mid, r));
  Node node2 = query2(2 * v + 2, mid + 1, tr, max(l, mid + 1), r);
  if (node2.val == -1)
    return node1;
  if (node1.val == -1)
    return node2;//cout<<node2.l+1<<" "<<node2.r +1<<" ";
  if (h[node2.l] >= h[node1.l])
    return node2;
  int ps = pos2(node1.l, node1.r, h[node2.l]);
  //cout<<tl<<" "<<tr<<" "<<l+1<<" "<<r+1<<" "<<ps+1<<endl;
  Node node3 = query2(v, tl, tr, node1.l, ps);
  return {node2.val + node3.val, node3.l, node2.r};
}

void update1(int v, int tl, int tr, int pos, ll val) {
  if (tl == tr) {
    a[pos] += val;
    t1[v] = {a[pos], tl, tr};
    return;
  }
  int mid = (tl + tr) >> 1;
  if (pos <= mid) {
    update1(2 * v + 1, tl, mid, pos, val);
    int mx = find_max(tl, pos - 1);
    if (mx < h[pos])
      t1[v].val += val;
  }
  else {
    update1(2 * v + 2, mid + 1, tr, pos, val);
    int mx = find_max(mid + 1, pos - 1);
    if (mx < h[pos])
      t1[v].val += val;
  }
}

void update2(int v, int tl, int tr, int pos, ll val) {
  if (tl == tr) {
    //a[pos] += val;
    t2[v] = {a[pos], tl, tr};
    return;
  }
  int mid = (tl + tr) >> 1;
  if (pos <= mid) {
    update2(2 * v + 1, tl, mid, pos, val);
    int mx = find_max(pos + 1, mid);
    if (mx < h[pos])
      t2[v].val += val;
  }
  else {
    update2(2 * v + 2, mid + 1, tr, pos, val);
    int mx = find_max(pos + 1, tr);
    if (mx < h[pos])
      t2[v].val += val;
  }
}

int main() {

  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", h + i);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  build1(0, 0, n - 1);
  build2(0, 0, n - 1);
  //update1(0, 0, n - 1, 1, 10);
  //update2(0, 0, n - 1, 1, 10);
  //Node n1 = query2(0, 0, n - 1, 2, 3);
  //cout<<n1.val<<" "<<n1.l+1<<" "<<n1.r+1<<endl;
  //return 0;
  while (q--) {
    int i, la, lb;
    scanf("%d%d%d", &i, &la, &lb);
    if (i == 1) {
      //update1(0, 0, n - 1, la - 1, lb - a[la - 1]);
      //update2(0, 0, n - 1, la - 1, lb - a[la - 1]);
    }
    else {
      if (la == lb) {
	printf("%d\n", a[la - 1]);
	continue;
      }
      if (h[la - 1] > h[lb - 1]) {
	if (la >= lb ) {
	  Node node = query1(0, 0, n - 1, lb - 1, la - 1);
	  if (node.r < la - 1)
	    puts("-1");
	  else
	    printf("%lld\n", node.val);
	}
	else {
	  Node node = query1(0, 0, n - 1, la - 1 , lb - 1);
	  //cout<<node.l+1<<" "<<node.r+1<<endl;
	  if (node.l > la - 1)
	    puts("-1");
	  else
	    printf("%lld\n", node.val);
	}
      }
      else
	puts("-1");
    }
  }
  return 0;
}
