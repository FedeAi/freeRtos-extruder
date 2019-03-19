#ifndef	DISPLAYUTILITY_h
#define DISPLAYUTILITY_h

#include "U8glib.h"


typedef enum {
    Menu_p,
    Status,
    Settings,
    Save,
    Reset
}Page_t;




class Menu 
{   
    #define MAX_MENU_ITEMS  5

    private: 
    char *menu_strings[MAX_MENU_ITEMS]; 
    char *title = NULL;
    int *menu_values_int[MAX_MENU_ITEMS];
    double *menu_values_double[MAX_MENU_ITEMS];
    

    public: 
    uint8_t curruntMenu = 0; 
    int itemIdx = 0;
    bool isSelectable = true; 

    //Menu(void){}
    Menu( bool aIsSelectable = true, char * ptTitle = NULL){
        isSelectable = aIsSelectable;
        title = ptTitle;
    }
  
    void addString(char * ptItem){
        if(itemIdx < MAX_MENU_ITEMS){
            menu_strings[itemIdx] = ptItem;
            menu_values_int[itemIdx] = NULL;
            menu_values_double[itemIdx++] = NULL;
        }
    }
    void addStringValue(char * ptItem, int *ptValue){
        if(itemIdx < MAX_MENU_ITEMS){
            menu_strings[itemIdx] = ptItem;
            menu_values_int[itemIdx] = ptValue;
            menu_values_double[itemIdx++] = NULL;
        }
    }
    void addStringValue(char * ptItem, double *ptValue){
        if(itemIdx < MAX_MENU_ITEMS){
            menu_strings[itemIdx] = ptItem;
            menu_values_int[itemIdx] = NULL;
            menu_values_double[itemIdx++] = ptValue;
        }
    }

    void updateMenu(int aUiKeyCode);

    void drawMenu(); 
      
}; 


extern U8GLIB_ST7920_128X64_1X u8g;


#endif


