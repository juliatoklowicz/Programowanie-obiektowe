import java.util.ArrayList;
import Customer.Customer;
import CustomerNotFoundException.CustomerNotFoundException;
import Account.Account;
import AccountLoginFailedException.AccountLoginFailedException;
import AccountNotFoundException.AccountNotFoundException;
import Bank.Bank;

public class WyjatkiJava {
    public static void main(String[] args) throws Exception {
        Bank b = new Bank();

        Customer Julia = new Customer("Julia");
        b.addCustomer(Julia);
        b.addAccount(new Account(1, Julia , 2408, "julia"));

        try 
        {
            System.out.println(b.findByName("abc").getName());
        }

        catch(CustomerNotFoundException ex)
        {
            ex.fillInStackTrace();
            ex.printStackTrace();
            try 
            {
                System.out.println(b.findByName("julia").getName());
            }

            catch(CustomerNotFoundException ex2)
            {
                System.out.println(ex.getMessage());
                System.out.println(ex.getName());  
            }

            ex.printStackTrace();
            System.out.println(ex.getMessage());
            System.out.println(ex.getName());           
        }
        try 
        {
            ArrayList<Account> a = b.findAllCustomerAcconts(Julia);
            for(int i = 0; i < a.size() ;i ++)
            {
                System.out.println(a.get(i).getNumber());
            }
        }

        catch(AccountNotFoundException ex)
        {
            System.out.println(ex.getMessage());
            System.out.println(ex.getCustomer().getName());           
        }

        try
        {
            Account a = b.findByNumber(1);
            System.out.println(a.getCustomer().getName());
            a.login("julia", 2408);
        }

        catch(AccountNotFoundException ex)
        {
            System.out.println(ex.getMessage());
            System.out.println(ex.getAccountN());
        }

        catch(AccountLoginFailedException ex)
        {
            System.out.println(ex.getMessage());
            System.out.println(ex.getLogin());
            System.out.println(ex.getPassword());
        }
        
            

    }
}
