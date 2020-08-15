function linearSearch(array, x){
  for(let i = 0; i < array.length; i++){
    if(array[i] === x){
      return i;
    }
  }
  return -1;
}
console.log(linearSearch([1,2,3,4,5] , 6));
