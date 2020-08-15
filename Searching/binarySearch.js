function binarySearch(array, x){
  let low = 0, high = array.length - 1;
    while(low <= high){
      const mid = Math.floor(low + (high - low)/2);
      if(array[mid] === x){
        return mid;
      }
      else if(array[mid] > x){
        high = mid - 1;
      }
      else{
        low = mid + 1;
      }
    }
    return -1;
}

console.log(binarySearch([1,2,3,4,5], 4));
