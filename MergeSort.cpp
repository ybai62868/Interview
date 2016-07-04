# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123456
int a[MAX],b[MAX];
int n;
void Mergearray( int * a,int first,int mid,int last,int * b )
{
    int i = first, j = mid+1;
    int m = mid, n = last;
    int k = 0;
    while ( i <= m && j <= n ){
        if ( a[i] <= a[j] ){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    while ( i <= m ){
        b[k++] = a[i++];
    }
    while ( j <= n ){
        b[k++] = a[j++];
    }
    for ( int i = 0;i < k;i++ ) a[first+i] = b[i];
}
void MergeSort( int * a,int first,int last,int * b )
{
    if ( first < last ){
        int mid = ( first+last )>>1;
        MergeSort(a,first,mid,b);
        MergeSort(a,mid+1,last,b);
        Mergearray(a,first,mid,last,b);
    }
}
int main(void)
{
    cin>>n;
    for ( int i = 0;i < n;i++ ) cin>>a[i];
    MergeSort(a,0,n-1,b);
    for ( int i = 0;i < n;i++ ) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
