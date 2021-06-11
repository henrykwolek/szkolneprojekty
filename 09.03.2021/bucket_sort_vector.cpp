#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
void bucketSort(int arr[], int n)
{
    vector<int> b[n];
    
    for (int i=0; i<n; i++)
    {
       int x = n*arr[i];
       b[x].push_back(arr[i]);
    }
 
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
 
int main()
{
    int arr[] = {1, 6, 3, 9, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before Sorting\n";
    for (int i=0; i<n; i++)
    cout << arr[i] << " ";
    
    bucketSort(arr, n);
    
    cout << "\nAfter Sorting \n";
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}