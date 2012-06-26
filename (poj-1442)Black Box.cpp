# include <stdio.h>
# define swap(a, b) {int t = a; a = b; b = t;}
# define INF_MIN -2000000005
# define INF_MAX 2000000005
long m, n;
long A[30005], u[30005];
long hM[30005], hm[30005], heap_sizeM, heap_sizem;

int right(int i)
{
    return i*2+1;
}
int left(int i)
{
    return i*2;
}
int parent(int i)
{
    return i/2;
}
/**
 * 最大优先队列
 */

void max_heapify(int i)
{
    int r = right(i);
    int l = left(i);
    long largest = INF_MIN;

    if (l <= heap_sizeM && hM[l] > hM[i])
        largest = l;
    else
        largest = i;
    
    if (r <= heap_sizeM && hM[r] > hM[largest])
        largest = r;

    if (largest != i)
    {
        swap(hM[i], hM[largest]);
        max_heapify(largest);
    }
}
long heap_maximum()
{
    return hM[1];
}
long heap_extract_max()
{
    long max = hM[1];
    hM[1] = hM[heap_sizeM];
    heap_sizeM--;
    max_heapify(1);
    return max;
}
void max_heap_increase_key(int i, int key)
{
    if (key < hM[i])
    {
        printf("new key is smaller than current key");
        return;
    }
    hM[i] = key;
    while (i > 1 && hM[parent(i)] < hM[i])
    {
        swap(hM[parent(i)], hM[i]);
        i = parent(i);
    }
}
void max_heap_insert(int key)
{
    heap_sizeM ++;
    hM[heap_sizeM] = INF_MIN;
    max_heap_increase_key(heap_sizeM, key);
}
/**
 * 最小优先队列
 */
void min_heapify(int i)
{
    int r = right(i);
    int l = left(i);
    long smallest = INF_MAX;
    if (l <= heap_sizem && hm[l] < hm[i])
        smallest = l;
    else
        smallest = i;

    if (r <= heap_sizem && hm[r] < hm[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(hm[i], hm[smallest]);
        min_heapify(smallest);
    }
}
long heap_minimum()
{
    return hm[1];
}
long heap_extract_min()
{
    long min = hm[1];
    hm[1] = hm[heap_sizem];
    heap_sizem--;
    min_heapify(1);
    return min;
}
void min_heap_decrease_key(int i, int key)
{
    if (hm[i] < key)
    {
        printf("new key is larger than current key");
        return;
    }
    hm[i] = key;
    while (i > 1 && hm[parent(i)] > hm[i])
    {
        swap(hm[parent(i)], hm[i]);
        i = parent(i);
    }
}
void min_heap_insert(int key)
{
    heap_sizem ++;
    hm[heap_sizem] = INF_MAX;
    min_heap_decrease_key(heap_sizem, key);
}

void load()
{
    scanf("%ld %ld", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%ld", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%ld", &u[i]);
}
void solve()
{
    heap_sizem = heap_sizeM = 0;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        for ( ; j <= u[i]; j++)
            min_heap_insert(A[j]);
        while (heap_sizem>0 && heap_sizeM >0 && heap_minimum() < heap_maximum())
        {
            long m1 = heap_extract_min();
            long m2 = heap_extract_max();
            max_heap_insert(m1);
            min_heap_insert(m2);
        }
        max_heap_insert(heap_extract_min());
        printf("%ld\n", heap_maximum());
    }
}
int main()
{
    freopen("data", "r", stdin);
    load();
    solve();
    return 0;
}
