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
        float x1=10;
        float x2=35;
        float y1=200;
        float y2=100;
        float addSpacex=3.5;
        float addSpacey=y2-x2+x2*addSpacex;
        int r=255, g=255, b=0;
    };
    struct BUTTON_FONT {
        //not in use
        int font_colorR=0, font_colorG=0, font_colorB=0;
        int x=10;
        int y=40;
        float spaceText=3.2;
    };
};
#endif
