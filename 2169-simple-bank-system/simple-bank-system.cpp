class Bank {
private:
    std::vector<long long> balance_;
    int n_;

    bool isValid(int account) const {
        return account >= 1 && account <= n_;
    }

public:
    Bank(std::vector<long long>& balance) {
        balance_ = balance;
        n_ = (int)balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) {
            return false;
        }
        if (balance_[account1 - 1] < money) {
            return false;
        }
        balance_[account1 - 1] -= money;
        balance_[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValid(account)) {
            return false;
        }
        balance_[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account)) {
            return false;
        }
        if (balance_[account - 1] < money) {
            return false;
        }
        balance_[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */