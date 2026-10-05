function add(a, b, c) {
  return a + b + c
}

function curry(func) {
  const requiredArgs = func.length

  function curried(...args) {
    if (args.length >= requiredArgs) return func.apply(this, args)

    return function (...nextArgs) {
      return curried.apply(this, [...args, ...nextArgs])
    }
  }
  return curried
}

const curriedAdd = curry(add)
console.log(curriedAdd(1, 2)(3), curriedAdd(4)(2, 2))
