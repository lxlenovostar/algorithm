import static org.junit.Assert.assertEquals;
import org.junit.Test;
import java.util.*;

public class SolutionTest {
  @Test
  public void testSolution() {
	Solution so = new Solution();
	//int[] preorder = {3, 9, 20, 15, 7};
	//int[] inorder = {9, 3, 15, 20, 7}; 

	//int[] preorder = {1, 2, 2};
	//int[] inorder = {2, 1, 2}; 

	//int[] preorder = {1, 2, 3, 4, 2, 4, 3};
	//int[] inorder = {3, 2, 4, 1, 4, 2, 3}; 
	
	int[] preorder = {1, 2, 3, 2, 3};
	int[] inorder = {2, 3, 1, 2, 3}; 

 	so.root = so.buildTree(preorder, inorder);
	
	for (int i : so.levelOrder())
       	System.out.printf("%d:", i);       

	boolean result = so.i_isSymmetric(so.root);
    System.out.printf("\nresult:%d", result == true ? 1 : 0);       
	/*	
	for (int i : so.levelOrder())
       	System.out.printf("%d:", i);       
    
	int[] a1 =  {1, 2, 3, 1}; 
    int result1 = s.findPeakElement(a1);
    assertEquals(2, result1);
    */ 
  }
}
