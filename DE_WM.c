#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Desktop_Env() {
int DEnv;
printf("which desktop environment you want to choose?\n");
printf("1. KDE-plasma\n");
printf("2. GNOME\n");
printf("3. XFCE\n");
printf("4. LXQT\n");
printf("Type here in numbers (default 1):- ");
scanf("%d", &DEnv);

switch (DEnv) {
case 1 :
system("emerge kde-plasma/plasma-meta");
break;
case 2 :
system("emerge gnome-base/gnome");
break;
case 3 :
system("emerge xfce");
break;
case 4 :
system("emerge lxqt");
break;
default:
system(" emerge kde-plasma/plasma-meta");
break;
}
}

void Window_mgr() {
char Wmgr[100];

printf("which window manager you want?");        
         printf("\n1. Hyprland\n");        
         printf("2. sway\n");        
         printf("3. Niri\n");        
         printf("4. Awesome\n");        
         printf("type here in numbers (default: 1):- ");        
         scanf("%99s", Wmgr);        
               
        switch (Wmgr[0]) {        
                        case '1' :        
                             system("emerge gui-wm/hyprland");        
                         break;        
                       case '2' :        
                              system("emerge gui-wm/sway");        
                              break;        
                      case '3' :        
                               system(" emerge gui-wm/niri");        
                               break;        
                      case '4' :        
                                system("emerge x11-wm/awesome");         
                               break;        
                      default:        
                                system("emerge gui-wm/hyprland");        
                               break;        
              }

}

int main() {
char DEWM[100];

printf("do you want DE or WM?:- ");        
          fgets(DEWM, sizeof(DEWM), stdin);        
          DEWM[strlen(DEWM) -1] = '\0';        
                
         if (strcmp(DEWM, "DE") ==0) {        
                    Desktop_Env();        
                    return 0;        
         }        
         if (strcmp(DEWM, "WM") ==0) {        
                   Window_mgr();        
                    return 0;        
         }        
   return 0;

}
