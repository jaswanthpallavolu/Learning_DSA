// worst case O(n^2) and avg O(nlog(n))

const arr = [5, 2, 8, 1, 3]

function quickSort(arr) {
  const size = arr.length
  if (size <= 1) return arr

  const pivot = arr[size - 1]
  const left = []
  const right = []

  for (let i = 0; i < size - 1; i++) {
    if (arr[i] < pivot) left.push(arr[i])
    else right.push(arr[i])
  }
  return [...quickSort(left), pivot, ...quickSort(right)]
}

console.log(quickSort(arr))
