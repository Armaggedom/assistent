//c++
#include<iostream>
//allegro
#include<allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
//define window
#define HIGHT 420 //474
#define LENGHT 680 //474
void buffer_clear(void) {
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//create map

}
int main(void) {
    int hight=420;
    int length=680;
	//function
	void buffer_clear(void);
	int rulex(int x);
	int ruley(int y);
	//variable
	bool stop=false;
	//define ALLEGRO
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *person=NULL;
	ALLEGRO_EVENT_QUEUE *event;
	//warn message
    al_show_native_message_box(NULL, "INFO", "apenas linguagem PTBR suportada", NULL, NULL, 0);
    //error message
    if(!al_init()) {
    	al_show_native_message_box(NULL, "CRITICAL ERROR", "ERROR:", "ALLEGRO não pode ser iniciado", NULL, ALLEGRO_MESSAGEBOX_ERROR);
   		return -1;
    }
    else {
        std::cout<<"ALLEGRO init"<<std::endl;
    };
    if(!al_init_image_addon()) {
        al_show_native_message_box(NULL, "GRAPHIC ERROR", "ERROR", "ALLEGRO não pode inicar image_addon", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    else {
        std::cout<<"image_addon init"<<std::endl;
    };
    //load images
    background=al_load_bitmap("default.png");
    person=al_load_bitmap("personagem.png");
    if(background==NULL or person==NULL) {
        al_show_native_message_box(NULL, "GRAPHIC ERROR", "ERROR", "ALLEGRO não encontrou as imagens", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    else {
        std::cout<<"bitmap load"<<std::endl;
    };
    display=al_create_display(length, hight);
    if(!display) {
    	al_show_native_message_box(NULL, "GRAPHIC ERROR", "ERROR", "ALLEGRO não pode criar a janela", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
    }
    else {
      std::cout<<"ALLEGRO display init"<<std::endl;
    };
    //create event
    event=al_create_event_queue();
    //install
    if(!al_install_keyboard()) {
    	al_show_native_message_box(NULL, "ERROR", "não foi possivel instalar o teclado", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
    }
    else {
      std::cout<<"Install keyboard init"<<std::endl;
    };
	//register events
    al_register_event_source(event, al_get_keyboard_event_source());
    al_register_event_source(event, al_get_display_event_source(display));
    //person int
    int x=0;
    int y=0;
    //event switch
    do {
    	ALLEGRO_EVENT ev;
    	//buffer clear
    	buffer_clear();
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_bitmap(person, x, y, 0);
    	al_flip_display();
    	al_wait_for_event(event, &ev);
    	//close button
    	if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE) {
    		stop=true;
    	}
    	//keyboard input
    	else if(ev.type==ALLEGRO_EVENT_KEY_DOWN) {
    		//escape(ESC) key
            if(ev.keyboard.keycode==ALLEGRO_KEY_ESCAPE) {
                stop=true;
            };
            if(ev.keyboard.keycode==ALLEGRO_KEY_W) {
              y-=10;
            };
            if(ev.keyboard.keycode==ALLEGRO_KEY_A) {
              x-=10;
            };
            if(ev.keyboard.keycode==ALLEGRO_KEY_S) {
              y+=10;
            };
            if(ev.keyboard.keycode==ALLEGRO_KEY_D) {
              x+=10;
            };
            //rule
            if(x>680)
                x-=x;
            if(x<0)
                x+=x;
            if(y<0)
                y+=y;
            if(y>480)
                y-=y;

            std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
    	};

    }while(!stop);
    std::cout<<"stop request"<<std::endl;
    al_destroy_event_queue(event);
    std::cout<<"destroy queue=event"<<std::endl;
    al_destroy_display(display);
    std::cout<<"destroy al_display"<<std::endl;
    std::cout<<"ALLEGRO stoped"<<std::endl;
    return 0;
}
