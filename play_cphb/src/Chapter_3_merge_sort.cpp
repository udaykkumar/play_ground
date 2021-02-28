#include <Chapter_3_merge_sort.h>
#include <algorithm>
#include <iostream>

static void mergesort( std::vector<int> &v, int lo, int hi, int &swaps)
{
    if ( lo >= hi )
        return;

    int mid = (hi + lo) / 2 ;

    mergesort(v, lo,     mid, swaps );
    mergesort(v, mid + 1, hi, swaps );

    size_t lvs = mid - lo + 1;
    std::vector<int> lv(lvs, 0);
    for ( size_t i = 0 ; i < lvs; i ++ )
        lv[i] = v[lo + i];

    size_t rvs = hi - mid;
    std::vector<int> rv(rvs, 0);
    for ( size_t i = 0 ; i < rvs; i ++ )
        rv[i] = v[mid + 1 + i];

    size_t i = 0, j = 0, k = lo;
    while (i < lvs && j < rvs)
    {
        v[k++] = (lv[i] <= rv[j]) ? lv[i++] : rv[j++];
        ++swaps;
    }

    while (i < lvs)
    {
        v[k++] = lv[i++];
        ++swaps;
    }

    while (j < rvs)
    {
        v[k++] = rv[j++];
        ++swaps;
    }

}

int cphb::merge_sort_v1( std::vector<int> &v )
{
    int swaps = 0;
    mergesort(v, 0, v.size() - 1, swaps);
    return swaps;
}

