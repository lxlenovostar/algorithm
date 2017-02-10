import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class SolutionTest {
  @Test
  public void testSolution() {
	Solution so = new Solution();
	int[] preorder = {1, 2, 4, 5, 3, 6, 7};
	int[] inorder = {4, 2, 5, 1, 6, 3, 7}; 

 	so.root = so.buildTree(preorder, inorder);

	for (int i : so.levelOrder())
       	System.out.printf("%d:", i);       
    
	/*
	int[] a1 =  {1, 2, 3, 1}; 
    int result1 = s.findPeakElement(a1);
    assertEquals(2, result1);
    */ 
  }
}
