//CMD Output Include
#include <iostream>
//Headers
#include "object.h"
//Allegro Include
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
//Namespaces
using namespace Basic_Color_Structs;
//namespace Window_Create_Form (declared using '::')
//Version
char version[]="1.3.1-ALPHA-DEBUG";
//Allegro Conversor
Window_Create_Form::WINDOW_DEFINE win;
//Global Funcion
bool Error(void) {
    return true;
}
void ComandCMDOutput(void) {
    //CMD Output
    for(int i=0; i<17; i++) {
        std::cout<<"-";
        };
    std::cout<<"\nDev: Bombbom\nVersion: "<<version<<std::endl;
    for(int i=0; i<17; i++) {
        std::cout<<"-";
    };
    std::cout<<" "<<std::endl;
}
int main(void) {
    //Allegro variable
    bool stop=false;
    //CMD Output
    void ComandCMDOutput(void);
    void RenderDisplay(void);
    int Text_Builder(void);
    void Obj_Builder(void);
    //Call CMD Output
    ComandCMDOutput();
    //Allegro define
    ALLEGRO_EVENT_QUEUE *event=NULL;
    ALLEGRO_DISPLAY *display=NULL;
    //Allegro init
    if(!al_init()) {
        al_show_native_message_box(NULL, "ERROR", "ERROR: ", "ALLEGRO fail", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    //Init font addon
    al_init_font_addon();
    //Init ttf addon(font function in .TTF)
    if(!al_init_ttf_addon()) {
        al_show_native_message_box(NULL, "ERROR", "ERROR: ", "TTF fail", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    //Init Primitive_addon(Color and bitmap)
    if(!al_init_primitives_addon()) {
        al_show_native_message_box(NULL, "ERROR", "ERROR: ", "ALLEGRO Graphic fail", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    //Create display
    display=al_create_display(win.WindowLenght, win.WindowHight);
    if(!display) {
        al_show_native_message_box(NULL, "ERROR", "ERROR: ", "Display fail", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    //Define Background
    BACKGROUND_DEFINE background;
    //Define Background Color
    al_clear_to_color(al_map_rgb(background.r, background.g, background.b));
    //Object builder
    Obj_Builder();
    //create event
    event=al_create_event_queue();
    al_register_event_source(event, al_get_display_event_source(display));
    //Allegro install
    if(!al_install_mouse()) {
        al_show_native_message_box(NULL, "ERROR", "ERROR: ", "Mouse install fail", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    //Draw text
    if(Text_Builder()==-1) {
        al_destroy_display(display);
        al_show_native_message_box(NULL, "ERROR", "ERROR: ", "TTF not found", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    };
    //Main loop

        while(!stop){
            //Render function
            RenderDisplay();
            //event declaration
            ALLEGRO_EVENT ev;
            al_wait_for_event(event, &ev);
            //event
            if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE) {
                stop=true;
            }
        };
        //end command
        al_destroy_display(display);
        al_destroy_event_queue(event);
        std::cout<<"process exited"<<std::endl;
        return 0;
}
void Obj_Builder(void) {
    BUTTON_STYLE button;
    al_draw_filled_rectangle(button.x1, button.x2, button.y1, button.y2, al_map_rgb(button.r, button.g, button.b));
    al_draw_filled_rectangle(button.x1, button.addSpacex*button.x2, button.y1, button.addSpacey, al_map_rgb(button.r, button.g, button.b));
}
int Text_Builder(void) {
    ALLEGRO_FONT *font=NULL;
    //Font load
    font=al_load_font("Anger_Management.ttf", 45, 0);
    if(!font) {
        return -1;
    };
    BUTTON_FONT fontS;
    al_draw_text(font, al_map_rgb(fontS.font_colorR, fontS.font_colorG, fontS.font_colorB), fontS.x, fontS.y, ALLEGRO_ALIGN_LEFT, "Esquerda");
    al_draw_text(font, al_map_rgb(fontS.font_colorR, fontS.font_colorG, fontS.font_colorB), fontS.x, fontS.spaceText*fontS.y, ALLEGRO_ALIGN_LEFT, "Esquerda");
    al_draw_textf(font, al_map_rgb(fontS.font_colorR, fontS.font_colorG, fontS.font_colorB), win.WindowLenght, win.WindowHight-50, ALLEGRO_ALIGN_RIGHT, "V: %s", version);
    al_destroy_font(font);
    return 0;
}
void RenderDisplay(void) {
    al_flip_display();
}
