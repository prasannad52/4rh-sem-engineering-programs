#quicksort
import numpy as np
import array
n = int(input("ENTER NUMBER OF ELMENTS IN ARRAY"))
arr = np.random.randint(10,100,n)
print(arr.tolist())
low = 0
high = len(arr)-1
class sort:
    def partition(self,arr,low,high):
        key = arr[low]
        i=low+1
        j=high
        while(i<j):
            while(arr[i]<=key):
                i=i+1
            while(arr[j]>key):
                j=j-1
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
        temp = arr[j]
        arr[j] = arr[low]
        arr[low] = temp
        return j
    def quicksort(self,arr,low,high):
        if low>=high:
            return
        else:
            k=self.partition(arr,low,high)
            self.quicksort(arr,low,k-1)
            self.quicksort(arr,k+1,high)
s = sort()
s.quicksort(arr,low,high)
print(arr.tolist())
