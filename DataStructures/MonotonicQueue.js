class MonotonicQueue {
  constructor(arr) {
    this.arr = arr
    this.head = 0
    this.queue = []
  }

  push(index) {
    while (this.queue.length && this.compare(index)) {
      this.queue.pop()
    }
    this.queue.push(index)
  }

  pop() {
    if (this.head >= this.arr.length || !this.queue.length) return
    const val = this.arr[this.head++]
    if (this.arr[this.queue[0]] === val) this.queue.shift()
    return val
  }

  peek() {
    if (!this.queue.length) return
    return this.arr[this.queue[0]]
  }

  compare(index) {
    return this.arr[index] > this.arr[this.queue[this.queue.length - 1]]
  }
}
