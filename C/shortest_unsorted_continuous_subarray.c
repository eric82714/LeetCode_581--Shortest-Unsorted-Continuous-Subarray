int compare(const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int* copy_and_sort(int* nums, int numsSize){
    int* copy = calloc(numsSize, sizeof(int));
    for(int i = 0; i < numsSize; i++) *(copy+i) = *(nums+i);
    qsort(copy, numsSize, sizeof(int), compare);
    
    return copy;
}

int findUnsortedSubarray(int* nums, int numsSize){
    if(numsSize == 0) return 0;
        
    int* copy = copy_and_sort(nums, numsSize);
    int right = numsSize-1, left = 0;
    bool isRright = false, isLeft = false;
    for(int i = 0; i < numsSize; i++){
        if(isRright && isLeft) break;
        if(*(copy+i) != *(nums+i) && !isLeft){ 
            left = i;
            isLeft = true;           
        }
        if(*(copy+(numsSize-1-i)) != *(nums+(numsSize-1-i)) && !isRright){ 
            right = numsSize-1-i;
            isRright = true;
        }
    }
    if(!isRright && !isLeft && (right - left == numsSize-1)) return 0;
        
    return right - left + 1;
}
