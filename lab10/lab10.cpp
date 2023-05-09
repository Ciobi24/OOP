#include "Array.h"



int main()
{
    Compare* c;
    c = new CompareGreater<int>();
    Array<int> arr(5);
    arr.Insert(0, 8);
   
    arr.Insert(1, 4);
    
    arr += 2;
    
    arr.Delete(1);
    
    arr.Insert(2, 1);
    
   // arr.Sort();
    
    //arr.Sort(Compare1<int>);
    arr.Sort(c);
    
    printf("Searching binary for 8: Index:%d\n", arr.BinarySearch(8));
  for (auto it : arr)
    {
        printf("%d ", it);
    }
   //for(auto it=arr.begin();it!=arr.end();++it)

	return 0;
}
