// compose and pipe are functional programming utilities used to combine multiple functions into one.
// The only difference is the order in which functions are executed.

// pipe execution order left to right
// pipe(f1, f2, f3)(value) : f3(f2(f1(value)))

function pipe(...funcs) {
  return function (...args) {
    if (!funcs.length) throw new Error("No function has passed as an argument")

    return funcs.reduce((result, func, index) => {
      if (typeof func !== "function") throw new TypeError("Not a function")
      if (index === 0) return func.call(this, ...args)
      return func.call(this, result)
    }, undefined)
  }
}

// compose execution order right to left
// compose(f1,f2,f3)(value) : f1(f2(f3(value)))
function compose(...funcs) {
  return function (...args) {
    const self = this
    if (!funcs.length) throw new Error("No function has passed as an argument")

    function execute(index) {
      const func = funcs[index]
      if (typeof func !== "function") throw new TypeError("Not a function")

      if (index === funcs.length - 1) return func.call(self, ...args)
      return func.call(self, execute(index + 1))
    }
    return execute(0)
  }
}

const add1 = (x) => x + 1
const square = (x) => x * x
const double = (x) => x * 2

console.log(pipe(add1, square, double)(2))
console.log(compose(add1, square, double)(2))
