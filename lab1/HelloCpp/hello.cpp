#include <iostream>
#include <string>
int main(){
    std::string fellow = "world";
    std::cout << "Hello " << fellow << std::endl;
    while (fellow != "exit") {
        std::cout << "Introduce yourself: ";
        std::cout.flush();
        std::getline(std::cin, fellow);
        if(fellow != "exit")
            std::cout << "Hello" << fellow << std::endl;
        
    }
    return 0;
}

//do funkcji while trzeba bylo dodac if, ktory sprawdza czy uzytkownik podal "exit" aby program dzialal poprawnie