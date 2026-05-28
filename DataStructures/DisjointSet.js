// Disjoint Set / union-find

class DisjoinSet {
  constructor(size) {
    this.parent = Array.from({ length: size }, (_, index) => index)
    this.rank = new Array(size).fill(0)
  }

  find(index) {
    if (this.parent[index] != index)
      this.parent[index] = this.find(this.parent[index])

    return this.parent[index]
  }

  union(x, y) {
    const rootX = this.find(x)
    const rootY = this.find(y)

    if (rootX === rootY) return false

    if (this.rank[rootX] < this.rank[rootY]) this.parent[rootX] = rootY
    else if (this.rank[rootX] > this.rank[rootY]) this.parent[rootY] = rootX
    else {
      this.parent[rootY] = rootX
      this.rank[rootX]++
    }
    return true
  }
}
