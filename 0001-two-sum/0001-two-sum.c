
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
 int * array = malloc(sizeof(int)* 2);
  array[0]=1;
  array[1]=1
        ;
for(int i=0;i<numsSize;++i){
    for(int j=i+1;j<numsSize;++j){

        if (nums[i] + nums[j]==target)
    {
       *returnSize = 2;
        array[0]=i;
        array[1]=j;
        return array;
            }   
 }

}
 *returnSize = 0;
return false;
};