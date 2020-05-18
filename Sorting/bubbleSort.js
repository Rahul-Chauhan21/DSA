//Bubble Sort inplace algorithm
// O(n^2) time | O(1) space
function bubbleSort(array){
  let isSorted = false;
  let counter = 0;
  while(!isSorted){  // keep traversing through array if any swap takes place in the previous pass.
    isSorted = true;
      for(let i = 0; i < array.length - 1 - counter; i++){ //each pass fixes a last element (maxima) of current subarray.
        if(array[i] > array[i+1]){
          swap(i,i+1,array);
          isSorted = false;
        }
      }
      counter++;
  }
  return array;
}

function swap(i,j,array){
  const temp = array[j];
  array[j] = array[i];
  array[i] = temp;
}
console.log(bubbleSort([8,5,2,9,5,6,3]));
