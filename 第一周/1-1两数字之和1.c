/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。你可以按任意顺序返回答案。
Note: The returned array must be malloced, assume caller calls free().*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                int* result = (int *)malloc( sizeof(int) * 2);
                    if(result == NULL) {
                        return NULL;
                    }
                    result[0] = i;
                    result[1] = j;
                    *returnSize = 2;
                    return result;
        }
    }
}
return NULL;
}//暴力破解，使用了栈内存（Stack）用的是遍历，占用内存小，运行速度慢

int hash(int key){
    int r=key%SIZE;
    return r<0?r+SIZE:r;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* hashTable[SIZE]={NULL};

    for(int i=0;i<numsSize;i++){
        int complement=target-nums[i];
        int h=hash(complement);//存到哈希函数里面了

        Node* curr=hashTable[h];
        while(curr !=NULL){
            if(curr->key==complement){

                int *result=(int*)malloc(sizeof(int)*2);
                result[0]=curr->index;
                result[1]=i;
                *returnSize=2;
                return result;
            }
            curr=curr->next;
        }
        int h_curr=hash(nums[i]);
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->key=nums[i];
        newNode->index=i;
        newNode->next=hashTable[h_curr];
        hashTable[h_curr]=newNode;
    }
    *returnSize=0;
    return NULL;
}//哈希表，使用了堆内存（Heap），先给所有数据编码，建立起一一映射的对应关系
