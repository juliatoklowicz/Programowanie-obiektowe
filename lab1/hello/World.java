package World;
import java.util.Scanner;

public class World {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String fellow = "World";
        System.out.printf("Hello %s\n", fellow);
        System.out.printf("Introduce yourself: ");
        fellow = s.nextLine();
        while (!fellow.equals("exit")) { //nalezalo uzyc funkcji equals do porownywania stringow aby kod dzialal poprawnie
            System.out.printf("Hello %s\n", fellow);
            System.out.printf("Introduce yourself: ");
            fellow = s.nextLine();
        }
        s.close();
    }

}