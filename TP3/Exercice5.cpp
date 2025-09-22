class BankAccount {
private:
	int number;
	std::string owner;
	float balance;
	
public:
    BankAccount(int number, std::string owner, float balance)
        : number(number), owner(owner), balance(balance) {}

    virtual void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Depot de " << amount << " effectue. Nouveau solde: " << balance << std::endl;
        }
        else {
            std::cout << "Montant invalide pour le depot." << std::endl;
        }
    }

    virtual void withdrawal(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Retrait de " << amount << " effectue. Nouveau solde: " << balance << std::endl;
        }
        else {
            std::cout << "Montant invalide pour le retrait ou solde insuffisant." << std::endl;
        }
    }

    float getBalance() const {
        return balance;
    }
};

// Classe CheckingAccount
class CheckingAccount : public BankAccount {
private:
    float overdraftLimit;

public:
    CheckingAccount(int number, std::string owner, float balance, float overdraftLimit)
        : BankAccount(number, owner, balance), overdraftLimit(overdraftLimit) {}

    void withdrawal(float amount) override {
        if (amount > 0 && (balance - amount) >= -overdraftLimit) {
            balance -= amount;
            std::cout << "Retrait de " << amount << " effectue. Nouveau solde: " << balance << std::endl;
        }
        else {
            std::cout << "Montant invalide pour le retrait ou limite de decouvert depassee." << std::endl;
        }
    }

    void transfer(float amount, BankAccount& otherAccount) {
        if (amount > 0 && (balance - amount) >= -overdraftLimit) {
            balance -= amount;
            otherAccount.deposit(amount);
            std::cout << "Transfert de " << amount << " effectue vers le compte " << otherAccount.number << std::endl;
        }
        else {
            std::cout << "Montant invalide pour le transfert ou limite de decouvert depassee." << std::endl;
        }
    }
};

// Classe SavingsAccount
class SavingsAccount : public BankAccount {
private:
    float annualInterestRate;

public:
    SavingsAccount(int number, std::string owner, float balance, float annualInterestRate)
        : BankAccount(number, owner, balance), annualInterestRate(annualInterestRate) {}

    void depositAnnualInterest() {
        float interest = balance * (annualInterestRate / 100);
        balance += interest;
        std::cout << "Interets annuels de " << interest << " ajoutes. Nouveau solde: " << balance << std::endl;
    }
};

int main() {
    // Test des classes
    CheckingAccount checking(12345, "Alice", 1000.0f, 500.0f);
    SavingsAccount savings(67890, "Bob", 2000.0f, 2.5f);

    std::cout << "--- Test du CheckingAccount ---" << std::endl;
    checking.deposit(300.0f);
    checking.withdrawal(200.0f);
    checking.withdrawal(1400.0f); // Test de la limite de decouvert
    checking.transfer(300.0f, savings);

    std::cout << "\n--- Test du SavingsAccount ---" << std::endl;
    savings.deposit(500.0f);
    savings.withdrawal(100.0f);
    savings.depositAnnualInterest();

    return 0;