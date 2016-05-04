#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
void putele(const int right, const int down, const HANDLE hOut) 
{ char symb[10]; strcpy(symb, "¡ô"); 
wchar_t wsym[10]; int cvcnt; cvcnt = MultiByteToWideChar(CP_UTF8, 0, symb, -1, NULL, 0);
 MultiByteToWideChar(CP_UTF8, 0, symb, -1, wsym, cvcnt); cvcnt = WideCharToMultiByte(CP_ACP, 0, wsym, -1, NULL, 0, NULL, NULL); WideCharToMultiByte(CP_ACP, 0, wsym, -1, symb, cvcnt, NULL, NULL); COORD pos = {right * 2, down + 1}; SetConsoleCursorPosition(hOut, pos); printf("%s", symb); } int main() { int i, j, k; int updn, leri; i = j = updn = leri = 0; for(k = 0; k < 1000; ++k) { HANDLE hOut; COORD pos= {0, 0}; hOut = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(hOut, pos); printf("--------------------------line: %2d, row: %2d, cnt: %4d--------------------------\n", j, i, k); putele(i, j, hOut); i == 39 ? updn = 1 : 0; j == 23 ? leri = 1 : 0; !i ? updn = 0 : 0; !j ? leri = 0 : 0; !updn ? ++i : --i; !leri ? ++j : --j; Sleep(50); } return 0; }

