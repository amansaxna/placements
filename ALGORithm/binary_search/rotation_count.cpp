//Rotation Count in Rotated Sorted array
#include<iostream>

using namespace std;

int * rotate(int *ar ,int size_arr, int rotate_by)
{
	//int size_arr = sizeof(ar)/sizeof(ar[0]); wreong way... we get a pointer to the array  sizeof(ar) will give the wriong answer
	//int solution[ size_arr ] ; wrong way to declare.. solution will be deleted once out of scope
 	//int * ptr = solution;
 	
 	int* solution = new int[size_arr];
 	int iter = 0;
	for( int i = rotate_by ; i < size_arr ; i++)
	{
		solution[iter] = ar[i];
		iter++;
	}

	for( int i = 0 ; i < rotate_by ; i++)
	{
		solution[iter] = ar[i];
		iter++;
	}
	return solution;

}

int find_rotation(int ar[], int start , int end) // return the index of the min. element
{
	for( int i = start; i< end ; i++)	cout << ar[i] << " _" ;
	int mid = (end-start)/2;

	if ( ar[mid] >ar[mid+1] ) //found 
	{
	 	return mid+1;
	}

	if( ar[mid-1] > ar[mid] )	//found the point of search
	{
		return mid;
	} 
	if (ar[start] > ar[mid])
       return find_rotation(ar, start, mid-1);
 
    return find_rotation(ar, mid+1, end);
    cout<<"\n";
}

int main()
{
	cout<<"enter the no of elements in the array :";
	int size;
	cin >> size;
	int ar[size]  ;
	//int(*rotated_array)[size];

	for( int i=0; i<size; i++)
	{
		cin>> ar[i];
	}

	int * rotated_array = rotate(ar,size, 3);

	for( int i = 0; i< size ; i++)	cout << rotated_array[i];
	int ans = find_rotation(rotated_array,0,size-1);
	cout << "array is rotated by : " << size - ans ;
}