#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameLogic.h"

using namespace sf;
using namespace std;


char gameover(int score)
{
    char playagain;
    cout << "gameover" << endl;
    cout << "Score: " << score << endl;
    cout << "Play again y/n: ";
    cin >> playagain;
    return playagain;
}

void helpmenu()
{
    RenderWindow help(VideoMode(1000, 1000), "Help", Style::Close | Style::Titlebar);
    RectangleShape rules(Vector2f(1000.0f, 1000.0f));

    Texture rulesTexture;
    rulesTexture.loadFromFile("media/rules.png");

    rules.setTexture(&rulesTexture);


    Vector2u textureSize = rulesTexture.getSize();


    rules.setTextureRect(IntRect(0, 0, textureSize.x, textureSize.y));

    while (help.isOpen())
    {


        Event e;
        while (help.pollEvent(e))
        {
            if (e.type == e.Closed)
            {
                help.close();
            }
        }

        //run after here on a mouse click event.

        rules.setPosition(0, 0);
        help.draw(rules);
        help.display();
    }

    return;

}

int getdiff(int y)
{
    if (y > 0 && y <= 66)
        return 1;
    else if (y > 76 && y <= 142)
        return 2;
    else if (y > 152 && y <= 218)
        return 3;
    else if (y > 228 && y <= 294)
        return 0;
    else if (y > 304 && y <= 370)
        return 4;
    //else if (y > 0 && y <= 66)
        //return 6;
}


int difficultymenu()
{
    int menu = 0;

    RenderWindow diff(VideoMode(200, 370), "Minesweeper", Style::Close | Style::Titlebar);
    RectangleShape easy(Vector2f(147.0f, 66.0f));
    RectangleShape medium(Vector2f(147.0f, 66.0f));
    RectangleShape hard(Vector2f(147.0f, 66.0f));
    RectangleShape help(Vector2f(147.0f, 66.0f));
    RectangleShape load(Vector2f(147.0f, 66.0f));


    Texture easyTexture;
    Texture medTexture;
    Texture hardTexture;
    Texture helpTexture;
    Texture loadTexture;

    easyTexture.loadFromFile("media/easy.png");
    medTexture.loadFromFile("media/medium.png");
    hardTexture.loadFromFile("media/hard.png");
    helpTexture.loadFromFile("media/help.png");
    loadTexture.loadFromFile("media/load.png");

    easy.setTexture(&easyTexture);
    medium.setTexture(&medTexture);
    hard.setTexture(&hardTexture);
    help.setTexture(&helpTexture);
    load.setTexture(&loadTexture);

    Vector2u textureSize = easyTexture.getSize();

    while (diff.isOpen())
    {
        Vector2i pos = Mouse::getPosition(diff);
        int x = pos.x;
        int y = pos.y;

        Event e;
        while (diff.pollEvent(e))
        {
            if (e.type == e.Closed)
            {
                diff.close();
            }

            if (e.type == Event::MouseButtonPressed)
            {
                if (e.key.code == Mouse::Left)
                {

                    menu = getdiff(y);
                    cout << menu;
                    return menu;
                }

            }

        }

        //run after here on a mouse click event.
        easy.setPosition(26.5, 0);
        medium.setPosition(26.5, textureSize.y * 1.f + 10.f);
        hard.setPosition(26.5, textureSize.y * 2.f + 20.f);
        help.setPosition(26.5, textureSize.y * 3.f + 30.f);
        load.setPosition(26.5, textureSize.y * 4.f + 40.f);

        diff.clear(Color(255, 255, 255));
        diff.draw(easy);
        diff.draw(medium);
        diff.draw(hard);
        diff.draw(help);
        diff.draw(load);

        diff.display();
    }

    return 0;
}

void helpwindow()
{

}


int buildwindow(GameLogic* g, int height, int width)
{
    bool gameoverbool = false;

    RenderWindow window(VideoMode(30 * width, 30 * height), "Minesweeper", Style::Close | Style::Titlebar);
    RectangleShape cell(Vector2f(30.0f, 30.0f));



    Texture cellTexture;
    cellTexture.loadFromFile("media/tiles.png");

    cell.setTexture(&cellTexture);


    Vector2u textureSize = cellTexture.getSize();
    textureSize.x /= 12;
    textureSize.y /= 1;


    cell.setTextureRect(IntRect(textureSize.x * 10, textureSize.y * 0, textureSize.x, textureSize.y));

    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / 30;
        int y = pos.y / 30;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == e.Closed)
            {
                window.close();
            }

            if (e.type == Event::MouseButtonPressed)
            {
                if (e.key.code == Mouse::Left)
                {

                    cout << x;
                    cout << ",";
                    cout << y;
                    cout << endl;

                    g->board[y][x].activate();

                    
                }
                else if (e.key.code == Mouse::Right)
                {
                    if(g->board[y][x].getFlagged() == false)
                        g->board[y][x].setFlagged();
                    else
                        g->board[y][x].setUnFlagged();
                }
            }


        }

        //run after here on a mouse click event.

        cell.setPosition(0.f, 0.f);
        window.draw(cell);
        for (int i = 0; i < height; i++)
        {
            for (int n = 0; n < width; n++)
            {
                if (g->board[i][n].getFlagged() == true)
                {
                    cell.setTextureRect(IntRect(textureSize.x * 11, textureSize.y * 0, textureSize.x, textureSize.y));

                }

                else if (g->board[i][n].getStatus() == false)
                    cell.setTextureRect(IntRect(textureSize.x * 10, textureSize.y * 0, textureSize.x, textureSize.y));

                else if (g->board[i][n].getIsBomb() == true)
                {
                    cell.setTextureRect(IntRect(textureSize.x * 9, textureSize.y * 0, textureSize.x, textureSize.y));//trigger game over event
                    gameoverbool = true;
                                       
                }

                else if (g->board[i][n].getStatus() == true)
                    cell.setTextureRect(IntRect(textureSize.x * (g->board[i][n].getBombCount()), textureSize.y * 0, textureSize.x, textureSize.y));

                
                
                cell.setPosition(n * 30.f, i * 30.f);
                window.draw(cell);

                

            }

        }

        window.display();
        
        if (gameoverbool == true)
        {
            char playagain;
            int score = g->scoreCount();
            playagain = gameover(score);

            if (playagain == 'y')
                return 1;
            else
                return 0;

        }

    }

    return 0;

}

