# Python program for implementation of Insertion Sort

# Function to do insertion sort

# O*n^2) time | O(1) space Avg and Worst Case
# O(n) time | O(1) space Best Case (Sorted Array)

# How does it work?
# We sort it by creating space at the beginning of the list that is a
# tentatively sorted list and then iterate through the rest of the array
# and each number in the rest of the array, we insert that number in the
# tentatively sorted list.


def insertionSort(arr):

    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        j = i
        while j > 0 and arr[j] < arr[j - 1]:
            swap(j, j-1, arr)


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]


# Driver code to test above
arr = [12, 11, 13, 5, 6]
insertionSort(arr)
for i in range(len(arr)):
    print(arr[i])
