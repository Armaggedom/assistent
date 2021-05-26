//PROMPT
#include <iostream>
//ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#define HIGHT 480
#define LENGHT 680
int main(void) {
    //VARIABLE
    bool stop=false;
    //ALLEGRO WINDOW DEFINE
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event;
    if(!al_init()) {
        al_show_native_message_box(NULL, "CRITICAL ERROR", "ERROR: ", "ALLEGRO cannot be initialized", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    display = al_create_display(LENGHT, HIGHT);
    if(!display) {
        al_show_native_message_box(NULL, "GRAPHIC ERROR", "ERROR: ", "Window cannot be opened", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    std::cout << "DEV: Bombbom" << std::endl;

    //EVENT
    event=al_create_event_queue();
    al_register_event_source(event, al_get_display_event_source(display));
    //MAIN PROGRAM
    do {
        //DRAW
        al_clear_to_color(al_map_rgb(255, 255, 255));
        //EVENT DEFINE
        ALLEGRO_EVENT ev;
       al_flip_display();
        al_wait_for_event(event, &ev);
        //EVENT IF
        if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE) {
          stop=true;
        };
    } while(!stop);
    al_destroy_display(display);
}
