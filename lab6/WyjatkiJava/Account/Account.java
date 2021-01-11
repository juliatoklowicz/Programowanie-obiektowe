package Account;

import Customer.Customer;

import AccountLoginFailedException.*;

public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account() 
    {
        accountNumber = 0;
        password = 0;
        login = "";
    }

    public Account ( int n , Customer c , int p , String l ) {
        accountNumber = n;
        owner = c;
        password = p;
        login = l;
    }

    public void login ( String l , int passwd )
    throws AccountLoginFailedException 
    {
        if (l.equals(login))
        {
            if (passwd == password)
            {
                System.out.println("Zalogowano pomyslnie");
                return;
            }
        }
        throw new AccountLoginFailedException("Nieprawidlowy login lub haslo",l ,passwd);
    }

    public Customer getCustomer ( ) {
        return owner;
    }

    public int getNumber ( ) 
    {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    public double withdraw (double amount ) {
        balance += amount;
        return balance;
    }
}
    
