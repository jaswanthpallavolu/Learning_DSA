// Objects need notification

// Observer, One object changes → many objects need to react
// Subject changes --> notify all observers
class Stock {
  observers: Investor[]
  price: number
  constructor() {
    this.observers = []
    this.price = 0
  }

  subscribe(observer: Investor) {
    this.observers.push(observer)
  }

  notify() {
    this.observers.forEach((observer) => observer.update())
  }

  setPrice(price: number) {
    this.price = price
    this.notify()
  }
}

class Investor {
  update() {
    console.log("Stock price changed!")
  }
}

// Pub/Sub - publisher doesn't know who the subscribers are.
type Callback = (data: any) => void
class EventBus {
  events: Map<string, Callback[]>
  constructor() {
    this.events = new Map()
  }

  subscribe(event: string, callback: Callback) {
    if (!this.events.has(event)) this.events.set(event, [])
    this.events.get(event)?.push(callback)
  }

  publish(event: string, data: any) {
    const callbacks = this.events.get(event) ?? []
    callbacks.forEach((callback) => callback(data))
  }
}

// Event Emitter/Event Listener
class EventEmitter {
  events = new Map<string, Set<Callback>>()

  on(event: string, callback: Callback) {
    if (!this.events.has(event)) {
      this.events.set(event, new Set())
    }

    this.events.get(event)!.add(callback)

    // return unSubscribe function
    return () => this.off(event, callback)
  }

  // once - TODO

  emit(event: string, data: any) {
    this.events.get(event)?.forEach((callback) => {
      callback(data)
    })
  }

  off(event: string, callback: Callback) {}
}
