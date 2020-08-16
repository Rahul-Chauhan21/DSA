//best case O(log(log n)) time | O(1) space
// worst case O(n) time
function interpolationSearch(array , x){
  let low = 0, high = array.length - 1;
  while(low <= high && x >= array[low] && x <= array[high]){
    if(low === high){
      if(array[low] === x){
        return low;
      }
      return -1;
    }
    let position = low + Math.floor((high - low)/ (array[high] - array[low]) * (x - array[low]));
    if(array[position] === x){
      return position;
    }

    if(array[position] < x){
      low = position + 1;
    }
    else {
      high = position - 1;
    }
  }
  return -1;
}

console.log(interpolationSearch([10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47], 18));
