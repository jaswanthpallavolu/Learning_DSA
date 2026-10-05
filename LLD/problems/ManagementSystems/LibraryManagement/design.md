> Entities

- LibrarySystem
- CatalogManager
- Book
- BookCopy
- Member
- BorrowItem

>

- Book (id, title, author)
- BookCopy (id, bookId, status)
- BorrowItem (id, copyId, memberId, borrowedAt, returnedAt)
- Member (id, name)
- CatalogManager
  - books
  - bookCopies
  - getBooks()
  - borrowCopy(bookId)
  - returnCopy(copyId)
- LibrarySystem
  - borrowItems
  - getBooks()
  - borrowBookCopy(bookId, memberId)
  - returnBookCopy(borrowItemId, memberId)

> Focus

- Extensibility — adding fines/payment later without disturbing the core design.
- Concurrency/persistence — only if we decide to take the LLD beyond an in-memory interview implementation.
