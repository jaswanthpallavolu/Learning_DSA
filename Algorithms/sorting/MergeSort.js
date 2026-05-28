// divide and conquer

const arr = [4, 1, 3, 6, 2, 1];

function mergeSort(arr) {
  const size = arr.length;
  if (size <= 1) return arr;

  const mid = Math.trunc(size / 2);
  const arr1 = mergeSort(arr.slice(0, mid));
  const arr2 = mergeSort(arr.slice(mid));

  return mergeArrays(arr1, arr2);
}

function mergeArrays(arr1, arr2) {
  const size1 = arr1.length;
  const size2 = arr2.length;

  let i = 0;
  let j = 0;
  const result = [];
  while (i < size1 && j < size2) {
    if (arr1[i] > arr2[j]) {
      result.push(arr2[j++]);
    } else {
      result.push(arr1[i++]);
    }
  }

  return result.concat(arr1.slice(i)).concat(arr2.slice(j));
}

console.log(mergeSort(arr));
