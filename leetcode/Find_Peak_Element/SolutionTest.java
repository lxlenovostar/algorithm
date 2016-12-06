import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class SolutionTest {
  @Test
  public void testSolution() {
	Solution s = new Solution();

	/*
    int[] a1 =  {1, 2, 3, 1}; 
    int result1 = s.findPeakElement(a1);
    assertEquals(2, result1);
    
	int[] a2 =  {2}; 
    int result2 = s.findPeakElement(a2);
    assertEquals(0, result2);

	int[] a3 =  {1,2,1}; 
    int result3 = s.findPeakElement(a3);
    assertEquals(1, result3);

	int[] a4 =  {3,2,1}; 
    int result4 = s.findPeakElement(a4);
    assertEquals(0, result4);
	*/

	int[] a5 =  {3, 4, 3, 2,1}; 
    int result5 = s.findPeakElement(a5);
    assertEquals(0, result5);
  }
}
