/* 
 * 9. Palindrome Number
 *
 * Description:
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 */

public class Solution1 {
    public static boolean isPalindrome(int x) {
		if(x < 0)
			return false;
		else if(x == 0)
			return true;
		else {
			int tmp = x;
			int y = 0;

			while(x != 0)
			{
				y = y*10 + x%10;
				x = x/10;
			}
		
			if (y == tmp)
				return true;
			else
				return false;
			}
    }

    public static void main(String[] args)
    {
        //System.out.printf("%d:", Solution.isPalindrome(121));       
        //System.out.println(Solution.isPalindrome(121));       
        System.out.println(Solution1.isPalindrome(1001));       
    }
}
