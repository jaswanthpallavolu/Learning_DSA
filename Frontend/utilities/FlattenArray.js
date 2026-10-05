// const flattenArray = (value) => {
//   if (!Array.isArray(value)) return [value]
//   const result = []
//   for (const item of value) {
//     result.push(...flattenArray(item))
//   }
//   return result
// }

// const flattenArray = (value, result = []) => {
//   if (!Array.isArray(value)) {
//     result.push(value)
//     return result
//   }

//   for (const item of value) {
//     flattenArray(item, result)
//   }
//   return result
// }

const flattenArray = (value) => {
  const stack = [...value].reverse()
  const result = []
  while (stack.length) {
    const item = stack.pop()
    if (Array.isArray(item)) {
      for (let i = item.length - 1; i >= 0; i--) {
        stack.push(item[i])
      }
    } else {
      result.push(item)
    }
  }
  return result
}

console.log(flattenArray(array))
