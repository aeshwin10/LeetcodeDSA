class Solution 
{
  public void sortColors(int[] nums)//Dutch National FlagAlgorithm
  {
    int temp = 0;    
    int low = 0;
    int mid = 0;          //3 pointers
    int high = nums.length;
    while (mid<=high-1)
    {
      if (nums[mid]==0){
        temp = nums[low];
        nums[low]=nums[mid];
        nums[mid]= temp;
        mid++;
        low++;
      }
      else if (nums[mid]==1){
        mid++;
      }
      else if (nums[mid]==2){
        temp = nums[high-1];
        nums[high-1]=nums[mid];
        nums[mid]=temp;
        
        high--;
      }
    }
  }
}