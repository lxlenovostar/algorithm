/* 
 * 9. Palindrome Number
 *
 * Description:
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

public class Solution {
    public static boolean isPalindrome(int x) {
		int num = 0;
		int tmp = x;
		int c_value = 1;

		if (x < 0)
			return false;

        if (x == 0)
            return true;	

		while(tmp != 0) {
			tmp /= 10; 
			num++;
		
			if (tmp != 0)	
				c_value *= 10;
		}
	
		tmp = x;	
		int tmp1 = x;
		for (int i = 0; i < num/2; i++) {
			int r_value = tmp%10;
			int l_value = tmp1/c_value;

        	System.out.printf("what1 l_value:%d tmp1:%d c_value:%d r_value:%d tmp:%d\n", l_value, tmp1, c_value, r_value, tmp);       

			if (r_value != l_value) {
				return false;
			}

			tmp /= 10;
			tmp1 %= c_value;
			c_value /= 10;
		}
		

        return true;
    }

    public static void main(String[] args)
    {
        //System.out.printf("%d:", Solution.isPalindrome(121));       
        //System.out.println(Solution.isPalindrome(121));       
        System.out.println(Solution.isPalindrome(1001));       
    }
}
