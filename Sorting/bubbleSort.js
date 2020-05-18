//Bubble Sort inplace algorithm
// O(n^2) time | O(1) space
function bubbleSort(array){
  let isSorted = false;
  let counter = 0;
  while(!isSorted){  // keep traversing through array if any swap takes place in the previous pass.
    isSorted = true;
      for(let i = 0; i < array.length - 1 - counter; i++){ // counter is used for setting sorted elements to the end.
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
