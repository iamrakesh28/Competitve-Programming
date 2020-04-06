#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int arr[] = {23, 5, 1}, mark[5];
char str[6];
vector <int> fig[5], cur;

void reset() {

  for (int i = 0; i < 5; ++i)
    fig[i].clear();
}

int main() {
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int f;
    scanf("%d", &f);
    cur.clear();
    reset();
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < 119; ++i)
      cur.push_back(i);
    for (int i = 0; i < 3; ++i) {
      for (int it : cur)
	printf("%d\n", it * 5 + i + 1);
      fflush(stdout);
      char ch;
      for (int it : cur) {
	scanf(" %c", &ch);
	fig[ch - 'A'].push_back(it);
      }
      int id = 0;
      for (int j = 0; j < 5; ++j)
	if (fig[j].size() == arr[i]) {
	  id = j;
	  break;
	}
      str[i] = id + 'A';
      cur.clear();
      for (int it : fig[id])
	cur.push_back(it);
      reset();
    }
    printf("%d\n", cur[0] * 5 + 4);
    fflush(stdout);
    char ch;
    scanf(" %c", &ch);
    str[4] = ch;
    char id = 'A';
    for (int j = 0; j < 5; ++j)
      if (j != 3)
	mark[str[j] - 'A']++;
    for (int j = 0; j < 5; ++j)
      if (mark[j] == 0) {
	id = j + 'A';
	break;
      }
    str[3] = id;
    str[5] = '\0';
    printf("%s\n", str);
    fflush(stdout);
    char y;
    scanf(" %c", &y);
    if (y == 'N')
      break;
  }
  return 0;
}
