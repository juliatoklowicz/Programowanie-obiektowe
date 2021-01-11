package Customer;

public class Customer {

    private String imie;
    private String nazwisko;
    
    public Customer() 
    {
        imie="";
    }

    public Customer (String s) {
        imie = s;
    }

    public String getName () {
        return imie;
    }

    @Override
    public boolean equals(Object c) {
        return c.equals(imie);
    }

    public boolean equals(Customer c) {
        return c.nazwisko.equals(nazwisko);
    }


}
