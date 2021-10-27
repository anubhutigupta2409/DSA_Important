//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class Main {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int T=sc.nextInt();//input number of testcases
		while(T-->0)
		{
		    Solution obj=new Solution();
		    
		    int C;
		    C=sc.nextInt();//input temperature in celscius
		    
		    System.out.println((int)(obj.cToF(C)));//print the output
		}
		
	}
}
// } Driver Code Ends


//User function Template for Java


class Solution
{
    public double cToF(int C)
    {
        return C*9/5 + 32;
    }
}

