type Task = () => Promise<void>

class ExecutionService {
  private queue: Task[] = []
  private activeTasks: number = 0
  private readonly maxWorkers: number

  constructor(maxWorkers: number) {
    this.maxWorkers = maxWorkers
  }

  addToQueue(task: Task): void {
    this.queue.push(task)
    this.process()
  }

  private process(): void {
    while (this.activeTasks < this.maxWorkers && this.queue.length > 0) {
      const task = this.queue.shift()!
      this.activeTasks++
      task()
        .catch((error) => console.error("task failed", error))
        .finally(() => {
          this.activeTasks--
          this.process()
        })
    }
  }

  shutdown(): void {
    this.queue = []
  }
}
