class Bank:

    def __init__(self, balance: List[int]):
        self.bal = balance
        self.n = len(balance)

    def valid(self, account):
        return account > 0 and account <= self.n

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if self.valid(account1) and self.valid(account2):
            if self.bal[account1 - 1] >= money:
                self.bal[account1 - 1] -= money
                self.bal[account2 - 1] += money
                return True
        return False

    def deposit(self, account: int, money: int) -> bool:
        if self.valid(account):
            self.bal[account - 1] += money
            return True
        return False

    def withdraw(self, account: int, money: int) -> bool:
        if self.valid(account) and self.bal[account - 1] >= money:
            self.bal[account - 1] -= money
            return True
        return False


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
