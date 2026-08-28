class ListNode {
  constructor(
    public val: number,
    public prev: ListNode | null,
    public next: ListNode | null,
  ) {}
}

class DoublyLinkedList {
  head: ListNode | null = null
  tail: ListNode | null = null
  size: number = 0

  // insert at the beginning
  insert(node: ListNode) {
    node.prev = null

    if (!this.head) {
      node.next = null
      this.head = node
      this.tail = node
    } else {
      this.head.prev = node
      node.next = this.head
      this.head = node
    }
    this.size++
  }

  delete(node: ListNode): ListNode | null {
    if (this.tail === node) {
      return this.deleteTail()
    }

    if (this.head === node) {
      const nextNode = this.head.next
      if (nextNode) nextNode.prev = null
      this.head = nextNode
    } else {
      if (node.prev) node.prev.next = node.next
      if (node.next) node.next.prev = node.prev
    }

    node.prev = null
    node.next = null
    this.size--
    return node
  }

  deleteTail(): ListNode | null {
    if (!this.tail) return null
    const tailNode = this.tail
    const prevNode = tailNode.prev
    if (prevNode) prevNode.next = null
    this.tail = prevNode
    tailNode.prev = null
    this.size--
    if (this.size === 0) this.head = null

    return tailNode
  }
}

// O(1) - put / get
class LRUCache {
  limit: number
  cache: Map<number, ListNode>
  list: DoublyLinkedList

  constructor(limit: number) {
    this.limit = limit
    this.cache = new Map()
    this.list = new DoublyLinkedList()
  }

  put(val: number) {
    if (this.limit === 0) return
    let node = this.cache.get(val)
    if (node) {
      this.list.delete(node)
      this.list.insert(node)
      return
    }

    node = new ListNode(val, null, null)
    if (this.list.size === this.limit) {
      const tail = this.list.deleteTail()
      if (tail) {
        this.cache.delete(tail.val)
      }
    }
    this.list.insert(node)
    this.cache.set(val, node)
  }

  get(val: number): number {
    const node = this.cache.get(val)
    if (!node) {
      return -1
    }

    this.list.delete(node)
    this.list.insert(node)
    return node.val
  }
}
