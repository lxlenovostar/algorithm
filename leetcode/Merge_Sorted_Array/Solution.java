/*
 * 88.Merge Sorted Array.
 *
 * merge sort 中的merge函数。
 * java:数组，打印怎么做？参考merge.java 
 */

public class Solution {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int i, j, k;
        int[] aux = new int[m + n];
    
        for (i = 0; i < m; i++)
            aux[i] = nums1[i]; 
        
        for (j = 0; j < n; j++)
            aux[i+j] = nums2[j];
       
		/* 
		for (i = 0; i < 6; i++)
            System.out.printf("%d:", aux[i]);       
		System.out.println();       
		*/

        i = 0;
        j = m;
        for (k = 0; k < (m + n); k++) {
            if (i >= m) {
				//System.out.println("fuck0");       
				nums1[k] = aux[j++];
			} 
            else if (j >= (n+m)) {
				//System.out.println("fuck1");       
				nums1[k] = aux[i++]; 
			}
            else if (aux[j] <= aux[i]) {
            	//System.out.printf("aux[i] %d, i %d, aux[j] %d, j %d", aux[i], i, aux[j], j);       
				//System.out.println(" fuck2");       
				nums1[k] = aux[j++];
			}
            else { 
            	//System.out.printf("aux[i] %d, i %d, aux[j] %d, j %d", aux[i], i, aux[j], j);       
				//System.out.println(" fuck3");       
				nums1[k] = aux[i++];
			}
        } 
    }

    public static void main(String[] args)
    {
        int i;

        int[] a1 = new int[6];
		a1[0] = 1;
		a1[1] = 2;
		a1[2] = 3;
        int[] a2 = new int[3];
		a2[0] = 4;
		a2[1] = 5;
		a2[2] = 6;
    
        Solution.merge(a1, 3, a2, 3);

        for (i = 0; i < 6; i++)
            System.out.printf("%d:", a1[i]);       
		System.out.println();       
    }
}
