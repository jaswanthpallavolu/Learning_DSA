// Represent an operation as an object

interface Command {
  execute(): void
  undo(): void
}

class CommandManager {
  private history: Command[] = []
  private current: number = 0

  execute(command: Command) {
    command.execute()
    if (this.current < this.history.length - 1)
      this.history = this.history.slice(0, this.current + 1)
    this.history.push(command)
    this.current++
  }

  undo() {
    if (!this.canUndo()) return
    this.history[this.current].undo()
    this.current--
  }

  redo() {
    if (!this.canRedo()) return
    this.current++
    this.history[this.current].execute()
  }

  canRedo() {
    return this.current < this.history.length - 1
  }

  canUndo() {
    return this.current >= 0
  }
}
