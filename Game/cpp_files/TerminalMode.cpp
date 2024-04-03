#include <iostream>
#include <ctime>
#include "../h_files/TerminalMode.h"

void TerminalMode::modeTerminal() {
    bool gamestat = true;
    srand(static_cast<unsigned>(time(0)));

    game g;
    int choix1;
    char choix2;

    while (gamestat) {
        piece p = g.nextcard();
        std::cout << "Next piece:" << p.color << " " << p.shape << "                   "
                  << "Score :" << g.score << std::endl;
        std::cout << "My Hand:" << std::endl;
        g.showhand();
        std::cout << "rouge:";
        g.rouge.display();
        std::cout << "blue:";
        g.bleu.display();
        std::cout << "jaune:";
        g.jaune.display();
        std::cout << "vert:";
        g.vert.display();
        std::cout << "lausange:";
        g.losange.display();
        std::cout << "carre:";
        g.carre.display();
        std::cout << "triangle:";
        g.triangle.display();
        std::cout << "rond:";
        g.rond.display();
        std::cout << "1 decaler couleur" << std::endl;
        std::cout << "2 decaler shapes" << std::endl;
        std::cout << "3 inserer en tete" << std::endl;
        std::cout << "4 inserer en queue" << std::endl;
        std::cout << "=>";
        choix1 = std::cin.get();

        switch (choix1 - '0') {
            case 1:
                std::cout << "r selon rouges" << std::endl;
                std::cout << "v selon verts" << std::endl;
                std::cout << "j selon jaune" << std::endl;
                std::cout << "b selon bleu" << std::endl;
                std::cout << "=>";
                choix2 = std::cin.get();
                g.decalercouleur(choix2);
                break;
            case 2:
                std::cout << "l selon losanges" << std::endl;
                std::cout << "c selon carre" << std::endl;
                std::cout << "r selon rond" << std::endl;
                std::cout << "t selon triangle" << std::endl;
                std::cout << "=>";
                choix2 = std::cin.get();
                g.decalershape(choix2);
                break;
            case 3:
                g.inserer('g', p);
                break;
            case 4:
                g.inserer('d', p);
                break;
        }
        g.supprimer();
        gamestat = g.gameover();
    }
}
