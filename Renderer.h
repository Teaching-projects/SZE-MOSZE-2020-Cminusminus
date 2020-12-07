#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "Game.h"
#include <ostream>
#include <fstream>
#include <iostream>

class Game;

class Renderer {
public:
    Renderer() {}
    virtual void render(const Game&) const = 0;
};

class TextRenderer : public Renderer {

public:
    TextRenderer() : outputStream(std::cout) { }
    TextRenderer(std::ostream& stream) : outputStream(stream) { }
    TextRenderer(std::ostream* stream) : outputStream(*stream) { }
    virtual void render(const Game&) const = 0;

    void setOutputStream(std::ostream& stream) const
    {
        outputStream.copyfmt(stream);
    }

protected:
    std::ostream& outputStream;
};

class HeroTextRenderer : public TextRenderer {

public:
    HeroTextRenderer() : TextRenderer() {};
    HeroTextRenderer(std::ostream& stream) : TextRenderer(stream) {}
    HeroTextRenderer(std::ostream* stream) : TextRenderer(stream) { }

    void render(const Game&) const override;
};

class ObserverTextRenderer : public TextRenderer {
public:
    ObserverTextRenderer() : TextRenderer() {}
    ObserverTextRenderer(std::ostream& stream) : TextRenderer(stream) {}
    ObserverTextRenderer(std::ostream* stream) : TextRenderer(stream) { }

    void render(const Game&) const override;
};

class SVGRenderer : public Renderer {

public:

    SVGRenderer(const std::string& output) : output(output) {}

    virtual void render(const Game&) const = 0;

protected:
    const std::string output = "";
};

class CharacterSVGRenderer : public SVGRenderer {
public:

    CharacterSVGRenderer(const std::string& output) : SVGRenderer(output) {}

    virtual void render(const Game&) const;
};

class ObserverSVGRenderer : public SVGRenderer {
public:

    ObserverSVGRenderer(const std::string& output) : SVGRenderer(output) {}

    virtual void render(const Game&) const;
};

#endif 
