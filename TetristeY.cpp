#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include <unistd.h> // For sleep function

#include <SFML/Graphics.hpp>

using namespace std;

typedef struct
{
    string color;
    string shape;
} piece;

class Node
{
public:
    piece *data;
    Node *prev;
    Node *next;

    Node(piece *data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class CircularDoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    int taille;

public:
    CircularDoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        taille = 0;
    }

    void addqueue(piece *data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        tail->next = head;
        head->prev = tail;
        taille++;
    }

    void addhead(piece *data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->next->prev = newNode;
            head = newNode;
        }

        tail->next = head;
        head->prev = tail;
        taille++;
    }

    void display()
    {
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "Liste vide" << endl;
            return;
        }

        while (temp != tail)
        {
            cout << temp->data->color << " " << temp->data->shape << "     ";
            temp = temp->next;
        }

        cout << temp->data->color << " " << temp->data->shape << endl;
    }
    void supprimer(piece *p)
    {
        if (head == tail && head->data == p)
        {
            delete head;
            head = tail = nullptr;
            taille--;
            return;
        }
        if (head->data == p)
        {
            Node *e = head;
            head->next->prev = tail;
            head = head->next;
            tail->next = head;
            delete (e);
            taille--;
            return;
        }
        Node *c = head->next;
        while (c != head)
        {
            if (c->data != p)
                c = c->next;
            else
            {
                c->prev->next = c->next;
                c->next->prev = c->prev;
                if (c == tail)
                    tail = c->prev;
                delete c;
                taille--;
                return;
            }
        }
    }

    void shiftleft()
    {
        if (taille < 2)
        {
            return;
        }

        Node *courant = head;
        piece temp = *head->data;
        while (courant->next != head)
        {
            *courant->data = *courant->next->data;
            courant = courant->next;
        }

        *tail->data = temp;
    }
};

class Cellule
{
public:
    piece *valeur;
    Cellule *suivant;

    Cellule(piece *valeur)
    {
        this->valeur = valeur;
        suivant = nullptr;
    }
};

class ListeCirculaire
{
public:
    Cellule *premier;
    Cellule *dernier;
    int taille;

public:
    ListeCirculaire()
    {
        premier = nullptr;
        dernier = nullptr;
        taille = 0;
    }

    bool estVide()
    {
        return premier == nullptr;
    }

    void ajouterEnTete(piece *valeur)
    {
        Cellule *nouvelleCellule = new Cellule(valeur);

        if (estVide())
        {
            premier = dernier = nouvelleCellule;
        }
        else
        {
            nouvelleCellule->suivant = premier;
            premier = nouvelleCellule;
            dernier->suivant = premier;
        }
        taille++;
    }

    void ajouterEnFin(piece *valeur)
    {
        Cellule *nouvelleCellule = new Cellule(valeur);

        if (estVide())
        {
            premier = dernier = nouvelleCellule;
        }
        else
        {
            dernier->suivant = nouvelleCellule;
            dernier = nouvelleCellule;
            dernier->suivant = premier;
        }
        taille++;
    }

    void afficher()
    {
        Cellule *temp = premier;
        for (int i = 0; i < taille; i++)
        {
            cout << temp->valeur->color << " " << temp->valeur->shape << "   ";
            temp = temp->suivant;
        }

        cout << endl;
    }
};

class game
{
public:
    CircularDoublyLinkedList bleu, jaune, rouge, vert, carre, losange, rond, triangle;
    ListeCirculaire hand;
    int score;
    game()
    {
        score = 0;
    }
    piece nextcard()
    {
        piece p;
        string couleurs[] = {"bleu", "rouge", "vert", "jaune"};
        p.color = couleurs[std::rand() % 4];
        string shapes[] = {"losange", "rond", "carre", "triangle"};
        p.shape = shapes[std::rand() % 4];
        return p;
    }

    void inserer(char c, piece *p)
    {

        switch (p->color[0])
        {
        case 'b':
            if (c == 'g')
                bleu.addhead(p);
            else
                bleu.addqueue(p);
            break;
        case 'j':
            if (c == 'g')
                jaune.addhead(p);
            else
                jaune.addqueue(p);
            break;
        case 'r':
            if (c == 'g')
                rouge.addhead(p);
            else
                rouge.addqueue(p);
            break;
        case 'v':
            if (c == 'g')
                vert.addhead(p);
            else
                vert.addqueue(p);
            break;
        }

        switch (p->shape[0])
        {
        case 'l':
            if (c == 'g')
                losange.addhead(p);
            else
                losange.addqueue(p);
            break;
        case 'c':
            if (c == 'g')
                carre.addhead(p);
            else
                carre.addqueue(p);
            break;
        case 'r':
            if (c == 'g')
                rond.addhead(p);
            else
                rond.addqueue(p);
            break;
        case 't':
            if (c == 'g')
                triangle.addhead(p);
            else
                triangle.addqueue(p);
            break;
        }

        if (c == 'd')
            hand.ajouterEnFin(p);
        else
            hand.ajouterEnTete(p);
    }

    void showhand()
    {
        hand.afficher();
    }

    void decalercouleur(char c)
    {
        switch (c)
        {
        case 'b':
            bleu.shiftleft();
            break;
        case 'j':
            jaune.shiftleft();
            break;
        case 'r':
            rouge.shiftleft();
            break;
        case 'v':
            vert.shiftleft();
            break;
        }
    }

    void decalershape(char s)
    {
        switch (s)
        {
        case 'l':
            losange.shiftleft();
            break;
        case 'c':
            carre.shiftleft();
            break;
        case 'r':
            rond.shiftleft();
            break;
        case 't':
            triangle.shiftleft();
            break;
        }
    }
    void supp(piece *p)
    {

        switch (p->color[0])
        {
        case 'b':
            bleu.supprimer(p);
            break;
        case 'j':

            jaune.supprimer(p);
            break;
        case 'r':

            rouge.supprimer(p);
            break;
        case 'v':

            vert.supprimer(p);
            break;
        }

        switch (p->shape[0])
        {
        case 'l':

            losange.supprimer(p);
            break;
        case 'c':

            carre.supprimer(p);
            break;
        case 'r':

            rond.supprimer(p);
            break;
        case 't':

            triangle.supprimer(p);
            break;
        }
    }
    int supprimer()
    {
        if (hand.taille >= 3)
        {
            Cellule *t1, *t2, *t3, *pred;
            t1 = hand.premier;
            t2 = t1->suivant;
            t3 = t2->suivant;
            pred = hand.dernier;
            while (t3 != hand.premier)
            {
                if (((t1->valeur->color == t2->valeur->color) && (t1->valeur->color == t3->valeur->color)) || ((t1->valeur->shape == t2->valeur->shape) && (t1->valeur->shape == t3->valeur->shape)))
                {
                    pred->suivant = t3->suivant;
                    if (t1 == hand.premier)
                        hand.premier = t3->suivant;
                    if (t3 == hand.dernier)
                        hand.dernier = pred;
                    supp(t1->valeur);
                    supp(t2->valeur);
                    supp(t3->valeur);
                    delete t1;
                    delete t2;
                    delete t3;
                    hand.taille -= 3;
                    score += 5;
                    return 1;
                }
                pred = t1;
                t1 = t1->suivant;
                t2 = t1->suivant;
                t3 = t2->suivant;
            }
            return 0;
        }
        return 0;
    }
    bool gameover()
    {
        return !(hand.taille == 15);
    }
};
void modeTerminal()
{
    bool gamestat = true;
    srand(static_cast<unsigned>(time(0)));

    game g;
    int choix1;
    char choix2;
    piece *p;
    while (gamestat)
    {
        // system("cls");
        p = new piece(g.nextcard());
        cout << "Next piece: " << p->color << " " << p->shape << "                   "
             << "Score  : " << g.score << endl;
        cout << "\n";
        cout << "-----------My Hand (liste principale)------------" << endl;
        g.showhand();
        cout << "------------Liste Color---------------\n";
        cout << "\033[31mrouge: \033[0m";
        g.rouge.display();
        cout << "\033[34mbleu: \033[0m";
        g.bleu.display();
        cout << "\033[33mjaune: \033[0m";
        g.jaune.display();
        cout << "\033[32mvert: \033[0m";
        g.vert.display();
        cout << "------------Liste Shape---------------\n";
        cout << "losange:";
        g.losange.display();
        cout << "carre:";
        g.carre.display();
        cout << "triangle:";
        g.triangle.display();
        cout << "rond:";
        g.rond.display();
        cout << "------------Commandes Game---------------\n";
        cout << "1 decaler couleur" << endl;
        cout << "2 decaler shapes" << endl;
        cout << "3 inserer en tete" << endl;
        cout << "4 inserer en queue" << endl;
        cout << "=>";
        choix1 = std::cin.get();
        cout << endl;

        switch (choix1 - '0')
        {
        case 1:
            cout << "r selon rouges" << endl;
            cout << "v selon verts" << endl;
            cout << "j selon jaune" << endl;
            cout << "b selon bleu" << endl;
            cout << "=>";
            cin >> choix2;
            g.decalercouleur(choix2);
            break;
        case 2:
            cout << "l selon losanges" << endl;
            cout << "c selon carre" << endl;
            cout << "r selon rond" << endl;
            cout << "t selon triangle" << endl;
            cout << "=>";
            cin >> choix2;
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
    delete p;
}


class GUI
{
private:
    sf::RenderWindow window;
    sf::Music musicGame;
    sf::Sound insertSound, destroySound;
    sf::SoundBuffer bufferInsert, bufferDestroy; // buffer declarito hna o machi f'sound import 7it it wont work tma it will be destroyed
    sf::Event event;
    sf::Shape *shape;
    
    game _game;

    piece *p;

    sf::Shape *createShape(string shape)
    {
        sf::Shape *newShape;
        switch (shape[0])
        {
        case 'l':
            newShape = new sf::RectangleShape(sf::Vector2f(80.f, 80.f));
            newShape->rotate(45); // newShape
            newShape->setPosition(70.f, 30.f);
            return newShape;
            break;
        case 'c': // carré
            newShape = new sf::RectangleShape(sf::Vector2f(80.f, 80.f));
            newShape->setPosition(70.f, 30.f);
            return newShape;
            break;
        case 'r': // circle
            newShape = new sf::CircleShape(50.f);
            newShape->setPosition(70.f, 30.f);
            return newShape;
            break;
        case 't': // triangle
            newShape = new sf::CircleShape(60, 3);
            newShape->setPosition(70.f, 30.f);
            return newShape;
            break;
        default:
            return nullptr;
        }
    }
    void colorShape(string color, sf::Shape *shape)
    {
        switch (color[0])
        {
        case 'r':
            shape->setFillColor(sf::Color::Red);
            break;
        case 'b':
            shape->setFillColor(sf::Color::Blue);
            break;
        case 'v':
            shape->setFillColor(sf::Color::Green);
            break;
        case 'j':
            shape->setFillColor(sf::Color::Yellow);
            break;
        }
    }

    void soundImport()
    {
        if (!musicGame.openFromFile("ressources/sounds/Tetris.ogg"))
            return;
        if (!bufferInsert.loadFromFile("ressources/sounds/insert.ogg"))
            return;
        if (!bufferDestroy.loadFromFile("ressources/sounds/destroyPieces.wav"))
            return;
    }

    int handleShortcuts() //had function katreturni 0 ila decalina b'shape o katrad 1 ila blcolor 
    {
        sf::Event event;
        if (window.waitEvent(event))
        {
            // Cchecki wach jana chi event
            switch (event.type)
            {
            // Checki achmn event
            case sf::Event::KeyPressed:
                // checki ina button clicka 3lih user
                switch (event.key.code)
                {
                case sf::Keyboard::D: // diamond shape
                    _game.decalershape('l');
                    return 0;
                    
                case sf::Keyboard::S: // square
                    usleep(200000);   // 0.2 second
                    _game.decalershape('c');
                    return 0;
                case sf::Keyboard::T: // triangle
                    usleep(200000);   // 0.2 second
                    _game.decalershape('t');
                    return 0;
                case sf::Keyboard::C: // circle
                    usleep(200000);   // 0.2 second
                    _game.decalershape('r');
                    return 0;

                //colors
                case sf::Keyboard::B: // blue
                    usleep(200000);   // 0.2 second
                    _game.decalercouleur('b');
                    return 1;
                    
                case sf::Keyboard::R: // red
                    usleep(200000);   // 0.2 second
                    _game.decalercouleur('r');
                    return 1;
                    
                case sf::Keyboard::Y: // yellow
                    usleep(200000);   // 0.2 second
                    _game.decalercouleur('j');
                    return 1;
                    
                case sf::Keyboard::G: // green
                    usleep(200000);   // 0.2 second
                    _game.decalercouleur('v');
                    return 1;
                    
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
        return 0;
    }

    void drawAllShapesThatAreInHand()
    {
        Cellule *_tmp; // for shawing elemnts in the hand of the user
        _tmp = _game.hand.premier;
        sf::Shape *_shape;
        float x = 0.0, y = 400;

        for (int i = 0; i < _game.hand.taille; i++)
        {
            // create and draw process
            _shape = createShape(_tmp->valeur->shape);
            colorShape(_tmp->valeur->color, _shape);
            x += 150;
            if (_tmp->valeur->shape[0] == 'l') // hna zid had condition 7it diamond shape can't fit correctly behind other shapes
                _shape->setPosition(x + 40, y);
            else
                _shape->setPosition(x, y);
            window.draw(*_shape);
            window.display();

            _tmp = _tmp->suivant;
        }
    }

    void startWindowGame()
    {
        // Create the font
        sf::Font font3d, arialFont;
        if (!font3d.loadFromFile("ressources/fonts/gunplay.otf"))
        {
            std::cout << "Failed to load font!" << std::endl;
            return;
        }
        if (!arialFont.loadFromFile("ressources/fonts/Arial.ttf"))
        {
            std::cout << "Failed to load font!" << std::endl;
            return;
        }

        // Create the button
        sf::RectangleShape button(sf::Vector2f(280, 100));
        button.setFillColor(sf::Color::Green);
        button.setPosition(840, 490);

        // text Tertiste
        sf::Text tetristeText("TETRIST", font3d, 150);
        tetristeText.setPosition(660, 220);
        tetristeText.setFillColor(sf::Color::Red);

        // text playNow
        sf::Text playNowText("PLAY NOW", arialFont, 50);
        playNowText.setPosition(850, 500);
        playNowText.setFillColor(sf::Color::White);

        // Main loop
        while (window.isOpen())
        {
            // Event handling
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                // Check if the button is clicked
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                        if (button.getGlobalBounds().contains(mousePos))
                        {
                            std::cout << "Start Game button clicked!" << std::endl;
                            return;
                        }
                    }
                }
            }

            // Draw the button
            window.draw(tetristeText);
            window.draw(button);
            window.draw(playNowText);

            // Display the window
            window.display();
        }
        window.~RenderTarget();
        window.~RenderWindow();
        window.~Window();
    }

public:
    GUI() : window(sf::VideoMode(1920, 1080), "TETRIS")
    {
        srand(static_cast<unsigned>(time(0)));
        soundImport();
        insertSound.setBuffer(bufferInsert);
        destroySound.setBuffer(bufferDestroy);
    }

    void start()
    {
        musicGame.setLoop(true);
        musicGame.play();
        p = new piece(_game.nextcard());
        shape = createShape(p->shape);
        colorShape(p->color, shape); // 3tih color
        startWindowGame();           // home page
        window.clear();
        musicGame.setVolume(10.f);
        while (window.isOpen())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // add left
            {
                usleep(200000); // 0.2 second

                // initialiser shape
                _game.inserer('g', p);
                insertSound.play();

                if (_game.supprimer()) // check if we have 3 elemnts next to each other
                    destroySound.play();

                window.clear();                  // kanms7o shape li tal3 lina lfu9 3la lisr
                p = new piece(_game.nextcard()); // génériw piece jdida
                shape = createShape(p->shape);
                colorShape(p->color, shape); // 3tih color
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {                   // add right
                usleep(200000); // 0.2 second
                // initialiser shape
                _game.inserer('d', p);
                insertSound.play();

                if (_game.supprimer()) // check if we have 3 elemnts next to each other
                    destroySound.play();

                window.clear(); // kanms7o shape li tal3 lina lfu9 3la lisr
                p = new piece(_game.nextcard());
                shape = createShape(p->shape);
                colorShape(p->color, shape); // 3tih color
            }
            if(handleShortcuts()==1){
                window.clear();
            }
            

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    musicGame.stop();
                    window.~RenderTarget();
                    window.~RenderWindow();
                    window.~Window();
                }
            }
            drawAllShapesThatAreInHand();

            window.draw(*shape);
            window.display();
        }
        delete p;
        window.~RenderTarget();
        window.~RenderWindow();
        window.~Window();
    }
};

int main()
{
    //modeTerminal();
    GUI gui;
    gui.start();

    return 0;
}
