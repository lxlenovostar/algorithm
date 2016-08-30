/*
 * 88.Merge Sorted Array.
 *
 * merge sort 中的merge函数。
 * java:数组，打印怎么做？参考merge.java 
 */

public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i, j, k;
        int[] aux = new int[m + n];
    
        for (i = 0; i < m; i++)
            aux[i] = nums1[i]; 
        
        for (j = 0; j < n; j++)
            aux[i+j] = nums2[j];

        i = 0;
        j = m;
        for (k = 0; k < (m + n); k++) {
            if (i > m) nums1[k] = aux[j++]; 
            else if (j > n) nums1[k] = aux[i++]; 
            else if (aux[j] <= aux[i]) nums1[k] = aux[j++];
            else nums1[k] = aux[j++];
        } 
    }

    public static void main(String[] args)
    {
        int i;

        int a1[6] = {1, 3, 5};
        int a2[3] = {2, 4, 6};
    
        merge(a1, 3, a2, 3);

        for (i = 0; i < 6; i++)
            System.out.print("%d", a1[i]);       
    }
}
