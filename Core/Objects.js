// SET
const nodes = new Set()
nodes.add("A")
nodes.add("B")
for (let node of [...nodes.values()]) {
  console.log(node)
}
nodes.delete("A")
console.log(nodes.size, nodes.has("B"))

// MAP vs Object
// Object keys don't preserve the actual type, all of them consider as type string
const map = new Map()
map.set(23, "Hello")
for (let key of [...map.keys()]) {
  console.log(key, typeof key, map.get(key))
}

const obj = Object.create({ 23: "hello" })
for (let key in obj) {
  console.log(key, typeof key)
}

// Map compares object keys by reference, not by their contents.

// Array

// This pattern—collect with ...args, then later spread with ...args

// func.apply(this, args);
// "Call func as if it were called by the same object that called this wrapper, using these arguments."
// fn.length is a built-in JavaScript property that returns the number of parameters a function is declared with (its arity).
