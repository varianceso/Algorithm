/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static void quicksort(int* ele,int left,int right){
    if(left<right){
        int high=right;
        int low=left;
        int flag=ele[left];
        while(low<high){
            while(low<high && ele[high]>flag)
                high--;
            ele[low]=ele[high];
            while(low<high && ele[low]<=flag)
                low++;
            ele[high]=ele[low];
        }
        ele[low]=flag;
        quicksort(ele,left,low-1);
        quicksort(ele,low+1,right);
    }
}

/*
static int factorial(int n){
    int f=1;
    while(n>1){
        f=f*(n--);
    }
return f;
}
A(n,m)＝n(n-1)(n-2)……(n-m+1)＝n!/(n-m)!
C(n,m)=A(n,m)/m!
C(n,m)=n!/( (n-m)! * m! )
最多有C(numsSize,4)种情况,但是这样会导致内存受限错误
int max=factorial(numsSize)/factorial(numsSize-4)*factorial(4);*/
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(numsSize<4)  
        return NULL;
    int n=numsSize;
    quicksort(nums,0,numsSize-1);
    
    int count=0;
    int max=100;/*假设的最大组数*/
    //int max=factorial(numsSize)/factorial(numsSize-4)*factorial(4);//会导致内存受限错误
    int** total=(int**)malloc(sizeof(int*)*max);
    for(int i=0;i<max;i++)
        total[i]=(int*)malloc(sizeof(int)*4);
    
    for(int i=0;i<n-3;i++){
        if(i>0 && nums[i]==nums[i-1]) 
            continue;
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) 
            break;
        if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) 
            continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1]) 
                continue;
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) 
                break;
            if(nums[i]+nums[j]+nums[n-2]+nums[n-1] < target) 
                continue;
            int left=j+1,right=n-1;
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i]+nums[j];
                if(sum<target) 
                    left++;
                else if(sum>target) 
                    right--;
                else{
                    total[count][0]=nums[i];
                    total[count][1]=nums[j];
                    total[count][2]=nums[left];
                    total[count][3]=nums[right];
                    count++;
                    do{
                        left++;
                    }while(nums[left]==nums[left-1] && left<right);
                    do{
                        right--;
                    }while(nums[right]==nums[right+1] && left<right);
                }
            }
        }
    }
    *returnSize=count;
    return total;
}
