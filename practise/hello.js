// function greet(city) {
//   return `Hi, I am ${this.name} from ${city}`
// }

// const user = {
//   name: "Rahul",
// }

// // greet is a function, but greet.prototype is the prototype used for objects created with new greet().
// greet.prototype.myCall = function (obj, ...args) {
//   obj.fn = this
//   const result = obj.fn(...args)
//   delete obj.fn
//   return result
// }

// const fn = new greet()
// console.log(fn.myCall(user, "Hello"))

// // console.log(greet.myCall(user, "Bangalore"))
// // "Hi, I am Rahul from Bangalore"

const array = [1, [2, 3], [[4], 5], 6]

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

Function.prototype.myApply = function (thisArg, args) {
  thisArg = thisArg === null ? globalThis : Object(thisArg)
  const key = Symbol()
  thisArg[key] = this
  try {
    return thisArg[key](...(args ?? []))
  } finally {
    delete thisArg[key]
  }
}
