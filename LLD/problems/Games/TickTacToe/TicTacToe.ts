function TicTacToe() {
  type Character = "X" | "O"
  type GameStatus = "Continue" | "Won" | "Draw"
  class Player {
    constructor(public readonly name: string) {}
  }

  class Game {
    players: [Player, Character][]
    currentPlayerIndex: number
    board = new Board()
    status: GameStatus

    constructor(player1: Player, player2: Player) {
      this.players = [
        [player1, "X"],
        [player2, "O"],
      ]
      this.currentPlayerIndex = 0
      this.status = "Continue"
    }

    private nextTurn() {
      this.currentPlayerIndex = this.currentPlayerIndex === 0 ? 1 : 0
    }

    place(row: number, col: number) {
      if (this.status !== "Continue") return
      if (!this.board.isCellAvailable(row, col)) return
      const [player, character] = this.players[this.currentPlayerIndex]
      this.board.fillCell(row, col, character)

      if (this.board.isWinningLine(row, col)) {
        this.status = "Won"
        console.log(`${player.name} Won`)
        return
      }

      if (this.board.areCellsOccupied()) {
        this.status = "Draw"
        console.log("Game Draw")
        return
      }

      this.nextTurn()
    }

    reset() {
      this.currentPlayerIndex = 0
      this.board = new Board()
      this.status = "Continue"
    }
  }

  class Board {
    cells: Character[][]
    rows = 3
    cols = 3
    fillCount: number
    constructor() {
      this.cells = Array.from({ length: this.rows }, () => new Array(this.cols))
      this.fillCount = 0
    }

    isCellAvailable(row: number, col: number): boolean {
      if (row < 0 || row > this.rows - 1 || col < 0 || col > this.cols - 1)
        return false
      return this.cells[row][col] === undefined
    }

    fillCell(row: number, col: number, char: Character) {
      this.cells[row][col] = char
      this.fillCount++
    }

    isWinningLine(row: number, col: number): boolean {
      return false
    }

    areCellsOccupied(): boolean {
      return this.fillCount === this.rows * this.cols
    }
  }

  const player1 = new Player("jaswanth")
  const player2 = new Player("pallavolu")
  const game = new Game(player1, player2)

  game.place(1, 1)
}
