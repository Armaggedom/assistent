#ifndef OBJECT_H
#define OBJECT_H

namespace Window_Create_Form {
    struct WINDOW_DEFINE {
        int WindowHight=420;
        int WindowLenght=750;
    };
};
// color and object namespace
namespace Basic_Color_Structs {
    //background obj
    struct BACKGROUND_DEFINE {
        int r=80, g=80, b=80;
    };
    //button obj
    struct BUTTON_STYLE {
        int x1=10;
        int x2=35;
        int y1=200;
        int y2=100;
       int r=255, g=255, b=0;
    };
    struct BUTTON_FONT {
        //not in use
        int font_colorR=0, font_colorG=0, font_colorB=0;
        int x=10;
        int y=40;
    };
};
#endif
