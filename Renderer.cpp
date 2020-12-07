#include "Renderer.h"
#include <filesystem>

void ObserverSVGRenderer::render(const Game& g) const {
   
    Map map = g.getMap();
    int maxCols = map.getMaxCols();
    Hero* hero = g.getHero();
    std::pair<int, int> heropos = g.getHeroPos();
    std::string heroTexture;

    if (!std::filesystem::exists(hero->getTexture()))
    {
        heroTexture = "svg/not_found.svg";
    }
    else
    {
        heroTexture = hero->getTexture();
    }

    std::vector<std::pair<Monster, std::pair<int, int>>> monsters = g.getMonsters();
    std::ofstream svg(output);
    std::string wallTexture;

    if (!std::filesystem::exists("svg/wall.svg"))
    {
        wallTexture = "svg/not_found.svg";
    }
    else
    {
        wallTexture = "svg/wall.svg";
    }

    std::string freeTexture;

    if (!std::filesystem::exists("svg/free.svg"))
    {
        freeTexture = "not_found.svg";
    }
    else
    {
        freeTexture = "svg/free.svg";
    }

    int svgXCoords = 0;
    int svgYCoords = 0;
    int svgWidth = map.getMaxCols() * 10;
    int svgHeight = map.getRows() * 10;

    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << svgWidth << "\" height=\"" << svgHeight << "\">\n";
    for (int x = 0; x < map.getRows(); x++)
    {
        svgXCoords = 0;
        for (int y = 0; y < map.getColumns(x); y++)
        {
            if (map.get(x, y) == 1)
            {
                svg << "<image href=\"" << wallTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
            }
            else if (heropos.first == x && heropos.second == y)
            {
                svg << "<image href=\"" << heroTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
            }
            else if (g.monsterCount(x, y) == 1)
            {
                std::string monsterTexture;
                for (auto p : monsters)
                {
                    if (p.first.isAlive() && (x == p.second.first && y == p.second.second))
                    {
                        if (!std::filesystem::exists(p.first.getTexture()))
                        {
                            monsterTexture = "not_found.svg";
                        }
                        else
                        {
                            monsterTexture = p.first.getTexture();
                        }
                        svg << "<image href=\"" << monsterTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
                    }
                }
            }
            else
            {
                svg << "<image href=\"" << freeTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
            }
            svgXCoords += 10;
        }
        if (map.getColumns(x) < maxCols)
        {
            for (int y = 0; y < (maxCols - map.getColumns(x)); y++)
            {
                svg << "<image href=\"" << wallTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
                svgXCoords += 10;
            }
        }
        svgYCoords += 10;
    }
    svg << "</svg>";
    svg.close();
}

void CharacterSVGRenderer::render(const Game& g) const {

    Map map = g.getMap();
    int maxCols = map.getMaxCols();
    Hero* hero = g.getHero();
    std::pair<int, int> heropos = g.getHeroPos();
    std::string heroTexture;

    if (!std::filesystem::exists(hero->getTexture()))
    {
        heroTexture = "svg/not_found.svg";
    }
    else
    {
        heroTexture = hero->getTexture();
    }

    std::vector<std::pair<Monster, std::pair<int, int>>> monsters = g.getMonsters();
    std::ofstream svg(output);   
    std::string wallTexture;

    if (!std::filesystem::exists("svg/wall.svg"))
    {
       wallTexture = "svg/not_found.svg";
    }
    else
    {
        wallTexture = "svg/wall.svg";
    }
    std::string freeTexture;
    if (!std::filesystem::exists("svg/free.svg"))
    {
        freeTexture = "svg/not_found.svg";
    }
    else
    {
        freeTexture = "svg/free.svg";
    }

    int firsti = 0;
    int secondi = g.getMap().getRows();
    int tmc = g.getMap().getMaxCols();
    int tm = 0;
    if ((g.getHeroPos().first - g.getHero()->getRadius()) > 0)
    {
        firsti = g.getHeroPos().first - g.getHero()->getRadius();
    }
    if ((g.getHeroPos().first + g.getHero()->getRadius() + 1) < g.getMap().getRows())
    {
        secondi = g.getHeroPos().first + g.getHero()->getRadius() + 1;
    } 
    if ((g.getHeroPos().second - g.getHero()->getRadius()) > 0)
    {
        tm = ((g.getHeroPos().second) - (g.getHero()->getRadius()));
    }
    if ((g.getHeroPos().second + g.getHero()->getRadius() + 1) < g.getMap().getMaxCols())
    {
        tmc = ((g.getHeroPos().second) + (g.getHero()->getRadius()) + 1);

    }

    int svgXCoords = 0;
    int svgYCoords = 0;
    int svgWidth = map.getMaxCols() * 10;
    int svgHeight = map.getRows() * 10;

    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" << svgWidth << "\" height=\"" << svgHeight << "\">\n";
    for (int i = firsti; i < secondi; i++)
    {
        svgXCoords = 0;
        int firstj = 0;
        int secondj = g.getMap().getColumns(i);
        if ((g.getHeroPos().second - g.getHero()->getRadius()) > 0)
        {
            firstj = ((g.getHeroPos().second) - (g.getHero()->getRadius()));
        }
        if ((g.getHeroPos().second + g.getHero()->getRadius() + 1) < g.getMap().getColumns(i))
        {
            secondj = ((g.getHeroPos().second) + (g.getHero()->getRadius()) + 1);
        }
        for (int j = firstj; j < secondj; j++)
        {
            if (map.get(i, j) == 1)
            {
                svg << "<image href=\"" << wallTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
            }
            else if (heropos.first == i && heropos.second == j)
            {
                svg << "<image href=\"" << heroTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
            }
            else if (g.monsterCount(i,j)==1)
            {
                std::string monsterTexture;
                for (auto p : monsters)
                {
                    if (p.first.isAlive() && (i == p.second.first && j == p.second.second))
                    {
                        if (!std::filesystem::exists(p.first.getTexture()))
                        {
                            monsterTexture = "not_found.svg";
                        }
                        else
                        {
                            monsterTexture = p.first.getTexture();
                        }
                        svg << "<image href=\"" << monsterTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
                    }
                }
            }
            else
            {
                svg << "<image href=\"" << freeTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
            }
          svgXCoords += 10;
        }
         for (int j = g.getMap().getColumns(i); j <tmc; j++) 
         {
             svg << "<image href=\"" << wallTexture << "\" width=\"10\" height=\"10\" x=\"" << svgXCoords << "\" y=\"" << svgYCoords << "\"/>\n";
             svgXCoords += 10;
         }
        svgYCoords += 10;
    }
    svg << "</svg>";
    svg.close();

}

void HeroTextRenderer::render(const Game& game) const {

    int firsti = 0;
    int secondi = game.getMap().getRows();
    int tmc = game.getMap().getMaxCols();
    int tm = 0;

    if ((game.getHeroPos().first - game.getHero()->getRadius()) > 0)
    {
        firsti = game.getHeroPos().first - game.getHero()->getRadius();
    }
    if ((game.getHeroPos().first + game.getHero()->getRadius() + 1) < game.getMap().getRows())
    {
        secondi = game.getHeroPos().first + game.getHero()->getRadius() + 1;
    }

    outputStream << "╔";
    if ((game.getHeroPos().second - game.getHero()->getRadius()) > 0)
    {
        tm = ((game.getHeroPos().second) - (game.getHero()->getRadius()));
    }
    if ((game.getHeroPos().second + game.getHero()->getRadius() + 1) < game.getMap().getMaxCols())
    {
        tmc = ((game.getHeroPos().second) + (game.getHero()->getRadius()) + 1);

    }
    for (int i = tm; i < tmc; i++)
    {
        outputStream << "══";
    }
    outputStream << "╗\n";
    for (int i = firsti; i < secondi; i++)
    {
        int firstj = 0;
        int secondj = game.getMap().getColumns(i);
        if ((game.getHeroPos().second - game.getHero()->getRadius()) > 0)
        {
            firstj = ((game.getHeroPos().second) - (game.getHero()->getRadius()));
        }
        if ((game.getHeroPos().second + game.getHero()->getRadius() + 1) < game.getMap().getColumns(i))
        {
            secondj = ((game.getHeroPos().second) + (game.getHero()->getRadius()) + 1);
        }
        outputStream << "║";
        for (int j = firstj; j < secondj; j++)
        {
            if (game.getMap().get(i, j) == 1)
            {
                outputStream << "██";

            }
            else if (game.getHeroPos().first == i && game.getHeroPos().second == j)
            {
                outputStream << "┣┫";


            }
            else if (game.monsterCount(i, j) == 1)
            {
                outputStream << "M░";


            }
            else if (game.monsterCount(i, j) > 1)
            {
                outputStream << "MM";
            }
            else
            {
                outputStream << "░░";


            }
        }

        for (int k = game.getMap().getColumns(i); k < tmc; k++)
        {
            outputStream << "██";
        }
        outputStream << "║\n";
    }
    outputStream << "╚";
    for (int i = tm; i < tmc; i++)
    {
        outputStream << "══";
    }
    outputStream << "╝\n\n";
    outputStream.flush();
}

void ObserverTextRenderer::render(const Game& game) const {
 
    outputStream << "╔";
    for (int i = 0; i < game.getMap().getMaxCols(); i++)
    {
        outputStream << "══";
    }
    outputStream << "╗\n";
    for (int i = 0; i < game.getMap().getRows(); i++)
    {
        outputStream << "║";
        for (int j = 0; j < game.getMap().getColumns(i); j++)
        {
            if (game.getMap().get(i, j) == 1)
            {
                outputStream << "██";
            }
            else if (game.getHeroPos().first == i && game.getHeroPos().second == j)
            {
                outputStream << "┣┫";
            }
            else if (game.monsterCount(i, j) == 1)
            {
                outputStream << "M░";
            }
            else if (game.monsterCount(i, j) > 1)
            {
                outputStream << "MM";
            }
            else
            {
                outputStream << "░░";
            }
        }
        for (int k = game.getMap().getColumns(i); k < game.getMap().getMaxCols(); k++)
        {
            outputStream << "██";
        }
        outputStream << "║\n";;
    }
    outputStream << "╚";
    for (int i = 0; i < game.getMap().getMaxCols(); i++)
    {
        outputStream << "══";
    }
    outputStream << "╝\n\n";
    outputStream.flush();
}