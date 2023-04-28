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
    _game = stateGame::start;
    sf::RenderWindow window_grid(sf::VideoMode(_size,_size), "sfml que o que");
    sf::Clock clock;
    window_grid.setFramerateLimit(60);

    font.loadFromFile("Fonty.ttf");
    counterBomb_level();

    while (window_grid.isOpen())
    {
        sf::Event event;
        //float CurrentTime = clock.restart().asSeconds(), fps = 1.0f / CurrentTime;

        while (window_grid.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_grid.close();
        }

        window_grid.clear();

        onClick(window_grid);

        if(_game != stateGame::lose){
            for (int i = 0; i < _numbox; i++) {
                for (int j = 0; j < _numbox; j++) {
                    window_grid.draw(box[i][j].get_box());
                    if (box[i][j].getState() == stateBox::nearBomb) {
                        window_grid.draw(text[i][j]);
                    }
                    if (box[i][j].getState() == stateBox::bomb) {
                        if (_game == stateGame::start) {
                            window_grid.close();
                            std::cout << "perdiste pero de doy chanse \n";
                            run();
                        }
                        else {
                            _game = stateGame::lose;
                        }
                    }
                }
            }
        }

        if (_game == stateGame::start) {
            _game = stateGame::playing;
        }

        window_grid.display();
    }

    delete box;
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
        _size = 800;
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
        box = new Box * [_numbox];
        text = new sf::Text * [_numbox];
        for (int i = 0; i < _numbox; i++) {
            box[i] = new Box[_numbox];
            text[i] = new sf::Text[_numbox];
        }
    }
    catch (std::exception e) {
        std::cout << e.what();
    }
}

void Grid::counterBomb_level() {
    srand(time(0));
    for (int i = 0; i < _numbox; i++) {
        for (int j = 0; j < _numbox; j++) {
            box[i][j].setPos(sf::Vector2f(40 * i, 40 * j));
            text[i][j].setPosition(sf::Vector2f(40 * i + 10, 40 * j + 10));
            box[i][j].setLevel(_level);
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

void Grid::onClick(sf::RenderWindow &window) {
    sf::Vector2i vector = sf::Mouse::getPosition(window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (vector.x >= 0 && vector.x <= window.getSize().x && vector.y >= 0 && vector.y <= window.getSize().y) {
            int x = vector.x / 40, y = vector.y / 40;
            if (box[x][y].getState() == stateBox::cover) {
                box[x][y].discover();
                if (box[x][y].getState() == stateBox::empty) {
                    Flood({x,y});
                }
            }
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if (vector.x >= 0 && vector.x <= window.getSize().x && vector.y >= 0 && vector.y <= window.getSize().y) {
            int x = vector.x / 40, y = vector.y / 40;
            if (box[x][y].getState() == stateBox::cover) {
                box[x][y].setState(stateBox::flag);
            }
            else if (box[x][y].getState() == stateBox::flag) {
                box[x][y].setState(stateBox::cover);
            }
        }
    }
}

void Grid::Flood(sf::Vector2i vector){
    int i = vector.x, j = vector.y;
    for (int x = (i - 1); x <= (i + 1); x++) {
        for (int y = (j - 1); y <= (j + 1); y++) {
            if ((x >= 0 && x < _numbox) && (y >= 0 && y < _numbox)) {
                if (box[x][y].getState() == stateBox::cover) {
                    box[x][y].discover();
                    if (box[x][y].getState() == stateBox::empty) {
                        Flood({ x,y });
                    }
                }
            }
        }
    }
}