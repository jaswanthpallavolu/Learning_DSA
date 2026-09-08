// Composition: building a class by combining objects rather than inherit them
function composition() {
  class Engine {
    start() {
      console.log("Engine started")
    }
  }

  class Car {
    constructor(private engine: Engine) {}

    drive() {
      this.engine.start()
      console.log("Car is driving")
    }
  }
}

// interface vs abstract class
// Interface: define a contract
// Abstract class: define a contract + shared implementation
function Interface() {
  interface Animal {
    name: string
    makeSound(): void
  }

  class Dog implements Animal {
    name: string
    constructor(name: string) {
      this.name = name
    }

    makeSound(): void {
      console.log("woof")
    }
  }
}

function Abstract() {
  abstract class Animal {
    constructor(public name: string) {}

    abstract makeSound(): void

    eat() {
      console.log(`${this.name} is eating`)
    }
  }

  class Dog extends Animal {
    makeSound() {
      console.log("Woof")
    }
  }
}

/*
OOP is a programming paradigm that organizes code around objects, combining data and behavior, and 
uses concepts such as encapsulation, abstraction, inheritance, and polymorphism 
to make software more modular and maintainable.
*/

// Encapsulation → bundle/hide data and behavior

// Abstraction   → expose essentials, hide complexity
function Abstraction() {
  abstract class Vehicle {
    abstract start(): void // every vehicle must have start

    stop(): void {
      console.log("Vehicle stopped")
    }
  }

  class Car extends Vehicle {
    start(): void {
      console.log("Car engine started")
    }
  }

  class Bike extends Vehicle {
    start() {
      console.log("Starting bike...")
    }
  }

  const car = new Car()
  car.start()
  const bike = new Bike()
  bike.start()
}

// Inheritance   → derive one class from another

// Polymorphism  → same interface, different behavior
function Polymorphism() {
  interface Payment {
    pay(amount: number): void
  }

  class CreditCard implements Payment {
    pay(amount: number) {
      console.log(`Paid ₹${amount} using Credit Card`)
    }
  }

  class UPI implements Payment {
    pay(amount: number) {
      console.log(`Paid ₹${amount} using UPI`)
    }
  }

  function processPayment(payment: Payment) {
    payment.pay(1000)
  }

  processPayment(new CreditCard())
  processPayment(new UPI())
}
