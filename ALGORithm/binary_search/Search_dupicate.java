//search for the given number and tere duplicate

import java.util.*;
import java.io.*;

class Search_dupicate
{	
	
	public static int binary_search(int[] ar, int num , int start , int end)
	{
		// 3 cases can happen here... 
		/*	1. Not found at middle
			2. found 
				2.1. num starts from mid
				2.2. num starts before mid
		*/
		mid = end - start / 2;

		if( ar[mid] == num )
		{
			if( ar[mid-1] != num ) return mid;
			else binary_search(ar, num, 0 , mid-1);
		}
		else
		{
			if( ar[mid] > num ) binary_search(ar, num, 0 , mid-1);
			else binary_search(ar, num ,mid+1, end);

		}

	}
	public static int num_dup(int[] ar, int num)
	{
		//implementing the binary search to find the position of the num .
		int count = 0;
		int position = binary_search( ar , num , 0 , ar.length -1 );
		for( int i = 0 ; i < ar.length ; i++) if( ar[i]  == num) count++;

		return count;

	}
	public static void main(String args[])
	{
		int[] ar = { 1 ,2 , 5 ,5 ,6 };

		System.out.println( "number of duplicates in the array of  5 are =>" +num_dup( ar, 5 ));

	}
}