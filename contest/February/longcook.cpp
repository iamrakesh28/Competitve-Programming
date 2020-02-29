#include <iostream>
#include <vector>

using namespace std;

int year[405];
/*
  6 -> 28   => Thursday  4
  7 -> 28   => Wednesday 3
  7 -> 29   => Wednesday 3
void intersect(int days) {
  //Friday
  for (int i = 0; i < 7; ++i) {
    int end = i + 9;
    vector <int> sun;
    sun.push_back(i + 2);
    for (int j = i + 9; j < days; j += 7)
      sun.push_back(j);
    int last = sun[sun.size() - 2];
    if (last <= end)
      cout<<i+1<<" "<<days<<endl;
  }
}
*/

bool leap(int y) {
  if (y % 400 == 0)
    return true;
  if (y % 4 == 0 && y % 100)
    return true;
  return false;
}
void first() {
  int start = 6;
  for (int i = 0; i < 400; ++i) {
    year[i] = start;
    int days = 365;
    if (leap(i))
      days++;
    start = start + days;
    start = start % 7;
  }
  return;
}

int main() {
  int q, tot4 = 0, start = 6;
  first();
  for (int i = 0; i < 400; ++i) {
    int days = 365;
    if (leap(i))
      days++;
    if (start == 4 && days == 365)
      tot4++;
    else if (start == 3)
      tot4++;
    start = start + days;
    start = start % 7;
  }
  scanf("%d", &q);
  while (q--) {
    int m1, y1, m2, y2, s1, s2;
    long long ans = 0;
    scanf("%d%d%d%d", &m1, &y1, &m2, &y2);
    if (y1 == y2) {
      s1 = year[y1 % 400];
      if (m1 <= 2 && m2 >= 2) {
	if (leap(y1)) {
	  if (s1 == 3)
	    ans++;
	}
	else {
	  if (s1 == 3 || s1 == 4)
	    ans++;
	}
      }
      printf("%lld\n", ans);
      continue;
    }
    s1 = year[y1 % 400] , s2 = year[y2 % 400];
    if (m1 <= 2) {
      if (leap(y1)) {
	if (s1 == 3)
	  ans++;
      }
      else {
	if (s1 == 4 || s1 == 3)
	  ans++;
      }
    }
    s1 = year[++y1 % 400];
    while (y1 < y2 && y1 % 400) {
      int days = 365;
      if (leap(y1))
	days++;
      if (s1 == 4 && days == 365)
	ans++;
      else if (s1 == 3)
	ans++;
      s1 = s1 + days;
      s1 = s1 % 7;
      y1++;
    }
    int temp = y2 / 400;
    temp = temp * 400;
    if (temp >= y1) {
      long long t = (temp - y1) / 400;
      y1 = temp;
      ans = ans + tot4 * t;
    }

    while (y1 < y2) {
      int days = 365;
      if (leap(y1))
	days++;
      if (s1 == 4 && days == 365)
	ans++;
      else if (s1 == 3)
	ans++;
      s1 = s1 + days;
      s1 = s1 % 7;
      y1++;
    }
    if (m2 >= 2) {
      if (leap(y2)) {
	if (s2 == 3)
	  ans++;
      }
      else {
	if (s2 == 4 || s2 == 3)
	  ans++;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
