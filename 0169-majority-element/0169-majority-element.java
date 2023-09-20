class Solution {
    public int majorityElement(int[] nums) 
    {
        int count = 0;      //We are using 
        int element = 0;

        for (int i = 0; i<nums.length; i++)
        {
            if (count ==0)
            {
                element = nums[i];
                count ++;
            }
            else if (count>=1 && nums[i] == element)
            {
                count++;
            }
            else if (count>=1 && nums[i] != element)
            {
                count--;
            }
        }
        return element;
    }
}