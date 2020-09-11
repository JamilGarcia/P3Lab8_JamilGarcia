#include <curses.h>
WINDOW *ventana;

/*
A_NORMAL        Normal display (no highlight)
    A_STANDOUT      Best highlighting mode of the terminal.
    A_UNDERLINE     Underlining
    A_REVERSE       Reverse video
    A_BLINK         Blinking
    A_DIM           Half bright
    A_BOLD          Extra bright or bold
    A_PROTECT       Protected mode
    A_INVIS         Invisible or blank mode
    A_ALTCHARSET    Alternate character set
    A_CHARTEXT      Bit-mask to extract a character
    COLOR_PAIR(n)   Color-pair number n 
*/

int main()
{
    int MaxX, MaxY; 
    initscr();
    getmaxyx(stdscr, MaxY, MaxX); 
    int MaxXTit = MaxX-4, 
        MaxXIzq = MaxX*0.33, 
        MaxXIzq2 = MaxX - (MaxX * 0.33), 
        MaxXYIzq = MaxY - (MaxY * 0.65), 
        MaxYDer = MaxY - (MaxY *0.5), 
        MaxYDer2 = MaxY - (MaxY * 0.55);
        //MaxYDer2 = MaxY -(MaxY*0.25); 
    if (!has_colors()){
        endwin(); 
        return 1; 
    }
    cbreak(); 
    noecho(); 
    nonl(); 
    intrflush(ventana, FALSE); 
    keypad(ventana, TRUE); 
    start_color(); 
    init_pair(1, COLOR_WHITE, COLOR_BLUE); 
    init_pair(2, COLOR_BLACK, COLOR_CYAN); 
    ventana = newwin(MaxY, MaxX, 0, 0);
    WINDOW *ventana_arr  = newwin(1, MaxX, 0, 0), 
    *titulo = newwin(3, MaxXTit, 2, 2), 
    *izquierda = newwin(MaxYDer2, MaxXIzq, MaxXYIzq, 2), 
    *derecha = newwin(MaxYDer2, (MaxXTit - MaxXIzq - 4 ), MaxXYIzq, MaxX/2.7);

    wbkgd(ventana, COLOR_PAIR(1));
    wbkgd(ventana_arr, COLOR_PAIR(2)); 
    wbkgd(titulo, COLOR_PAIR(1));  
    wbkgd(izquierda, COLOR_PAIR(1));  
    wbkgd(derecha, COLOR_PAIR(1));  
    box (titulo, ACS_VLINE, ACS_HLINE);
    box (izquierda, ACS_VLINE, ACS_HLINE);
    box (derecha, ACS_VLINE, ACS_HLINE);

    attron(A_BOLD); 
    wprintw(ventana_arr, "YaST @ g185"); 
    mvwprintw(titulo, 1 , MaxXTit/2.5, "YaST2 Control Center") ;
    mvwprintw(ventana_arr, 0 , MaxX -18, "Press F1 for Help") ;
    attroff(A_BOLD);

    //Izquierda
    attron(A_STANDOUT); 
    mvwprintw(izquierda, 1, 1,  "Software") ;
    attroff(A_STANDOUT); 
    mvwprintw(izquierda, 2, 1, "HardWare");
    mvwprintw(izquierda, 3, 1, "System");
    mvwprintw(izquierda, 4, 1, "Network Devices");
    mvwprintw(izquierda, 5, 1,"NetWork Services");
    mvwprintw(izquierda, 6, 1, "Security and Users");
    mvwprintw(izquierda, 7, 1, "Misc");
    //Derecha
    attron(WA_REVERSE);
    mvwprintw(derecha, 1, 1, "Patch CD Update") ;
    attroff(WA_REVERSE); 
    mvwprintw(derecha, 2, 1, "Installation into Directory") ;
    mvwprintw(derecha, 3, 1, "Online Update") ;
    mvwprintw(derecha, 4, 1, "Install and Remove Software") ;
    mvwprintw(derecha, 5, 1, "Change Source of Installation") ;
    mvwprintw(derecha, 6, 1, "System Update") ;

    mvwprintw(ventana, MaxY-2, 2, "[Help]");
    mvwprintw(ventana, MaxY-2, MaxX-10, "[Quit]");

    touchwin(ventana); 
    touchwin(ventana_arr); 
    touchwin(titulo); 
    touchwin(izquierda); 
    touchwin(derecha); 
    wrefresh(ventana);
    wrefresh(ventana_arr);
    wrefresh(titulo);
    wrefresh(izquierda);
    wrefresh(derecha);

    /*
    int tecla = getch();
    printw("%d", tecla);
    refresh();
    */
   //getch(); 
    getchar();  
    endwin();
    return 0;
}