#include "Grid.h"

Grid::Grid() {
    this->_level = stateLevel::easy;
    run();
}

Grid::Grid(stateLevel level) {
    this->_level = level;
    run();
}

void Grid::run() {
    level();
    gridElement();
    std::cout << _size;
    std::cout << _numbox;
    sf::RenderWindow window_grid(sf::VideoMode(_size,_size), "sfml que o que");
    font.loadFromFile("Fonty.ttf");

    while (window_grid.isOpen())
    {
        sf::Event event;
        while (window_grid.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_grid.close();
        }

        window_grid.clear();

        for (int i = 0; i < _numbox; i++) {
            for (int j = 0; j < _numbox; j++) { 
                box[i][j].discover();
                window_grid.draw(box[i][j].get_box());
                window_grid.draw(text[i][j]);
            }

        }

        window_grid.display();

    }
}

void Grid::level() {
    switch (_level)
    {
    case stateLevel::easy:
        _size = 400;
        break;
    case stateLevel::medium:
        _size = 600;
        break;
    case stateLevel::hard:
        _size = 1000;
        break;
    default:
        _size = 400;
        break;
    }

    gridElement();
}

void Grid::gridElement() {

    try{
        _numbox = _size / 40; 
    }
    catch (std::exception e) {
        std::cout << e.what();
    }

    box = new Box * [_numbox];
    text = new sf::Text * [_numbox];
    for (int i = 0; i < _numbox; i++) {
        box[i] = new Box[_numbox];
        text[i] = new sf::Text[_numbox];
    }
}

void Grid::CounterBomb_level() {
    srand(time(0));
    for (int i = 0; i < _numbox; i++) {
        for (int j = 0; j < _numbox; j++) {
            box[i][j].setPos(sf::Vector2f(40 * i, 40 * j));
            text[i][j].setPosition(sf::Vector2f(40 * i + 10, 40 * j + 10));
            box[i][j].bombRandom();
            if (box[i][j].getBomb()) {
                for (int x = (i - 1); x <= (i + 1); x++) {
                    for (int y = (j - 1); y <= (j + 1); y++) {
                        if ((x >= 0 && x < _numbox) && (y >= 0 && y < _numbox)) {
                            if (!box[x][y].getBomb()) {
                                box[x][y].setNearBomb();
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < _numbox; i++) {
        for (int j = 0; j < _numbox; j++) {
            text[i][j].setString(std::to_string(box[i][j].getNearBombs()));
            text[i][j].setCharacterSize(20);
            text[i][j].setFont(font);
            text[i][j].setFillColor(sf::Color(255, 255, 255, 100));
        }
    }
}