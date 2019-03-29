#ifndef	MENU_H
#define MENU_H

#include "U8glib.h"
#include "temperatureManager.h"
#include "Extruder.h"
class Menu 
{   
    #define MAX_MENU_ITEMS  5

    private: 
        char *menu_strings[MAX_MENU_ITEMS]; 
        float *menu_values_float[MAX_MENU_ITEMS];
        double *menu_values_double[MAX_MENU_ITEMS];   /* TODO: eliminare non usato */
        const u8g_fntpgm_uint8_t *menuFont;

    public: 
        bool has_menu = false;
        char *title = NULL;
        uint8_t currentMenu = 0; 
        int itemIdx = 0;
        int nMenuItems = 0;
        bool isSelectable = false; 
        bool isSelected = false; 
        int topSpacing;

    Menu(char * ptTitle = NULL, u8g_fntpgm_uint8_t *aMenuFont = u8g_font_profont12 ):
        menuFont(aMenuFont), title(ptTitle)  { }

    void addMenuString(char * ptItem){
        has_menu = true;

        if(itemIdx < MAX_MENU_ITEMS){
            menu_strings[itemIdx] = ptItem;
            menu_values_float[itemIdx] = NULL;
            menu_values_double[itemIdx++] = NULL;
            nMenuItems++;
        }
    }
    void addMenuStringValue(char * ptItem, void *ptValue){
        has_menu = true;

        if(itemIdx < MAX_MENU_ITEMS){
            menu_strings[itemIdx] = ptItem;
            menu_values_float[itemIdx] = ptValue;
            menu_values_double[itemIdx++] = NULL;
            nMenuItems++;
        }
    }

    void updateMenu(int aUiKeyCode);
    void drawMenu();    
      
}; 

class Page : public Menu
{   
    public:     
        Page(char *aPtTitle = NULL, u8g_fntpgm_uint8_t *aMenuFont = u8g_font_profont12 ): Menu(aPtTitle, aMenuFont){ }
        virtual void drawPage();
        void drawTitle();  
        void drawButton(int x, int y, int id, char * name, const u8g_fntpgm_uint8_t *font);
        char *heaterStatus;
        char *motorStatus;
        char *PCE;
        char *PTR;
}; 



class StatusPage : public Page
{   
    public:     
        StatusPage(char *aPtTitle = NULL, TemperatureManager * aPtTemperatureManager = NULL, Extruder *aPtExtruderManager = NULL ): Page(aPtTitle), ptTemperatureManager(aPtTemperatureManager), ptExtruderManager(aPtExtruderManager)
        { nMenuItems = 1; heaterStatus = "COLD"; motorStatus="ON";}
        void drawPage();
    private:
        TemperatureManager *ptTemperatureManager;
        Extruder *ptExtruderManager;
        
}; 
class SettingPage : public Page
{   
    public:     
        SettingPage(char *aPtTitle = NULL, TemperatureManager * aPtTemperatureManager = NULL, Extruder *aPtExtruderManager = NULL ): Page(aPtTitle), ptTemperatureManager(aPtTemperatureManager), ptExtruderManager(aPtExtruderManager)
        { nMenuItems = 3; PCE=" PCE"; PTR=" PTR";}
        void drawPage();
    private:
        TemperatureManager *ptTemperatureManager;
        Extruder *ptExtruderManager;
        
}; 

class SavePage : public Page
{   
    public:     
        SavePage(char *aPtTitle = NULL, u8g_fntpgm_uint8_t *aMenuFont = u8g_font_profont12 ): Page(aPtTitle, aMenuFont){ nMenuItems = 0;}
        void drawPage();
        
}; 
class ResetPage : public Page
{   
    public:     
        ResetPage(char *aPtTitle = NULL, u8g_fntpgm_uint8_t *aMenuFont = u8g_font_profont12): Page(aPtTitle, aMenuFont){ nMenuItems = 0;}
        void drawPage();
        
}; 

extern U8GLIB_ST7920_128X64_1X u8g;

#endif