/*
Base Case: If array size is 1, return.
Do One Pass of normal Bubble Sort. This pass fixes last element of current subarray.
Recur for all elements except last of current subarray
*/
array = [8,5,2,9,5,6,3];
function bubbleSortRecur(array,n){
  if(n == 1){
    return array; // All iterations are complete return the array.
  }
    for(let i = 0; i < n - 1; i++){ // each pass fixes a last element (maxima) of current subarray.
      if(array[i] > array[i+1]){
        swap(i,i+1,array);
      }
    }
    return bubbleSortRecur(array,n-1);
}

function swap(i,j,array){
  const temp = array[j];
  array[j] = array[i];
  array[i] = temp;
}

console.log(bubbleSortRecur(array,array.length));
