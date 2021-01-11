package CustomerNotFoundException;

public class CustomerNotFoundException extends Exception{
    static final long serialVersionUID = 1L ;
    private String n_cust;

    public CustomerNotFoundException ( ) {}
    public CustomerNotFoundException ( String errorMsg , String s ) {
        super ( errorMsg ) ;
        n_cust = s ;
        
    }
    public String getName(){
        return n_cust;
    }
}