array = [8,5,2,9,5,6,3];
function heapSort(array) {
  buildMaxHeap(array);
	for(let endIdx = array.length - 1; endIdx > 0; endIdx--){
		swap(0,endIdx,array);
		heapifyDown(0,endIdx -1, array);
	}
	return array;
}

function buildMaxHeap(array){
	const firstParentIdx = Math.floor((array.length - 2)/2);
	for(let i = firstParentIdx; i>=0; i--){
		heapifyDown(i, array.length - 1, array);
	}
}

function heapifyDown(parentIdx, endIdx, heap){
	let leftChildIdx = parentIdx * 2 + 1;
	while(leftChildIdx <= endIdx){
		let largerChildIdx = leftChildIdx;
		const rightChildIdx = parentIdx * 2 + 2 <= endIdx ? parentIdx * 2 + 2 : -1;
		if(rightChildIdx != -1 && heap[rightChildIdx] > heap[leftChildIdx]){
			largerChildIdx = rightChildIdx;
		}
		if(heap[parentIdx] > heap[largerChildIdx]){
			return;
		}
		else{
			swap(parentIdx,largerChildIdx,heap);
			parentIdx = largerChildIdx;
			leftChildIdx = parentIdx * 2 + 1;
		}
	}
}

function swap(i,j,array){
	const temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}


console.log(heapSort(array));
