class MyHeap {
  arr = []

  peek() {
    if (this.isEmpty()) return
    return this.arr[0]
  }

  push(val) {
    this.arr.push(val)
    this.bubbleUp(this.arr.length - 1)
  }

  pop() {
    if (this.isEmpty()) return
    if (this.size() === 1) return this.arr.pop()
    const top = this.arr[0]
    this.arr[0] = this.arr.pop()
    this.bubbleDown(0)
    return top
  }

  bubbleUp(index) {
    if (index === 0) return
    const parent = Math.trunc((index - 1) / 2)
    if (this.compare(parent, index)) {
      this.swap(parent, index)
      this.bubbleUp(parent)
    }
  }

  bubbleDown(index) {
    const left = 2 * index + 1
    const right = 2 * index + 2
    let target = index
    if (left < this.size() && this.compare(target, left)) {
      target = left
    }
    if (right < this.size() && this.compare(target, right)) {
      target = right
    }
    if (target !== index) {
      this.swap(target, index)
      this.bubbleDown(target)
    }
  }

  compare(index1, index2) {}

  swap(index1, index2) {
    const temp = this.arr[index1]
    this.arr[index1] = this.arr[index2]
    this.arr[index2] = temp
  }

  isEmpty() {
    return this.arr.length === 0
  }

  size() {
    return this.arr.length
  }
}

class MyMinHeap extends MyHeap {
  compare(index1, index2) {
    return this.arr[index1] > this.arr[index2]
  }
}
