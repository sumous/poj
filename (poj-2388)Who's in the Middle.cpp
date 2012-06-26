# include <iostream>
# include <cstdio>
# define swap(a, b) {int t = a; a = b; b = t;}
using namespace std;
int A[10005], N, size;
void load()
{
    cin >> N;
    size = N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
}
int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return i*2;
}
int right(int i)
{
    return i*2+1;
}
/* 使以i为根节点的树保持最大堆性质 */
void max_heapify(int i)
{
    int l = left(i), r = right(i);
    int largest = 0;
    if (l <= size && A[i] < A[l])
        largest = l;
    else
        largest = i;
    if (r <= size && A[largest] < A[r])
        largest = r;
    if (i != largest)
    {
        swap(A[i], A[largest]);
        max_heapify(largest);
    }
}
/* 构建最大堆 */
void build_max_heap()
{
    for (int i = N/2; i > 0; i--)
    {
        max_heapify(i);
    }
}
/* 堆排序 */
void heap_sort()
{
    build_max_heap();
    for (int i = size; i > 1; i--)
    {
        swap(A[i], A[1]);
        size --;
        max_heapify(1);
    }
}

int main()
{
    freopen("data", "r", stdin);
    load();
    heap_sort();
    cout << A[N/2+1] << endl;
    return 0;
}
