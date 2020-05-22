# How does it work?

# We divide the list into two separate lists within that list,
# one sub list that represents the sorted numbers and the other
# represents the  unsorted numbers.
# So at the beginning we start with the entire list as an unsorted list.
# We iterate through this unsorted list a bunch of times to find the
# smallest number in that list. Once we have the smallest number
# we append it to the sorted sub list. We keep doing that till we
# exhaust the unsorted sub list.

# O(n^2) time | O(1) space Best, Avg, Worst


def selectionSort(array):
    currentIdx = 0
    while currentIdx < len(array) - 1:
        smallestIdx = currentIdx
        for i in range(currentIdx + 1, len(array)):
            if array[smallestIdx] > array[i]:
                smallestIdx = i
        swap(currentIdx, smallestIdx, array)
        currentIdx += 1
    return array


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]


# Driver code to test above
arr = [12, 11, 13, 5, 6]
selectionSort(arr)
for i in range(len(arr)):
    print(arr[i])
