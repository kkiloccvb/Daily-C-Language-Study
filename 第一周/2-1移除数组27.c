//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
//假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//返回 k。
/*
自写
*/
int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // 记录合格的人有多少个
        for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) { // 如果发现一个合格的
        nums[k]=num[i];// TODO: 把合格的 nums[i] 挪到 nums[k] 的位置
        k++;// TODO: 让 k 往后挪一个位置，等待下一个
        }
    }
 return k; // 返回合格的总数
}//我先找一个 val，然后把后面的数都往前挪一位。如果有 n 个数，这种做法最坏要跑 n^2 次运算。
/*
最小内存
*/
int removeElement(int* nums, int numsSize, int val) {
    int slow=0,fast=0;
    for(fast;fast<numsSize;fast++)
    {
        if(nums[fast]!=val)
        {
            nums[slow]=nums[fast];
            slow++;

        }
    }
    return slow;

    
}//在原数组 nums 上进行“原地覆盖”，只额定申请了两个变量：slow 和 fast。注意使用已经有的变量减小内存
/*
最快速度
*/
int removeElement(int* nums, int numsSize, int val) {
    
    int slowI = 0;
    for(int fastI = 0;fastI<numsSize;fastI++){
        if(val != nums[fastI]){
            nums[slowI++] = nums[fastI];
        }
    }
    return slowI;
}//fast 指针从头到尾只走了一遍。每个元素只被看了一次，每个“好数据”只被移动了一次。这就是极致的 O(n)。

//与两数之和区别：因为那道题要“找”特定的组合，而这道题只是“过滤”。场景决定算法。