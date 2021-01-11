package Bank;

import Customer.Customer;
import java.util.ArrayList;
import Account.Account;

import CustomerNotFoundException.CustomerNotFoundException;
import AccountNotFoundException.AccountNotFoundException;

interface SearchCustomers{
    Customer findByName(String name)
                throws CustomerNotFoundException;
}

interface SearchAccounts{
    Account findByNumber(int number)
                throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAcconts(Customer cust)
                throws AccountNotFoundException;
}

public class Bank implements SearchAccounts , SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<Customer > ( );
    ArrayList<Account> accounts = new ArrayList<Account > ( );

    @Override
    public Customer findByName ( String name )
    throws CustomerNotFoundException {
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers.get(i).getName().equals(name))
            {
                return customers.get(i);
            }
        }
        throw new CustomerNotFoundException("Nie znaleziono", name);
    }

    @Override
    public Account findByNumber ( int num)
    throws AccountNotFoundException {
        for(int i = 0; i < accounts.size(); i++)
        {
            if(accounts.get(i).getNumber() == num)
            {
                return accounts.get(i);
            }
        }
        throw new AccountNotFoundException("Nie znaleziono", num);
    }

    @Override
    public ArrayList<Account> findAllCustomerAcconts(Customer cust)
                throws AccountNotFoundException {
        ArrayList<Account> accounts_find = new ArrayList<Account > ( );
        for(int i = 0; i < accounts.size(); i++)
        {
            if(accounts.get(i).getCustomer() == cust)
            {
                accounts_find.add(accounts.get(i));
            }
        }
        if(accounts_find.size() > 0)
        {
            return accounts_find;
        }
        throw new AccountNotFoundException("Nie znaleziono", cust);
    }

    public void addCustomer(Customer cust){
            customers.add(cust);
    }

    public void addAccount(Account a){
        accounts.add(a);
    }

    public void delCustomer(Customer cust){
        customers.remove(cust);
    }
    
    public void delAccount(Account a){
        accounts.remove(a);
    }
}
    
