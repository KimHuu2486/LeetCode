class Bank {
private:
    vector<long long> bal;
    int n;
    bool valid(const int& account) { return account > 0 && account <= n; }

public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool transfer(const int& account1, const int& account2,
                  const long long& money) {
        if (valid(account1) && valid(account2)) {
            if (bal[account1 - 1] >= money) {
                bal[account1 - 1] -= money;
                bal[account2 - 1] += money;
                return true;
            }
        }
        return false;
    }

    bool deposit(const int& account, const long long& money) {
        if (valid(account)) {
            bal[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(const int& account, const long long& money) {
        if (valid(account) && bal[account - 1] >= money) {
            bal[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */