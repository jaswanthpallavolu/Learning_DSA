// blind, call, apply helps you to control the value of 'this' when function is executed

// Object(value) converts a primitive into its corresponding wrapper object.
// This is called boxing.

// Function.prototype.call
Function.prototype.myCall = function (thisArg, ...argArray) {
  thisArg = thisArg === null ? globalThis : Object(thisArg)
  const key = Symbol()
  thisArg[key] = this
  try {
    return thisArg[key](...argArray)
  } finally {
    delete thisArg[key]
  }
}

// Function.prototype.bind
Function.prototype.myBind = function (thisArg, ...initArgs) {
  thisArg = thisArg === null ? globalThis : Object(thisArg)
  const fn = this
  return function (...argArray) {
    const key = Symbol()
    thisArg[key] = this
    try {
      return thisArg[key](...initArgs, ...argArray)
    } finally {
      delete thisArg[key]
    }
  }
}
