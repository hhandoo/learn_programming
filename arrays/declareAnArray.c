#include <stdio.h>

int main(){

    // only initialization
    int nums1[5];

    // initialization and declaration
    int nums[5] = {1,2,3,4,5};

    for(int i = 0; i<5; i++){
        printf("%d\n", nums[i]);
    }

    
    return 0;
}