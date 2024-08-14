import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Comparator;
import java.util.HashSet;

class Solution240 {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (int i = 0; i < matrix.length; ++i ) {
            for (int j = 0; j < matrix[0].length; ++j) {
                if (matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        int[][] intervals = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
        int target = 5;

        Solution240 test = new Solution240();
        boolean ret = test.searchMatrix(intervals, target);
        
       System.out.println("ret="+ret);
    }
}
