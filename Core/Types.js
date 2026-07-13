// TYPE CHECKING

// typeof - [number, string, object, undefined, boolean, function]
console.log(typeof null, typeof [], typeof function getName() {})

console.log(Array.isArray([]))

// instanceof - check whether the object is created from a constructor
console.log([] instanceof Array, {} instanceof Object)

// TYPE CONVERSION (COERSION)
console.log(Number("345"), String(123), Boolean(1))
console.log(String([1, [2, 3]]))
console.log(String({})) // [object Type]

// implicit type conversion
console.log("5" + 1, 4 + "10")
console.log("5" - 1) // substraction only works on numbers

console.log(Boolean({}), Boolean([])) // Objects are always truthy
console.log({} + [], [] + [])
