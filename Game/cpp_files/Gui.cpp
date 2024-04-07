#include "../h_files/Gui.h"
#include <unistd.h>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

GUI::GUI() : window(sf::VideoMode(1920, 1080), "TETRISTE")
{
    srand(static_cast<unsigned>(time(0)));
    soundImport();
    insertSound.setBuffer(bufferInsert);
    destroySound.setBuffer(bufferDestroy);
    swapSound.setBuffer(bufferSwap);
    lostSound.setBuffer(bufferLost);

    if (!scoreFont.loadFromFile("ressources/fonts/gang.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return;
    }
    scoreText = sf::Text("Score: 0", scoreFont, 60);
    scoreText.setPosition(1500, 50);
    scoreText.setFillColor(sf::Color::White);

    nextText = sf::Text(" Next Element:  ", scoreFont, 50);
    nextText.setPosition(0, 40);
    nextText.setFillColor(sf::Color::White);

    lostText = sf::Text("You Lost ", scoreFont, 100);
    lostText.setPosition(800, 400);
    lostText.setFillColor(sf::Color::Red);

    doubleText= sf::Text("Double Time Score", scoreFont, 40);
    doubleText.setPosition(1450, 20);
    doubleText.setFillColor(sf::Color::Red);

    // set the first 5 elements that the user could see
    for (int i = 0; i < 3; i++)
    {
        p = _game.nextcard();
        nextElements.push(p);
    }
}

void GUI::startWindowGame()
{
    // Create the font
    sf::Font font3d, arialFont, pacificoFont;
    musicGame.setLoop(true);
    musicGame.play();
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
    button.setFillColor(sf::Color(60, 179, 113)); // Vert
    button.setOutlineThickness(5);                // Épaisseur de la bordure
    button.setOutlineColor(sf::Color::Black);     // Couleur de la bordure
    button.setPosition(820, 490);

    // text Tertiste
    sf::Text tetristeText("TETRISTE", font3d, 150);
    tetristeText.setPosition(630, 280);
    tetristeText.setFillColor(sf::Color::Red);

    // Text "PLAY NOW"
    sf::Text playNowText("PLAY NOW", arialFont, 50);
    // Center the text within the button
    sf::FloatRect textBounds = playNowText.getLocalBounds();
    playNowText.setPosition(button.getPosition().x + (button.getSize().x - textBounds.width) / 2,
                            button.getPosition().y + (button.getSize().y - textBounds.height) / 2 - textBounds.top);
    playNowText.setFillColor(sf::Color::Yellow);

    // Charger les textures pour les images
    sf::Texture texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture;
    if (!texture1.loadFromFile("ressources/images/image1.png") ||
        !texture2.loadFromFile("ressources/images/image2.png") ||
        !texture3.loadFromFile("ressources/images/image3.png") ||
        !texture4.loadFromFile("ressources/images/image4.png") ||
        !texture5.loadFromFile("ressources/images/image5.png") ||
        !texture6.loadFromFile("ressources/images/image6.png") ||
        !texture7.loadFromFile("ressources/images/image7.png") ||
        !texture.loadFromFile("ressources/images/image.png"))
    {
        // Gérer l'erreur si une texture ne peut pas être chargée
        return;
    }

    // Créer les sprites pour les images
    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    sf::Sprite sprite4(texture4);
    sf::Sprite sprite5(texture5);
    sf::Sprite sprite6(texture6);
    sf::Sprite sprite7(texture7);
    sf::Sprite sprite(texture);

    // Déterminer les positions pour chaque coin de l'écran
    float screenWidth = window.getSize().x;
    float screenHeight = window.getSize().y;
    float imageWidth = sprite1.getLocalBounds().width;
    float imageHeight = sprite1.getLocalBounds().height;

    // Coin supérieur gauche
    sprite1.setPosition(0, 0);

    // coin centre haut
    sprite.setPosition(800, 0);
    // Coin gauche milieu

    sprite6.setPosition(0, 400);

    // Coin supérieur droit
    sprite2.setPosition(screenWidth - imageWidth + 770, 0);

    // Coin droit milieu
    sprite5.setPosition(screenWidth - imageWidth + 770, 400);

    // Coin centre bas coupe

    sprite7.setPosition(760, 600);

    // Coin inférieur gauche
    sprite3.setPosition(0, screenHeight - imageHeight + 400);

    // Coin inférieur droit
    sprite4.setPosition(screenWidth - imageWidth + 760, screenHeight - imageHeight + 400);

    // Ajuster la taille de chaque sprite
    float scaleFactor = 0.2f; // Changer cette valeur pour ajuster la taille des images
    float scaleFactor2 = 0.5f;
    sprite1.setScale(scaleFactor, scaleFactor);
    sprite2.setScale(scaleFactor, scaleFactor);
    sprite3.setScale(scaleFactor, scaleFactor);
    sprite4.setScale(scaleFactor, scaleFactor);
    sprite5.setScale(scaleFactor, scaleFactor);
    sprite6.setScale(scaleFactor, scaleFactor);
    sprite7.setScale(scaleFactor2, scaleFactor2);
    sprite.setScale(scaleFactor, scaleFactor);
    // Main loop
    while (window.isOpen())
    {
        window.clear(sf::Color::White);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Gérer les événements de la souris pour le bouton
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                if (button.getGlobalBounds().contains(mousePos))
                {
                    std::cout << "Start Game button clicked!" << std::endl;
                    start();
                }
            }
        }

        // Dessiner le bouton et le texte
        window.draw(tetristeText);
        window.draw(button);
        window.draw(playNowText);

        // Dessiner les sprites des images
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.draw(sprite5);
        window.draw(sprite6);
        window.draw(sprite7);
        window.draw(sprite);
        // Display the window
        window.display();
    }
    window.~RenderTarget();
    window.~RenderWindow();
    window.~Window();
}

void GUI::displayPieceInTheQueue()
{

    queue<piece> file = nextElements;
    int x = 500, y = 50;
    sf::Shape *tmp;
    for (int i = 0; i < 3; i++)
    { // display in the console elements
        x += 150;
        tmp = createShape(file.front().shape);
        colorShape(file.front().color, tmp);
        tmp->setPosition(x, y);
        if (file.front().shape == 'l')
        { // ila kant diamond khassna n3tiwha spacing ktar
            tmp->setPosition(x + 50, y);
        }
        window.draw(*tmp);
        file.pop(); // remove
    }
}

void GUI::start()
{
    int didWeChangeColorOrShape;
    score = 0;
    // set all elements to nullptr so if we try to play again we wont have a prb
    initAllElementsOfTheGame();
    scoreText.setString("Score: 0"); // hna we need to always set the text so if the game is played again it can be updated

    p = _game.nextcard();
    shape = createShape(p.shape);
    colorShape(p.color, shape); // 3tih color
    // startWindowGame();           // home page
    window.clear();
    musicGame.setVolume(10.f);
    while (window.isOpen())
    {
        // draw waiting elements
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // add left
        {
            usleep(200000); // 0.2 second
            // initialiser shape
            _game.inserer('g', p);
            insertSound.play();

            if (_game.supprimer())
            { // check if we have 3 elemnts next to each other
                destroySound.play();
                if (score >= 30 && score <= 100)
                    score += 20;
                else
                {
                    score += 10;
                }

                scoreText.setString("Score: " + to_string(score));
            }

            window.clear();           // kanms7o shape li tal3 lina lfu9 3la lisr
            p = nextElements.front(); // génériw piece jdida
            nextElements.pop();
            nextElements.push(_game.nextcard());

            shape = createShape(p.shape);
            colorShape(p.color, shape); // 3tih color
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {                   // add right
            usleep(200000); // 0.2 second
            // initialiser shape
            _game.inserer('d', p);
            insertSound.play();

            if (_game.supprimer())
            { // check if we have 3 elemnts next to each other
                destroySound.play();
                if (score >= 30 && score <= 100)
                    score += 20;
                else
                {
                    score += 10;
                }
                scoreText.setString("Score: " + to_string(score));
            }
            p = nextElements.front(); // génériw piece jdida
            nextElements.pop();
            nextElements.push(_game.nextcard());

            window.clear(); // kanms7o shape li tal3 lina lfu9 3la lisr

            shape = createShape(p.shape);
            colorShape(p.color, shape); // 3tih color
        }
        didWeChangeColorOrShape = handleShortcuts();
        if (didWeChangeColorOrShape == 1)
        {
            if (_game.supprimer())
            { // checki ila 3ndna 3 7da b3dyathum
                destroySound.play();
                if (score >= 30 && score <= 100)
                    score += 20;
                else
                {
                    score += 10;
                }
                scoreText.setString("Score: " + to_string(score));
            }
            window.clear();
            swapSound.play();
        }
        else if (didWeChangeColorOrShape == 0)
        {
            if (_game.supprimer())
            { // checki ila 3ndna 3 7da b3dyathum
                destroySound.play();
                if (score >= 30 && score <= 100)
                    score += 20;
                else
                {
                    score += 10;
                }
            }
            window.clear();
            swapSound.play();
        }

        while (window.pollEvent(event)) // close event
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
        // drawWaitingElements();
        if (_game.hand.taille == 13)
        {
            lostSound.play();
            break;
        }
        // testing
        if(score>=30 && score <=100)
            window.draw(doubleText);
        window.draw(*shape);
        window.draw(scoreText);
        window.draw(nextText);
        displayPieceInTheQueue();
        window.display();
    } // end loop of the game

    topScores(score);

    musicGame.pause();
    sf::Font arialFont;
    if (!arialFont.loadFromFile("ressources/fonts/Arial.ttf"))
    {
        std::cout << "Failed to load font!" << std::endl;
        return;
    }
    sf::RectangleShape button(sf::Vector2f(320, 100));
    button.setFillColor(sf::Color::Green);
    button.setPosition(840, 550);

    sf::Text playNowText("PLAY AGAIN", arialFont, 50);
    playNowText.setPosition(850, 560);
    playNowText.setFillColor(sf::Color::White);
    // losing part
    while (window.isOpen())
    {
        window.clear();
        window.draw(lostText);
        window.draw(button);
        window.draw(playNowText);
        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (button.getGlobalBounds().contains(mousePos))
                    {
                        window.clear();
                        startWindowGame();
                    }
                }
            }
        }
    }

    window.~RenderTarget();
    window.~RenderWindow();
    window.~Window();
}

sf::Shape *GUI::createShape(char shape)
{

    sf::Shape *newShape;
    switch (shape)
    {
    case 'l':
        newShape = new sf::RectangleShape(sf::Vector2f(80.f, 80.f));
        newShape->rotate(45); // newShape
        newShape->setPosition(405.f, 30.f);
        return newShape;
        break;
    case 'c': // carré
        newShape = new sf::RectangleShape(sf::Vector2f(80.f, 80.f));
        newShape->setPosition(345.f, 30.f);
        return newShape;
        break;
    case 'r': // circle
        newShape = new sf::CircleShape(50.f);
        newShape->setPosition(345.f, 30.f);
        return newShape;
        break;
    case 't': // triangle
        newShape = new sf::CircleShape(60, 3);
        newShape->setPosition(335.f, 30.f);
        return newShape;
        break;
    default:
        return nullptr;
    }
}

void GUI::colorShape(char color, sf::Shape *shape)
{
    switch (color)
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

void GUI::soundImport()
{
    if (!musicGame.openFromFile("ressources/sounds/Tetris.ogg"))
        return;
    if (!bufferInsert.loadFromFile("ressources/sounds/insert.ogg"))
        return;
    if (!bufferDestroy.loadFromFile("ressources/sounds/destroyPieces.wav"))
        return;
    if (!bufferSwap.loadFromFile("ressources/sounds/swapPieces.wav"))
        return;
    if (!bufferLost.loadFromFile("ressources/sounds/losing2.wav"))
        return;
}

int GUI::handleShortcuts()
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

            // colors
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
    return -1;
}

void GUI::drawAllShapesThatAreInHand()
{
    Cellule *_tmp; // for shawing elemnts in the hand of the user
    _tmp = _game.hand.premier;
    sf::Shape *_shape = nullptr;
    float x = 0.0, y = 400;

    for (int i = 0; i < _game.hand.taille; i++)
    {
        // create and draw process
        _shape = createShape(_tmp->valeur.shape);
        colorShape(_tmp->valeur.color, _shape);
        x += 150;
        if (_tmp->valeur.shape == 'l') // hna zid had condition 7it diamond shape can't fit correctly behind other shapes
            _shape->setPosition(x + 40, y);
        else
            _shape->setPosition(x, y);
        window.draw(*_shape);
        window.display();

        _tmp = _tmp->suivant;
    }
}

void GUI::initAllElementsOfTheGame()
{
    _game.hand.init();
    _game.bleu.init();
    _game.vert.init();
    _game.rouge.init();
    _game.jaune.init();
    _game.triangle.init();
    _game.carre.init();
    _game.rond.init();
    _game.losange.init();
}

void GUI::topScores(int score)
{
    ofstream file("maxScores.txt", ios::app);
    file << "," + score;
    file.close();
}
