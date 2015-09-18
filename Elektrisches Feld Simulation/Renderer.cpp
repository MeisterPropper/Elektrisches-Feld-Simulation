#include "Renderer.hpp"
#include "Constants.hpp"

void Renderer::init(sf::String s , sf::Vector2i v, bool b)
{
	if(b)
		pwindow = new sf::RenderWindow(sf::VideoMode(v.x, v.y), s, sf::Style::Fullscreen);
	else
		pwindow = new sf::RenderWindow(sf::VideoMode(v.x, v.y), s);
	m_fill_color = { 238, 232, 232 };
	m_transform = { 1, 1 };
}

void Renderer::deinit()
{
	delete pwindow;
	pwindow = nullptr;
}

void Renderer::process_events()
{
	while (pwindow->isOpen())
	{
		while (pwindow->pollEvent(m_ev))
		{
			switch (m_ev.type)
			{
			case sf::Event::Closed:
				pwindow->close(); break;
			case sf::Event::Resized:
				realign(); break;
			case sf::Event::KeyPressed:
			{
				switch (m_ev.key.code)
				{
				case sf::Keyboard::Escape:
					pwindow->close(); break;	// Später wieder entfernen!!!
				}
			}
			}
		}
		
		// Fenster aktualisieren
		pwindow->clear(m_fill_color);
		for (auto it = m_render_list.begin(); it != m_render_list.end(); ++it)
		{
			pwindow->draw(*(*it));
		}
		pwindow->display();
	}
}

void Renderer::start_render(sf::Drawable *p)
{
	// Nullzeigertest
	if (!p) return;

	m_render_list.push_back(reinterpret_cast<sf::Drawable*>(p));
}

void Renderer::stop_render(sf::Drawable *p)
{
	for (auto it = m_render_list.begin(); it != m_render_list.end(); ++it)
	{
		if ((*it) == p)
		{
			m_render_list.erase(it);
			return;
		}
	}
	return;
}

void Renderer::realign()
{
	sf::Vector2u size_new = pwindow->getSize();
	sf::Vector2u size_org = reference_resolution;

	sf::Vector2f transform = sf::Vector2f((float)size_org.x / (float)size_new.x, (float)size_org.y / (float)size_new.y);

	m_transform = transform;

	for (auto it = m_render_list.begin(); it != m_render_list.end(); ++it)
	{
		reinterpret_cast<sf::Sprite*>((*it))->setScale(sf::Vector2f(m_transform.x, m_transform.y));
	}
}
