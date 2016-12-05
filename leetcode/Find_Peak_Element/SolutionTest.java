import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class SolutionTest {
  @Test
  public void testSolution() {
	Solution s = new Solution();

    int[] a1 =  {1, 2, 3, 1}; 
    int result1 = s.findPeakElement(a1);
    assertEquals(2, result1);
    
	int[] a2 =  {2}; 
    int result2 = s.findPeakElement(a2);
    assertEquals(2, result1);
  }
}
