//
//	Functions.inl
//
//	Inlinefunktionen
//
//	Luc Arne Wengoborski
//
//	Dieses Programm wird unter der GNU General Public Lizenz weitergegeben
//

#pragma once

#include "Constants.hpp"
#include <math.h>

template <typename test_particle, typename distance, typename return_value = double>
inline return_value calculate_force(test_particle Q1, test_particle Q2, distance r)
{
	return (return_value)(1 / (4 * pi *electric_fieldconstant)*((Q1*Q2) / pow(r, 2)));
}

template <typename test_particle, typename distance, typename return_value = double>
inline return_value calculate_field_charge(test_particle Q, distance r)
{
	return (return_value)(Q / (4 * pi * electric_fieldconstant* pow(r, 2)));
}
