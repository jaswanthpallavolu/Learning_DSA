class MyHeap {
  heap
  constructor() {
    this.heap = []
  }
  peek() {
    if (this.isEmpty()) return
    return this.heap[0]
  }

  push(val) {
    this.heap.push(val)
    this.bubbleUp(this.heap.length - 1)
  }

  pop() {
    if (this.isEmpty()) return
    if (this.heap.length === 1) return this.heap.pop()
    const peek = this.peek()
    this.heap[0] = this.heap.pop()
    this.bubbleDown(0)
    return peek
  }

  isEmpty() {
    return this.heap.length === 0
  }

  bubbleUp(index) {} // TODO: implement iterative method

  bubbleDown(index) {} // TODO: implement iterative method

  swap(i, j) {
    const temp = this.heap[i]
    this.heap[i] = this.heap[j]
    this.heap[j] = temp
  }
}

class MinPQ extends MyHeap {
  bubbleUp(index) {
    if (index === 0) return

    const root = Math.floor((index - 1) / 2)
    if (this.heap[root][1] > this.heap[index][1]) {
      this.swap(root, index)
      this.bubbleUp(root)
    }
  }

  bubbleDown(index) {
    const left = 2 * index + 1
    const right = 2 * index + 2
    const size = this.heap.length
    let target = index
    if (left < size && this.heap[left][1] < this.heap[target][1]) target = left
    if (right < size && this.heap[right][1] < this.heap[target][1])
      target = right
    if (target !== index) {
      this.swap(target, index)
      this.bubbleDown(target)
    }
  }
}
