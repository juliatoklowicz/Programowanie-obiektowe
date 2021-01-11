//package recycling;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.HashMap;

public class Wezel {
    private ArrayList<Wezel> polaczenia = new ArrayList<>();
    private TreeMap<Wezel, Boolean> polaczenia1 = new TreeMap<>();
    private HashMap<Wezel, Boolean> polaczenia2 = new HashMap<>();

    public void dodajPolaczenie(Wezel w)
    {
        polaczenia.add(w);
    }

    public void dodajPolaczenie1(Wezel w)
    {
        polaczenia1.put(w,true);
    }

    public void dodajPolaczenie2(Wezel w)
    {
        polaczenia2.put(w,true);
    }

    @Deprecated
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Finalizowanie obiektu");
        super.finalize();
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for (int i = 0; i <= 1000000; i++) {
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
        }
        s.nextLine();
        s.close();
    }
}

//5. Na konsoli nie wypisuje sie tekst, poniewaz obiekty sa usuwane tylko gdy nie obciążą mocy obliczeniowej

//12. Poniewaz ze zwyklej tablicy ciezko byloby usuwac polaczenia, o wiele prosciej robi sie to korzystajac z 
//ArrayList czyli tablicy dynamicznej