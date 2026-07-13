// Ascii
console.log("A".charCodeAt(0), "a".charCodeAt(0))
console.log(String.fromCharCode(97))

// console.log('A' - 0); // NaN

console.log(/[a-z0-9A-Z]/.test("@"))

console.log("Jaswanth".startsWith("Jas"))

console.log([..."jaswanth"].sort())
console.log("jas wanth".split(" ").join("-"))

// .slice(start, end) - end is non-inclusive
console.log("012345".slice(1, 5))
