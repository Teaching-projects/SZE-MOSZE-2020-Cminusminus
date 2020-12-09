#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "Game.h"
#include <ostream>
#include <fstream>
#include <iostream>

class Game; //Forward declaration of the Game class.

class Renderer {
	/**
	*\brief An abstract class for rendering.
	*/
public:
    Renderer() {}
	///\brief A function to render.
	///\param Game& The game we want to render from.
    virtual void render(const Game&) const = 0;
};

class TextRenderer : public Renderer {

public:
    TextRenderer() : outputStream(std::cout) { }
	/**
	*\brief An abstract class for rendering text.
	*\param std::ostream& The stream we want to render to.
	*/
    TextRenderer(std::ostream& stream) : outputStream(stream) { }
	/**
	*\brief An abstract class for rendering text.
	*\param std::ostream* The stream we want to render to. 
	*/
    TextRenderer(std::ostream* stream) : outputStream(*stream) { }
	///\brief A function to render.
	///\param Game& The game we want to render from.
    virtual void render(const Game&) const override = 0;
	///\brief A function to set the output stream.
	///\param std::ostream& The output stream we want to set.
    void setOutputStream(std::ostream& stream) const
    {
        outputStream.copyfmt(stream);
    }

protected:
    std::ostream& outputStream; ///\brief The outputStream render to.
};

class HeroTextRenderer : public TextRenderer {

public:
    HeroTextRenderer() : TextRenderer() {};
	/**
	*\brief A class for rendering text.
	*\param std::ostream& The stream we want to render to.
	*/
    explicit HeroTextRenderer(std::ostream& stream) : TextRenderer(stream) {}
	/**
	*\brief A class for rendering text.
	*\param std::ostream* The stream we want to render to.
	*/
    explicit HeroTextRenderer(std::ostream* stream) : TextRenderer(stream) { }
	///\brief A function to render.
	///\param Game& The game we want to render from.
    void render(const Game&) const override;
};

class ObserverTextRenderer : public TextRenderer {
public:
    ObserverTextRenderer() : TextRenderer() {}
	/**
	*\brief A class for rendering text.
	*\param std::ostream& The stream we want to render to.
	*/
    explicit ObserverTextRenderer(std::ostream& stream) : TextRenderer(stream) {}
	/**
	*\brief A class for rendering text.
	*\param std::ostream* The stream we want to render to.
	*/
    explicit ObserverTextRenderer(std::ostream* stream) : TextRenderer(stream) { }
	///\brief A function to render.
	///\param Game& The game we want to render from.
    void render(const Game&) const override;
};

class SVGRenderer : public Renderer {

public:
	/**
	*\brief An abstract class for rendering output to svg file.
	*\param std::string& The file we want to render to.
	*/
    SVGRenderer(const std::string& output) : output(output) {}
	///\brief A function to render.
	///\param Game& The game we want to render from.
    virtual void render(const Game&) const override = 0;

protected:
    const std::string output = ""; ///The file we open.
};

class CharacterSVGRenderer : public SVGRenderer {
public:

	/**
	*\brief A class for rendering output to svg file.
	*\param std::string& The file we want to render to.
	*/
    explicit CharacterSVGRenderer(const std::string& output) : SVGRenderer(output) {}
	///\brief A function to render.
	///\param Game& The game we want to render from.
    virtual void render(const Game&) const override;
};

class ObserverSVGRenderer : public SVGRenderer {
public:
	/**
	*\brief A class for rendering output to svg file.
	*\param std::string& The file we want to render to.
	*/
    explicit ObserverSVGRenderer(const std::string& output) : SVGRenderer(output) {}
	///\brief A function to render.
	///\param Game& The game we want to render from.
    virtual void render(const Game&) const override;
};

#endif 
