import static org.junit.Assert.assertEquals;
import org.junit.Test;
import java.util.*;

public class SolutionTest {
  @Test
  public void testSolution() {
	Solution so = new Solution();
	
	int[] prices = {7, 1, 5, 3, 6, 4};
	int[] prices1 = {2, 4, 1};

	int  result = so.maxProfit(prices);
    System.out.printf("\nresult:%d", result);       
	
	int  result1 = so.maxProfit(prices1);
    System.out.printf("\nresult:%d", result1);       
  }
}
