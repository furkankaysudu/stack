#include <iostream>
#include <stdio.h>
#include <cstdlib>

struct stackExmpl{
    int sp;
    unsigned capacity;
    int *arr;
};
struct stackExmpl* createStack(unsigned capacity){
    struct stackExmpl* stck = (struct stackExmpl*)malloc(sizeof(struct stackExmpl));
    stck->capacity = capacity;
    stck->sp = -1;
    stck->arr = (int*)malloc(stck->capacity*sizeof(int));
    return stck;
};
int overflow(struct stackExmpl*stck){
    return stck->sp == stck->capacity-1;
}
int underflow(struct stackExmpl*stck){
    return stck->sp==-1;
}
void top(stackExmpl*stck,int veri){
    if (overflow(stck))
        return;
    stck->arr[++stck->sp]=veri;
    printf("%d verisi eklendi",veri);

}
int pop(stackExmpl*stck){
    if (underflow(stck))
        return -500;
   return stck->arr[stck->sp--];

}

int main(){
    struct stackExmpl*stck = createStack(100);
    top(stck,10); printf(" %d \n",stck->sp);
    top(stck,20); printf(" %d \n",stck->sp);
    top(stck,30); printf(" %d \n",stck->sp);
    printf("%d verisi yigindan alindi.\n",pop(stck));
    printf("%d verisi yigindan alindi.\n",pop(stck));
    printf("%d verisi yigindan alindi.\n",pop(stck));


    return 0;
}
