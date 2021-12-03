//Find element at given index after a number of rotations
/*
	arr[] : {1, 2, 3, 4, 5}
        ranges[] = { {0, 2}, {0, 3} }
        index : 1
	Output : 3
*/

import java.util.*;
import java.io.*;

class item_afterRotation {
	
	public static void rotate(int arr[], int start , int end )
	{
		int temp = 0;
		for(int i = start+1; i< end ; i++)
		{
			temp = arr[start];
			arr[start] = arr[i];
			arr[i] = temp; 
		}
	}

	// Driver code
	public static void main(String args[])
	{
		int size = 0;
		Scanner sc = new Scanner(System.in);

		
		//System.out.println("Enter the size of the set ");
		//size = sc.nextInt();

		//System.out.println("Enter the K ");
		//k = sc.nextInt();

		int arr[] = { 1, 5, 3, 4, 2 };
		int n = arr.length;
		
		int ranges[][] = { {0, 2}, {0, 3} };
System.out.println(Arrays.toString(arr));
		for(int row[] : ranges)	rotate(arr, row[0], row[1]);
		System.out.println(Arrays.toString(arr));
		System.out.println(arr[1]);	
	
	}
}

