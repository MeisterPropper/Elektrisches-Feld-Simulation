#include <iostream>
#include <Windows.h>
#include "Functions.inl"
#include "Renderer.hpp"

__int32 _stdcall WinMain(HINSTANCE,
	HINSTANCE,
	LPSTR,
	__int32)
{
	// Testbereich //
	//**********************************

	Renderer renderer;

	
	sf::CircleShape cs;
	cs.setFillColor(sf::Color(255, 0, 255));
	cs.setRadius(100.f);
	cs.setPosition(sf::Vector2f(200.f, 200.f));
	cs.setPointCount(200);
	cs.setOutlineThickness(5);
	cs.setOutlineColor(sf::Color(0, 0, 155));

	renderer.init(sf::String("Elektrisches Feld Simulation - Debug"), sf::Vector2i(800, 600), false);

	renderer.start_render(&cs);
	renderer.process_events();
	double result = calculate_field_charge(5, 3);
	renderer.deinit();

	//**********************************
	return 0x0;
}