// blind, call, apply helps you to control the value of 'this' when function is executed

// Object(value) converts a primitive into its corresponding wrapper object.
// This is called boxing.

// because native apply treats both null and undefined as the default this value (with the usual strict/non-strict function semantics).
// thisArg == null, use == instead of ===

// Function.prototype.call
Function.prototype.myCall = function (thisArg, ...argArray) {
  thisArg = thisArg === null ? globalThis : Object(thisArg)
  const key = Symbol()
  thisArg[key] = this
  try {
    return thisArg[key](...argArray)
  } finally {
    delete thisArg[key]
    // cleanup
  }
}

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

// Function.prototype.bind
Function.prototype.myBind = function (thisArg, ...initArgs) {
  thisArg = thisArg === null ? globalThis : Object(thisArg)
  const fn = this
  return function (...argArray) {
    const key = Symbol()
    thisArg[key] = fn
    try {
      return thisArg[key](...initArgs, ...argArray)
    } finally {
      delete thisArg[key]
    }
  }
}
