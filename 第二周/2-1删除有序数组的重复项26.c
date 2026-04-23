//删除有序数组的重复项26
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize==0){
        return 0;
    }
    int i=0;
        for(int j=1;j<numsSize;j++)
        {
            if(nums[j]!=nums[i])
            {
               i++;
               nums[i]=nums[j];
            }
        }
    return i+1;
}//自写
int removeDuplicates(int* nums, int numsSize) {
    int* fast=&nums[1];
    int* slow=&nums[1];
    int count=1;
    if(numsSize==0){
        return 0;
    }
    for(int i=1;i<numsSize;i++){
        if(*fast!=*(fast-1)){
            *slow=*fast;
            slow++;
            count++;
        }
        fast++;
    }
    return count;
}//内存最小