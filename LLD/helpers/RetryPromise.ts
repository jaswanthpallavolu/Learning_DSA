class RetryPromise {
  private readonly maxRetry: number
  private retryDelay: number

  constructor(maxRetry: number, delay: number) {
    this.maxRetry = maxRetry
    this.retryDelay = delay
  }

  async execute(task: Task): Promise<void> {
    let attempts = 0
    while (attempts <= this.maxRetry) {
      try {
        await task()
        return
      } catch (error) {
        attempts++
        if (attempts > this.maxRetry) throw error
        await this.delayRetry()
      }
    }
  }

  private delayRetry(): Promise<void> {
    return new Promise((resolve) => setTimeout(resolve, this.retryDelay))
  }
}
