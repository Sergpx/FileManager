#pragma once
#include "Element.h"
#include <vector>
class NavWindow
{
	Element* activeElement = nullptr;
	std::vector<Element> elements;
public:
	void removeElement();
	void addElement(Element);
	
};

