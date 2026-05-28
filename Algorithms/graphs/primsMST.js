class MyHeap {
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

  bubbleUp(index) {}

  bubbleDown(index) {}

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

// T.C O(ElogV)
function primsMST(n, graphs) {
  const visited = new Array(n).fill(false)
  const dist = new Array(n).fill(Infinity)
  let weight = 0
  const pq = new MinPQ()
  pq.push([[0, -1], 0]) // [[node, parent], weight]

  while (!pq.isEmpty()) {
    const [[u, parent], w] = pq.pop()
    if (visited[u]) continue
    visited[u] = true

    if (parent !== -1) weight += w

    for (const [v, w] of graphs[u]) {
      if (visited[v]) continue
      pq.push([[v, u], w])
    }
  }

  return weight
}

// T.C O(n^2)
const points = [
  [3, 12],
  [-2, 5],
  [-4, 1],
]

function primsMST(points) {
  const n = points.length
  const visited = new Array(n).fill(false)
  const dist = new Array(n).fill(Infinity)
  let weight = 0
  dist[0] = 0
  let visitedNodes = 0

  while (visitedNodes !== n) {
    let minWeight = Infinity
    let u = 0
    for (let i = 0; i < n; i++) {
      if (visited[i]) continue
      if (minWeight > dist[i]) {
        minWeight = dist[i]
        u = i
      }
    }
    visited[u] = true
    visitedNodes += 1

    weight += minWeight

    for (let v = 0; v < n; v++) {
      if (visited[v]) continue
      const distance =
        Math.abs(points[u][0] - points[v][0]) +
        Math.abs(points[u][1] - points[v][1])
      if (dist[v] > distance) dist[v] = distance
    }
  }

  return weight
}
