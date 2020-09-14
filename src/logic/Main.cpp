#pragma once
#include "Mainframe.h"

void main() {
    
Mainframe* pongRevised = new Mainframe;
	pongRevised->init();
	pongRevised->mainLoop();
	
	delete pongRevised;
  }