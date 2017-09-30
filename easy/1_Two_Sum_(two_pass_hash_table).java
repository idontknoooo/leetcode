import java.util.HashMap; 
import java.util.Map;
class Solution{
public int[] twoSum(int[] nums, int target) 
{
    Map<Integer, Integer> map = new HashMap<>();
	// O(n): Storing pairs into hashmap
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i); // Key: number; value: its order
    }
	// O(n): Search complement from hashmap
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
		// If complement exist and complement is not 'this'
        if (map.containsKey(complement) && map.get(complement) != i) {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
}
