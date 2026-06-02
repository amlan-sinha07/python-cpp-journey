class BankAccount:
    def __init__(self,name,balance):
        self.name=name
        self.balance=balance
    def deposit(self,amount):
        try:
            if not isinstance(amount,(int,float)):
                raise TypeError("amount must be a number")
            if amount<=0:
                raise ValueError("amount must be positive")
            self.balance+=amount
            print(f"deposited {amount} . new balance {self.balance}")
        except TypeError as e:
            print(f"error: {e}")
        except ValueError as e:
            print(f"error: {e}")
    def withdraw(self,amount):
        try:
            if not isinstance(amount,(float,int)):
                raise TypeError("amount must be a number")
            if amount<=0:
                raise ValueError("amount should be positive")
            elif self.balance>=amount:
                self.balance-=amount
                print(f"withdraw {amount}, current balance {self.balance}")
            else:
                print("insufficient funds")
        except TypeError as e:
            print(f"error {e}")
        except ValueError as e :
            print(f"error: {e}")
    def show_balance(self):
        print(f"current balance= {self.balance}")
a1=BankAccount("Amlan",1000)
a1.deposit(5000)
a1.withdraw(1000)
a1.show_balance()