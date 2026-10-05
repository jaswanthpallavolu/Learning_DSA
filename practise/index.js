class MyNode {
  constructor(key, val, prev, next) {
    this.key = key
    this.val = val
    this.prev = prev ?? null
    this.next = next ?? null
  }
}

/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
  this.map = new Map()
  this.capacity = capacity
  this.size = 0
  this.head = null
  this.tail = null
}

LRUCache.prototype.addAtHead = function (node) {
  if (this.size === 0) {
    this.head = node
    this.tail = node
    this.size++
    return
  }

  node.prev = null
  node.next = this.head
  this.head.prev = node
  this.head = node
  this.size++
}

LRUCache.prototype.remove = function (node) {
  if (this.size === 1) {
    this.tail = null
    this.head = null
  } else if (node === this.tail) {
    this.tail = this.tail.prev
    this.tail.next = null
  } else if (node === this.head) {
    this.head = this.head.next
    this.head.prev = null
  } else {
    const prev = node.prev
    const next = node.next
    prev.next = next
    if (next) next.prev = prev
  }
  this.size--
  node.next = null
  node.prev = null
  return node
}

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
  if (!this.map.has(key)) return -1
  const node = this.map.get(key)
  this.remove(node)
  this.addAtHead(node)
  return node.val
}

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
  let node = null
  if (this.map.has(key)) {
    node = this.map.get(key)
    node.val = value
    node = this.remove(node)
  } else {
    node = new MyNode(key, value)
    this.map.set(key, node)
  }
  this.addAtHead(node)

  if (this.size > this.capacity) {
    const removeNode = this.remove(this.tail)
    this.map.delete(removeNode.key)
  }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
