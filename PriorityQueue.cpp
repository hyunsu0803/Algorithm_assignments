//2019023436_김현수_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heapstruct heap;

struct Heapstruct {
    int size;
    int* arr;
};
heap* CreateHeap(int);
void heapify(heap*, int);
int DeleteMax(heap*);
void Insert(heap*, int);
int main() {
    heap* maxheap = CreateHeap(100000);
    int* m_arr = (int*)malloc(sizeof(int) * 100000);
    int cnt = 0;
    while (1) {
        int case_, num, c_idx;
        scanf("%d", &case_);
        if (case_ == 1) {
            scanf("%d", &num);
            Insert(maxheap, num);

        }
        else if (case_ == 2) {
            m_arr[cnt++] = DeleteMax(maxheap);
            //  for(int i=1;i<=maxheap->size;++i) printf("%d번째 %d\n",i,maxheap->arr[i]);

        }
        else if (case_ == 3) {
            scanf("%d %d", &c_idx, &num);
            maxheap->arr[c_idx] = num;
            // for(int j=(maxheap->size)/2;j>=1;j--)
            for (int j = c_idx; j > 0; j /= 2)
                heapify(maxheap, j);
            //  for(int i=1;i<=maxheap->size;++i) printf("%d번째 %d\n",i,maxheap->arr[i]);

        }
        else if (case_ == 0) {
            for (int j = 0; j < cnt; ++j) printf("%d ", m_arr[j]);
            printf("\n");
            for (int j = 1; j <= maxheap->size; ++j) printf("%d ", maxheap->arr[j]);
            printf("\n");
            break;
        }
        //   else if(case_==4) for(int i=1;i<=maxheap->size;++i) printf("%d번째 %d\n",i,maxheap->arr[i]);
        else
            break;

    }


    return 0;

}

heap* CreateHeap(int size_) {
    heap* tmp;
    tmp = (heap*)malloc(sizeof(heap));
    tmp->size = 0;
    tmp->arr = (int*)malloc(sizeof(int) * (size_ + 1));

    return tmp;
}
void heapify(heap* Uheap, int k) { //return 형태 void여도 됨 heap* 아니어도 된다
    int child = k * 2;
    int tmp_;
    if (Uheap->size >= child) { //내가 생각해보지 못한 예외 처리
        if (child != Uheap->size && Uheap->arr[child] <= Uheap->arr[child + 1]) child++;
        if (Uheap->arr[child] > Uheap->arr[k]) {
            tmp_ = Uheap->arr[k];
            Uheap->arr[k] = Uheap->arr[child];
            Uheap->arr[child] = tmp_;
            heapify(Uheap, child);
        }
    }

}
void Insert(heap* h, int value) {
    int i;
    for (i = ++h->size; i / 2 > 0 && h->arr[i / 2] < value; i /= 2) {
        h->arr[i] = h->arr[i / 2];
    }
    h->arr[i] = value;

}
int DeleteMax(heap* h) {
    int i, child, max, end;
    max = h->arr[1];
    end = h->arr[h->size--];

    for (i = 1; i * 2 <= h->size; i = child) {
        child = i * 2;
        if (child != h->size && h->arr[child] <= h->arr[child + 1]) child++;
        if (end < h->arr[child]) h->arr[i] = h->arr[child];
        else break;
    }
    h->arr[i] = end;
    return max;
}