array = [8,5,2,9,5,6,3];
function quickSort(array) {
  quickSortHelper(array, 0, array.length - 1);
	return array;
}

function quickSortHelper(array, startIdx, endIdx){
	if(startIdx >= endIdx) return;
	const pivotIdx = startIdx;
	let leftIdx = startIdx + 1;
	let rightIdx = endIdx;
		while(leftIdx <= rightIdx){
			if(array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]){
				swap(leftIdx,rightIdx,array);
			}
			if(array[leftIdx] <= array[pivotIdx]){
				leftIdx++;
			}
			if(array[rightIdx] >= array[pivotIdx]){
				rightIdx--;
			}
		}
	swap(pivotIdx, rightIdx, array);
	const leftSubarrayIsSmaller = rightIdx - 1 - startIdx < endIdx - (rightIdx + 1);
	if(leftSubarrayIsSmaller){
		quickSortHelper(array,startIdx,rightIdx - 1);
		quickSortHelper(array,rightIdx + 1, endIdx);
	}
	else{
		quickSortHelper(array,rightIdx + 1, endIdx);
		quickSortHelper(array,startIdx, rightIdx - 1);
	}
}

function swap(i,j,array){
	const temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}

console.log(quickSort(array));
