#include <iostream>
#include <string>
#include <string.h>
#include "SFML/Graphics.hpp"

#include "Box.h"
#include "Grid.h"

int main(void) {

    //sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    Grid grid(stateLevel::medium);
    
    /*Box box[10][10];
    sf::Font font;
    font.loadFromFile("Fonty.ttf");

    sf::Text tx[10][10];

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            box[i][j].setPos(sf::Vector2f(40 * i, 40 * j));
            tx[i][j].setPosition(sf::Vector2f(40 * i + 10, 40 * j + 10));
            box[i][j].bombRandom();
            if (box[i][j].getBomb()) {
                try {
                    for (int x = (i - 1); x <= (i + 1); x++) {
                        for (int y = (j - 1); y <= (j + 1); y++) {
                            if ((x >= 0 && x < 10) && (y >= 0 && y < 10)) {
                                if (box[x][y].getBomb() == true) {
                                }
                                else {
                                    box[x][y].setNearBomb();
                                }
                            }
                        }
                    }
                }catch(std::exception e){
                    std::cout << e.what() << "\n";
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tx[i][j].setString(std::to_string(box[i][j].getNearBombs()));
            tx[i][j].setCharacterSize(20);
            tx[i][j].setFont(font);
            tx[i][j].setFillColor(sf::Color(255, 255, 255, 100));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            box[i][j].discover();
            window.draw(box[i][j].get_box());
            window.draw(tx[i][j]);
        }

    }

    window.display();

    }
    */
	return 0;
}
