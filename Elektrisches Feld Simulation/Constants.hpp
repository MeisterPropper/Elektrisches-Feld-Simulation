//
//	Constants.hpp
//
//	Konstanten und Enumerationen
//
//	Luc Arne Wengoborski
//
//	Dieses Programm wird unter der GNU General Public Lizenz weitergegeben
//


#pragma once

#include <math.h>
#include <SFML\Graphics.hpp>

// PI
const long double pi = 3.141592653589793238462643383279502884L;
// Elektrische Feldkonstante E0
const double electric_fieldconstant = 8.85418782*pow(10, -12);
// Elementarladung
const double elementary_charge = 1.6022*pow(10, -19);

// Referenzauflösung des Fensters
// Wird für die korrekte Skalierung aller Elemente verwendet
const sf::Vector2u reference_resolution = { 1920, 1080 };


