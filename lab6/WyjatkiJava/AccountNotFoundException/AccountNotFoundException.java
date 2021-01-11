package AccountNotFoundException;

import Customer.Customer;

public class AccountNotFoundException extends Exception{
    static final long serialVersionUID = 1L ;
    private int n_account;
    private Customer c;
    public AccountNotFoundException ( ) { }
    public AccountNotFoundException ( String errorMsg , int s ) {
        super ( errorMsg ) ;
        n_account = s ;
    }
    public AccountNotFoundException ( String errorMsg , Customer cust ) {
        super ( errorMsg ) ;
        c = cust ;
    }
    public int getAccountN(){
        return n_account;
    }
    public Customer getCustomer()
    {
        return c;
    }
}