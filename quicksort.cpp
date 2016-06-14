void quicksort( vector<int>&v,int left,int right ){
    if ( left < right ){
        int key = v[left];
        int lo = left;
        int hi = right;
        while ( lo < hi ){
            while ( lo < hi && v[hi] > key ){
                hi--;
            }
            v[lo] = v[hi];
            while ( lo < hi && v[lo] < key ){
                lo++;
            }
            v[hi] = v[lo];
        }
        v[lo] = key;
        quicksort(v,left,lo-1);
        quicksort(v,lo+1,right);
    }
}
