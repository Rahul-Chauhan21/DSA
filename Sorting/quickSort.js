function testSortingAlgo(){
  for(let i = 0; i < 100; i++){
    const array = [];
    const length = randomIntFromInterval(1,1000);
    for(let i = 0; i < length; i++){
      array.push(randomIntFromInterval(-1000,1000));
    }
    const javaScriptSortedArray = array.slice().sort((a,b) => a - b);
    const sortedAlgoArray = quickSort(array.slice());
    console.log(arraysAreEqual(javaScriptSortedArray,sortedAlgoArray));
  }
}

function randomIntFromInterval(min,max){
  // max and min inclusive
  return Math.floor(Math.random() * (max - min + 1) + min);
}

function arraysAreEqual(arrayOne,arrayTwo){
  if(arrayOne.length !== arrayTwo.length) return false;
  for(let i = 0; i < arrayOne.length; i++){
    if(arrayOne[i] !== arrayTwo[i]){
      return false;
    }
  }
  return true;
}

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

function testSortingAlgo(){
  for(let i = 0; i < 100; i++){
    const array = [];
    const length = randomIntFromInterval(1,1000);
    for(let i = 0; i < length; i++){
      array.push(randomIntFromInterval(-1000,1000));
    }
    const javaScriptSortedArray = array.slice().sort((a,b) => a - b);
    const sortedAlgoArray = quickSort(array.slice());
    console.log(arraysAreEqual(javaScriptSortedArray,sortedAlgoArray));
  }
}

function randomIntFromInterval(min,max){
  // max and min inclusive
  return Math.floor(Math.random() * (max - min + 1) + min);
}

function arraysAreEqual(arrayOne,arrayTwo){
  if(arrayOne.length !== arrayTwo.length) return false;
  for(let i = 0; i < arrayOne.length; i++){
    if(arrayOne[i] !== arrayTwo[i]){
      return false;
    }
  }
  return true;
}

testSortingAlgo();
