/**
 * mors_defensePlanner.hpp
 */
#pragma once
#include "mors_planner.hpp"

class MorsDefensePlanner : public MorsPlanner
{
public:
	MorsDefensePlanner(); //costruttore

	void handle(); //non è una sua funzione, ma di MorsPlanner
};
