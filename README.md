> Linux 

COMPILE: 
	g++ -std=c++11 hy352_gui.cpp main.cpp Logo.cpp -o LOGO $(pkg-config --libs allegro-5 allegro_image-5 allegro_primitives-5 allegro_font-5 allegro_ttf-5)


