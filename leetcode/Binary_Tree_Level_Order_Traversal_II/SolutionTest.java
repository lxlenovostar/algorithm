import static org.junit.Assert.assertEquals;
import org.junit.Test;
import java.util.*;

public class SolutionTest {
  @Test
  public void testSolution() {
	Solution so = new Solution();
	int[] preorder = {3, 9, 20, 15, 7};
	int[] inorder = {9, 3, 15, 20, 7}; 

 	so.root = so.buildTree(preorder, inorder);
	
	for (int i : so.levelOrder())
       	System.out.printf("%d:", i);       

	List<List<Integer>> result = so.levelOrderBottom(so.root);
	for (List<Integer> temp : result) {
       	System.out.println();       
		for (int i : temp)
       		System.out.printf("%d:", i);       
	}
	/*	
	for (int i : so.levelOrder())
       	System.out.printf("%d:", i);       
    
	int[] a1 =  {1, 2, 3, 1}; 
    int result1 = s.findPeakElement(a1);
    assertEquals(2, result1);
    */ 
  }
}
