// DI:  a technique for providing an object with dependencies it needs, instead of having it create them itself
function DI() {
  class Engine {}

  class Car {
    engine: Engine
    constructor(engine: Engine) {
      this.engine = engine
    }
  }
}
