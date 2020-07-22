#include <iostream>

using namespace std;

typedef long long ll;
ll temp[3], a[6];

bool one() {
  ll diff, mul;
  bool init_diff = false, init_mul = false, mpos = true, dpos = true;
  for (int i = 0; i < 3; ++i) {
    if (a[i] != a[i + 3]) {
      if (init_diff == false) {
	diff = a[i] - a[i + 3];
	init_diff = true;
      }
      else if (diff != a[i] - a[i + 3])
	dpos = false;
      if (init_mul == false) {
	if (a[i + 3] % a[i] == 0)
	  mul = a[i + 3] / a[i];
	else
	  mpos = false;
	init_mul = true;
      }
      else {
	if (a[i + 3] % a[i] == 0) {
	  if (a[i + 3] / a[i] != mul)
	    mpos = false;
	}
	else
	  mpos = false;
      }
    }
  }
  return mpos || dpos;
}

bool compare(ll arr[]) {
  bool poss = true;
  for (int i = 3; i < 6; ++i)
    if (arr[i - 3] != a[i]) {
      poss = false;
      break;
    }
  return poss;
}

void mult(int num, int d) {
  for (int i = 0; i < 3; ++i)
    if ((1 << i) & num)
      temp[i] *= d;
}

void divi(int num, int d) {
  for (int i = 0; i < 3; ++i)
    if ((1 << i) & num)
      temp[i] /= d;
}

void add(int num, int d) {
  for (int i = 0; i < 3; ++i)
    if ((1 << i) & num)
      temp[i] += d;
}


bool single(int q) {
  for (int j = 0; j < 3; ++j)
    if ((1 << j) & q) {
      int d = a[j + 3] - temp[j];
      add(q, d);
      if (compare(temp))
	return true;
      add(q, -d);
      if (temp[j] == 0)
	continue;
      if (a[j + 3] % temp[j])
	continue;
      d = a[j + 3] / temp[j];
      mult(q, d);
      if (compare(temp))
	return true;
      divi(q, d);
    }
  return false;
}

bool helper1(int p, int q) {
  bool poss = false;
  temp[0] = a[0];
  temp[1] = a[1];
  temp[2] = a[2];
  for (int i = 0; i < 3; ++i)
    if ((1 << i) & p) {
      add(p, a[i + 3] - a[i]);
      if (single(q))
	return true;
      add(p, a[i] - a[i + 3]);
      if (a[i] == 0)
	continue;
      if (a[i + 3] % a[i])
	continue;
      mult(p, a[i + 3] / a[i]);
      if (single(q))
	return true;
      divi(p, a[i + 3] / a[i]);
    }
  return poss;
}

bool helper2() {
  ll n1 = a[3] - a[4], d1 = a[0] - a[1];
  if (d1 == 0)
    return false;
  else {
    if (n1 % d1)
      return false;
    ll x = n1 / d1;
    //cout<<x<<endl;
    ll d = a[3] - a[0] * x;
    ll val = a[2] * x + d;
    if (val == a[5])
      return true;
  }
  return false;
}

bool two() {
  for (int i = 0; i < 3; ++i)
    if (a[i] == a[i + 3])
      return true;
  for (int i = 1; i < 8; ++i) {
    for (int j = 1; j < 8; ++j) {
      if (i != j && helper1(i, j))
	return true;
      else if (i == j && i == 7) {
	if (helper2())
	  return true;
      }
    }
  }
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int ans = 3;
    for (int i = 0; i < 6; ++i)
      scanf("%d", a + i);
    if (compare(a)) {
      puts("0");
      continue;
    }
    if (one()) {
      puts("1");
      continue;
    }
    if (two()) {
      puts("2");
      continue;
    }
    printf("%d\n", ans);
  }
  return 0;
}
