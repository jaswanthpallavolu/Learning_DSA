> Split Wise
> Entities

-

- User (id, name)
- Group (id, name, creatorId)
- Participant (id, groupId, userId, role: admin | editor)
- Split (id, expense, groupId, creatorId)
- SplitShare (id, splitId, userId, expense, settledAt)

- enum SplitType (EQUAL, PERCENTAGE, EXACT)
- SplitStrategy

- SplitWiseService
- Expense
- Split
- User
- Group
- Participant
- BalanceSheet

```typescript
BalanceSheet: Map<User, Map<User, Amount>> // net balance
getBalances(userId) // returns amounts that other users owe to userId
```
