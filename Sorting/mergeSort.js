array = [8,5,2,9,5,6,3];
// O(nlogn) time | O(n) space
function mergeSort(array) {
  if(array.length <= 1) return array;
	mergeSortHelper(array, 0, array.length - 1);
	return array;
}

function mergeSortHelper(array,startIdx,endIdx){
	if(startIdx < endIdx){
		const middleIdx = Math.floor(startIdx + (endIdx - startIdx)/2);
		mergeSortHelper(array,startIdx,middleIdx);
		mergeSortHelper(array,middleIdx + 1, endIdx);
		doMerge(array,startIdx,middleIdx,endIdx);
	}
}

function doMerge(array,startIdx,middleIdx,endIdx){
	var temp = Array(endIdx - startIdx + 1);
	let k = 0;
	let i = startIdx;
	let j = middleIdx + 1;
		while(i <= middleIdx && j <= endIdx){
			if(array[i]<=array[j]){
				temp[k++] = array[i++];
			}
			else{
				temp[k++] = array[j++];
			}
		}
		while(i<=middleIdx){
			temp[k++] = array[i++];
		}
		while(j<=endIdx){
			temp[k++] = array[j++];
		}

		for(let i = startIdx; i <= endIdx; i++){
			array[i] = temp[i - startIdx];
		}
}

console.log(mergeSort(array));
