#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// --- H�M H? TR? ---
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hidecursor() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConCurInf;
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

// --- BI?N GAME ---
int xp[20], yp[20];           // �?n ngu?i choi
int ex_p[10], ey_p[10];       // �?n qu�n d?ch (M?i)
int xx[6], yy[6];             // �?ch nh? (*)
int b_xx[3], b_yy[3];         // �?ch l?n (O)
int score = 0, player_x = 25;
int enemy_speed_counter = 0;

void draw_bar(int x) {
    textcolor(10);
    gotoxy(x + 1, 22); printf("    %c    ", 219);
    gotoxy(x + 1, 23); printf("   %c%c%c   ", 221, 219, 222);
    gotoxy(x + 1, 24); printf("  %c%c%c%c%c  ", 221, 219, 223, 219, 222);
}

// H�m x? l� d?n c?a d?ch (M?i)
void update_enemy_bullets() {
    for (int i = 0; i < 10; i++) {
        if (ex_p[i] != 0) {
            gotoxy(ex_p[i], ey_p[i]); printf(" "); // X�a d?n cu
            ey_p[i]++; // �?n d?ch bay xu?ng

            if (ey_p[i] > 24) {
                ex_p[i] = 0;
            } else {
                // Ki?m tra d?n d?ch tr�ng ngu?i choi
                if (ex_p[i] >= player_x && ex_p[i] <= player_x + 10 && ey_p[i] >= 22) {
                    textcolor(12); gotoxy(25, 12); printf("BAN DA BI TRUNG DAN! GAME OVER!");
                    getch(); exit(0);
                }
                textcolor(14); gotoxy(ex_p[i], ey_p[i]); printf("|"); // V? d?n d?ch
            }
        }
    }
}

void update_enemies() {
    // 1. T?o d?ch
    if (rand() % 80 == 1) {  
        for (int i = 0; i < 6; i++) {
            if (xx[i] == 0) { xx[i] = rand() % 50 + 5; yy[i] = 2; break; }
        }
    }
    if (rand() % 150 == 1) { 
        for (int i = 0; i < 3; i++) {
            if (b_xx[i] == 0) { b_xx[i] = rand() % 45 + 5; b_yy[i] = 2; break; }
        }
    }

    enemy_speed_counter++;
    
    // �?ch nh? di chuy?n v� b?n
    if (enemy_speed_counter % 15 == 0) {
        for (int i = 0; i < 6; i++) {
            if (xx[i] != 0) {
                gotoxy(xx[i], yy[i]); printf(" ");
                yy[i]++;
                // X�c su?t d?ch nh? b?n d?n (M?i)
                if (rand() % 10 == 1) {
                    for (int k = 0; k < 10; k++) {
                        if (ex_p[k] == 0) { ex_p[k] = xx[i]; ey_p[k] = yy[i] + 1; break; }
                    }
                }
                if (yy[i] >= 22) { textcolor(12); gotoxy(25, 12); printf("KE DICH XAM LUOC! GAME OVER!"); getch(); exit(0); }
                textcolor(12); gotoxy(xx[i], yy[i]); printf("*");
            }
        }
    }

    // �?ch l?n di chuy?n v� b?n
    if (enemy_speed_counter % 20 == 0) {
        for (int i = 0; i < 3; i++) {
            if (b_xx[i] != 0) {
                gotoxy(b_xx[i]-1, b_yy[i]); printf("   ");
                b_yy[i]++;
                // X�c su?t d?ch l?n b?n d?n (M?i)
                if (rand() % 5 == 1) {
                    for (int k = 0; k < 10; k++) {
                        if (ex_p[k] == 0) { ex_p[k] = b_xx[i]; ey_p[k] = b_yy[i] + 1; break; }
                    }
                }
                if (b_yy[i] >= 22) { textcolor(12); gotoxy(25, 12); printf("KE DICH XAM LUOC! GAME OVER!"); getch(); exit(0); }
                textcolor(13); gotoxy(b_xx[i]-1, b_yy[i]); printf("(O)");
            }
        }
    }
}

void update_bullets() {
    for (int i = 0; i < 20; i++) {
        if (xp[i] != 0) {
            gotoxy(xp[i], yp[i]); printf(" ");
            yp[i]--;
            if (yp[i] < 2) xp[i] = 0;
            else {
                // Ki?m tra va ch?m v?i d?ch nhu cu...
                for (int j = 0; j < 6; j++) {
                    if (xx[j] != 0 && (xp[i] >= xx[j]-1 && xp[i] <= xx[j]+1) && (yp[i] == yy[j] || yp[i] == yy[j]+1)) {
                        gotoxy(xx[j], yy[j]); printf(" "); xx[j] = 0; xp[i] = 0; score++; break;
                    }
                }
                if (xp[i] != 0) {
                    for (int j = 0; j < 3; j++) {
                        if (b_xx[j] != 0 && (xp[i] >= b_xx[j]-2 && xp[i] <= b_xx[j]+2) && (yp[i] == b_yy[j] || yp[i] == b_yy[j]+1)) {
                            gotoxy(b_xx[j]-1, b_yy[j]); printf("   "); b_xx[j] = 0; xp[i] = 0; score += 5; break;
                        }
                    }
                }
                if (xp[i] != 0) { textcolor(11); gotoxy(xp[i], yp[i]); printf("%c", 4); }
            }
        }
    }
    textcolor(15); gotoxy(74, 20); printf("%-4d", score);
}

int main() {
    system("cls");
    hidecursor();
    srand(time(NULL));

    // Reset m?ng
    for(int i=0; i<10; i++) { ex_p[i]=0; }
    for(int i=0; i<6; i++) { xx[i]=0; }
    for(int i=0; i<3; i++) { b_xx[i]=0; }

    textcolor(15);
    gotoxy(1, 1); printf("+-----------------------------------------------------------+--------------+");
    for (int i = 0; i < 23; i++) { gotoxy(1, i + 2); printf("|                                                           |              |"); }
    gotoxy(1, 25); printf("+-----------------------------------------------------------+--------------+");
    
    gotoxy(66, 3); printf("X: Thoat");
    gotoxy(66, 5); printf("P: Tam dung");
    gotoxy(66, 20); printf("Score: 0");

    while (1) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 'x' || ch == 'X') break;
            if (ch == 'p' || ch == 'P') getch();
            if (ch == ' ') {
                for (int i = 0; i < 20; i++) {
                    if (xp[i] == 0) { xp[i] = player_x + 5; yp[i] = 21; break; }
                }
            }
            if (ch == -32 || ch == 0) {
                ch = getch();
                if (ch == 75 && player_x > 2) { 
                    gotoxy(player_x+1, 22); printf("         "); gotoxy(player_x+1, 23); printf("         "); gotoxy(player_x+1, 24); printf("         ");
                    player_x -= 2; 
                }
                if (ch == 77 && player_x < 52) { 
                    gotoxy(player_x+1, 22); printf("         "); gotoxy(player_x+1, 23); printf("         "); gotoxy(player_x+1, 24); printf("         ");
                    player_x += 2; 
                }
            }
        }
        draw_bar(player_x);
        update_bullets();
        update_enemy_bullets(); // G?i h�m c?p nh?t d?n d?ch
        update_enemies();
        Sleep(40);
    }
    return 0;
}
