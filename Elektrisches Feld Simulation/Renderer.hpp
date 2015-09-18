//
//	Renderer.hpp
//
//	Fenster + Verwaltung
//
//	Luc Arne Wengoborski
//
//	Dieses Programm wird unter der GNU General Public Lizenz weitergegeben
//


#pragma once

#include <SFML\Graphics.hpp>
#include <list>

class Renderer
{
public:
	void init(sf::String, sf::Vector2i, bool);
	void deinit();
	void process_events();
	void start_render(sf::Drawable*);
	void stop_render(sf::Drawable*);

	void change_color(sf::Color& c) { m_fill_color = c; }

	void realign();


	sf::RenderWindow *pwindow;

private:
	std::list<sf::Drawable*> m_render_list;
	sf::Event m_ev;
	sf::Color m_fill_color;
	sf::Vector2f m_transform;
};
