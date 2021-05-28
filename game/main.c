#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
int main(void) {
    al_show_native_message_box(NULL, "INFO", "V:0.0", "Jogo em desenvolvimento aguarde", NULL, ALLEGRO_MESSAGEBOX_WARN);
    return 0;
}
