#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> alternateSort(vector <int> &arr) {

  vector <int> answer;
  sort(arr.begin(), arr.end());
  
  for (int i = 0; i < arr.size(); i += 2)
    answer.push_back(arr[i]);

  return answer;
}

int main() {

  vector <int> arr{3, 5, 1, 5, 9, 10, 2, 6};
  vector <int> answer = alternateSort(arr);

  for (int elem : answer)
    cout << elem << " ";
  cout << endl;
  
  return 0;
}

