/* 
this refers to the object associated with the current function invocation. 
For normal functions, its value is determined by how the function is called. 
Arrow functions don't have their own this; they lexically inherit it from the surrounding scope.
*/

const user = {
  name: "jaswanth",
  greetA: function () {
    console.log("Hello ", this.name)
  },
  greetB: () => {
    console.log("Hello ", this.name)
  },
}

user.greetA()
user.greetB()
