#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

char a[55][55];
int b[55][55];
int n, remain;
void otp()
{
    system("cls");
    int i, j;
    putchar(' ');putchar(' ');
    for (i = 0; i < n; i++)
    {
        printf(" %d", i % 10);
    }
    putchar('\n');
    for (i = 0; i < n; i++)
    {
        printf("%d  ", i % 10);
        for (j = 0; j < n; j++)
        {
            putchar(a[i][j]);
            //putchar(b[i][j] + '0');
            putchar(' ');
        }
        printf(" %d", i % 10);
        putchar('\n');
    }
    putchar(' ');putchar(' ');
    for (i = 0; i < n; i++)
    {
        printf(" %d", i % 10);
    }
    putchar('\n');
    printf("There are %d piece(s) of ground remaining\n", remain);
}
void pre(int row, int col)
{
    int cot = 0;
    if (b[row][col] != -1)
    {
        if (row > 0 && b[row - 1][col] == -1) cot++;
        if (row > 0 && col > 0 && b[row - 1][col - 1] == -1) cot++;
        if (col > 0 && b[row][col - 1] == -1) cot++;
        if (row > 0 && b[row - 1][col + 1] == -1) cot++;
        if (col > 0 && b[row + 1][col - 1] == -1) cot++;
        if (b[row][col + 1] == -1) cot++;
        if (b[row + 1][col] == -1) cot++;
        if (b[row + 1][col + 1] == -1) cot++;
        b[row][col] = cot;
    }

}
void uncover(int row, int col)
{
    remain--;
    a[row][col] = (b[row][col] == 0) ? ' ' : (b[row][col] + '0');
    if (b[row][col] == 0)
    {
        //printf("%d %d %d\n", remain, row, col);
        if (row < n - 1 && a[row + 1][col] == '#') uncover(row + 1, col);
        if (col < n - 1 && a[row][col + 1] == '#') uncover(row, col + 1);
        if (row > 0 && a[row - 1][col] == '#') uncover(row - 1, col);
        if (col > 0 && a[row][col - 1] == '#') uncover(row, col - 1);
        if (row < n - 1 && col < n - 1 && a[row + 1][col + 1] == '#') uncover(row + 1, col + 1);
        if (row > 0 && col < n - 1 && a[row - 1][col + 1] == '#') uncover(row - 1, col + 1);
        if (row > 0 && col > 0 && a[row - 1][col - 1] == '#') uncover(row - 1, col - 1);
        if (row < n - 1 && col > 0 && a[row + 1][col - 1] == '#') uncover(row + 1, col - 1);

    }
    return ;
}
int main()
{
    srand(time(NULL));
    while (1)
    {
        int mines, i, j;
        int opx, opy;
        system("cls");
        printf("Please input the length of a side(2 to 30)\n");
        scanf("%d", &n);
        if (n < 2 || n > 30)
        {
            printf("Invalid input!\nPress any key to continue");
            getch();
            continue;
        }
        printf("\nPlease input the number of mines\n");
        scanf("%d", &mines);
        remain = n * n - mines;
        if (mines >= n * n)
        {
            printf("There are too many mines!\nPress any key to continue");
            getch();
            continue;
        }
        if (mines < 1)
        {
            printf("Are you kidding me? Please input the number of mines seriously!\nPress any key to continue");
            getch();
            continue;
        }
        memset(a, '#', sizeof(a));
        memset(b, 0, sizeof(b));
        for (i = 0; i < mines;)
        {
            int x = rand() % n;
            int y = rand() % n;
            if (b[x][y] != -1)
            {
                i++; b[x][y] = -1;
                //a[x][y] = 'a';
            }
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                pre(i, j);
        otp();
        printf("Please input the operations:\nIf you want to uncover a wall, please input 'a' first\n");
        printf("Or if you want to mark a mine, please input 'b' first\n");
        printf("Then input the xth row and yth column to indicate the ground\n");
        printf("For example: a 15 13 means uncover the ground that located in 15th row and 13th column\n");
        while (remain> 0)
        {
            char opc[50];
            scanf("%s%d%d", opc, &opx, &opy);
            if (opx < 0 || opx >= n || opy < 0 || opy >= n)
            {
                printf("\nInvalid input! Press any key to continue");
                getch();
                otp();
                continue;
            }
            if (opc[0] == 'a')
            {
                if (a[opx][opy] != '#')
                {
                    printf("The ground has been uncovered\nPress any key to continue");
                    getch();
                }
                else if (b[opx][opy] != -1)
                {
                    uncover(opx, opy);
                }
                else
                {
                    system("cls");
                    printf("BOOM!\n");
                    printf("Press any key to continue\n");
                    getch(); break;
                }
            }
            else if (opc[0] == 'b')
            {
                if (a[opx][opy] == '#')
                    a[opx][opy] = '!';
                else if (a[opx][opy] == '!')
                    a[opx][opy] = '#';
                else
                {
                    printf("You cannot mark a uncovered ground!\nPress any key to continue");

                    getch();
                }
            }
            else
            {
                printf("\nInvalid input! Press any key to continue");
                getch();
                continue;
            }
            otp();
        }
        if (remain <= 0)
        {
            printf("You win!\n");
            printf("Press any key to continue");
            getch();
        }
    }
    return 0;
}
