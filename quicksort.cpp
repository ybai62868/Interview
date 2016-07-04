//O(nlogn)
# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123456
int a[MAX];
int n;
void quicksort( int * v,int left,int right )
{
    if ( left < right ){
        int key = v[left];
        int low = left;
        int hight = right;
        while ( low < hight ){
           while ( low < hight&&v[hight] > key ){
                hight--;
           }
           v[low] = v[hight];
           while ( low < hight&&v[low] < key ){
                low++;
           }
           v[hight] = v[low];
        }
        v[low] = key;
        quicksort(v,left,low-1);
        quicksort(v,low+1,right);
    }
}
int main(void)
{
    cin>>n;
    for ( int i = 0;i < n;i++ ) cin>>a[i];
    quicksort(a,0,n-1);
    for ( int i = 0;i < n;i++ ) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
