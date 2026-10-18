#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// تابع چاپ
void print(char x[8][8], char *player1, char *player2, int blackCount, int whiteCount) {
    // پاک کردن صفحه
   system("cls");

    //تمایش نام بازیکنان و امتیاز های انها
    printf("%s [B]: %i   Vs   %s [W]: %i\n", player1, blackCount, player2, whiteCount);
    printf("\n");

    //نمایش زمین بازی
    for (int i = 0; i < 8; i++) {
        printf("      %i\t", i);// شماره گزاری ستون ها
    }
    printf("\n");

    for (int j = 0; j < 8; j++) {
        printf(" %3i ", j);// شماره گذاری ردیف ها
        for (int i = 0; i < 8; i++) {
            printf(" | %3c ", x[i][j]);
        }
        printf("\n");
        printf("      ---------------------------------------------------------");
        printf("\n");
    }
}

//تابع بررسی حرکت عمودی
int check_amoodi(char mohre, char x[8][8], int r, int s){
    int checkmove= 0;
    char reverse;
    if (mohre == 'B') {
        reverse = 'W';
    } else {
        reverse = 'B';
    }
    //عمودی به سمت بالا
    for(int i=r-1;i>=0;i--){
        if(x[i][s]== ' '){
            break;
        }
        if (x[i][s] == reverse) {
            continue; // ادامه تا زمانی که مهره مخالف پیدا شه
        }
        if (x[i][s] == mohre && r - i >=2)
        {
            checkmove=1;
            break;// مهره هم‌رنگ پیدا شده و فاصله حداقل ۲ خانه هست

        }
    }
    //عمودی به سمت پایین
    for(int i=r+1;i<8;i++){
        if(x[i][s]== ' '){
            break;
        }
        if (x[i][s] == reverse){
            continue;
        } //ادامه تا زمانی که مهره مخالف پیدا شه
        if (x[i][s] == mohre && i - r >=2)
           {
            checkmove=1;
            break;
        }
    }
    return checkmove;
}
//تابع بررسی حرکت افقی
int check_ofoghi(char mohre, char x[8][8], int r, int s){
    int checkmove= 0;
    char reverse;
    if (mohre == 'B') {
        reverse = 'W';
    } else {
        reverse = 'B';
    }
//افقی به سمت راست
    for(int i=s+1;i<8;i++) {
        if(x[r][i]== ' '){
            break;
        }
        if (x[r][i] == reverse){
            continue; // ادامه تا زمانی که مهره مخالف پیدا شه
        }
        if (x[r][i] == mohre && i - s >=2){
            checkmove=1;
        break;// مهره هم‌رنگ پیدا شده و فاصله حداقل ۲ خانه هست

        }
    }
//افقی به سمت چپ
    for (int i=s-1;i>=0;i--){
        if(x[r][i]== ' '){
            break;
        }
        if (x[r][i] == reverse){
            continue; // ادامه تا زمانی که مهره مخالف پیدا شه
        }
        if (x[r][i] == mohre && s - i >=2){
        checkmove=1;
        break;
            }
    }
    return checkmove;
}
//تابع بررسی حرکت مورب از جهت چپ بالا به جهت راست پایین
int check_movarab1(char mohre, char x[8][8], int r, int s){
    int checkmove=0;
    char reverse;
    if (mohre == 'B') {
        reverse = 'W';
    } else {
        reverse = 'B';
    }
//مورب چپ بالا
    for (int i = r - 1; i >= 0; i--) {
        for (int j = s - 1; j >= 0; j--) {
            //شرط بررسی مورب بودن
            if (i - r == j - s) {
                if(x[i][j]== ' '){
                    break;
                }
                if (x[i][j] == reverse){
                    continue; // ادامه تا زمانی که مهره مخالف پیدا شه
                }
                if(x[i][j]== mohre && r - i >= 2 && s - j >= 2){
                    checkmove=1;
                    break;
                }
            }
        }
    }
//مورب راست پایین
    for (int i = r + 1; i < 8; i++) {
        for (int j = s + 1; j < 8; j++) {
            //شرط بررسی مورب بودن
            if (i - r == j - s) {
                if (x[i][j] == ' ') {
                    break;
                }
                if (x[i][j] == reverse){
                    continue; // ادامه تا زمانی که مهره مخالف پیدا شه
                }
                if (x[i][j] == mohre && i - r >= 2 && j - s >= 2) {
                    checkmove = 1;
                    break;
                }
            }
        }
    }
    return checkmove;
}
//تابع بررسی حرکت مورب از جهت چپ پایین به جهت راست بالا
int check_movarab2(char mohre, char x[8][8], int r, int s){
    int checkmove=0;
    char reverse;
    if (mohre == 'B') {
        reverse = 'W';
    } else {
        reverse = 'B';
    }
//مورب راست بالا
    for (int i = r - 1; i >= 0; i--) {
        for (int j = s + 1; j<8; j++) {
            //شرط بررسی مورب بودن
            if (r - i == j - s) {
                if(x[i][j]== ' '){
                    break;
                }
                if (x[i][j] == reverse){
                    continue; // ادامه تا زمانی که مهره مخالف پیدا شه
                }
                if(x[i][j]== mohre && r - i >= 2 && j - s >= 2){
                    checkmove=1;
                    break;
                }
            }
        }
    }
//مورب چپ پایین
    for (int i = r + 1; i < 8; i++) {
        for (int j = s - 1; j >=0; j--) {
            //شرط بررسی مورب بودن
            if (i - r == s - j) {
                if (x[i][j] == ' ') {
                    break;
                }
                if (x[i][j] == reverse){
                    continue; // ادامه تا زمانی که مهره مخالف پیدا شه
                }
                if (x[i][j] == mohre && i - r >= 2 && s - j >= 2) {
                    checkmove = 1;
                    break;
                }
            }
        }
    }
    return checkmove;
}
// تابع تغییر رنگ مهره ها
void change(char mohre, char x[8][8], int r, int s) {
    x[r][s] = mohre;// قرار دادن مهره در مکان جدید
    char reverse;
    //پیدا کردن متضاد مهره
    if (mohre == 'B') {
        reverse = 'W';
    } else {
        reverse = 'B';
    }

    // تغییر رنگ مهره‌ها در جهت عمودی پایین
    for (int i = r + 1; i < 8; i++) {
        if (x[i][s] == mohre) {// اگر به مهره ای به رنگ مهره خودمون رسیدیم
            for (int j = r + 1; j < i; j++) {// پیمایش تا پایین
                if (x[j][s] == reverse) { // اگر مهره متضاد پیدا شود
                    x[j][s] = mohre;//تغییر رنگ مهره به رنگ مهره خودمون
                } else{
                    break;// اگر به مهره‌ای غیر از مهره مخالف رسیدیم، تغییر رنگ را متوقف می‌کنیم
                }
            }
            break;// پس از پیدا کردن مهره هم‌رنگ و تغییر رنگ مهره‌های مخالف، حلقه را متوقف می‌کنیم
        }
    }
    //تغییر رنگ مهره‌ها در جهت عمودی بالا
    for (int i = r - 1; i >=0; i--) {
        if (x[i][s] == mohre) {
            for (int j = r - 1; j >=i; j--) {
                if (x[j][s] == reverse) {
                    x[j][s] = mohre;
                }else{
                    break;
                }
            }
            break;
        }
    }
    //تغییر رنگ مهره‌ها در جهت افقی راست
    for (int i = s + 1; i < 8; i++) {
        if (x[r][i] == mohre) {// اگر به مهره ای به رنگ مهره خودمون رسیدیم
            for (int j = s + 1; j < i; j++) { // پیمایش به سمت راست
                if (x[r][j] == reverse) {// اگر مهره متضاد پیدا شود
                    x[r][j] = mohre;//تغییر رنگ مهره به رنگ مهره خودمون
                } else{
                    break;// اگر به مهره‌ای غیر از مهره مخالف رسیدیم، تغییر رنگ را متوقف می‌کنیم
                }
            }
            break;// پس از پیدا کردن مهره هم‌رنگ و تغییر رنگ مهره‌های مخالف، حلقه را متوقف می‌کنیم
        }
    }
    //تغییر رنگ مهره‌ها در جهت افقی چپ
    for (int i = s - 1; i >= 0; i--) {
        if (x[r][i] == mohre) {
            for (int j = s - 1; j > i; j--) {
                if (x[r][j] == reverse) {
                    x[r][j] = mohre;
                } else{
                    break;
                }
            }
            break;
        }
    }
    //تغییر رنگ مهره ها در جهت مورب به سمت چپ بالا
    for (int i = r - 1; i >= 0; i--) {
        for (int j = s - 1; j >= 0; j--) {
            if (r-i == s-j) {//بررسی شرط مورب بودن
                if (x[i][j] == mohre){// اگر به مهره ای به رنگ مهره ی خودمون رسیدیم
                    for (int k = 1; k < (r - i); k++) {
                        if (x[r - k][s - k] == reverse) {// اگر مهره متضاد پیدا شود
                            x[r - k][s - k] = mohre;//تغییر رنگ مهره به رتگ مهره خودمون
                        }
                    }
                    break;
                    }
            }
        }
    }
    //تغییر رنگ مهره ها در جهت مورب به سمت راست پایین
    for (int i = r + 1; i < 8; i++) {
        for (int j = s + 1; j < 8; j++) {
            if (i - r == j - s) {
                if (x[i][j] == mohre){
                    for (int k = 1; k < (i-r); k++) {
                        if (x[r + k][s + k] == reverse) {
                            x[r + k][s + k] = mohre;

                        }
                    }
                break;
                    }
            }
        }
    }
    //تغییر رنگ مهره ها در جهت مورب به سمت راست بالا
    for (int i = r - 1; i >= 0; i--) {
        for (int j = s + 1; j < 8; j++) {
            if (r-i == j - s) {
                if (x[i][j] == mohre){
                    for (int k = 1; k < (r - i); k++) {
                        if (x[r - k][s + k] == reverse) {
                            x[r - k][s + k] = mohre;
                        }
                    }
                    break;
                    }
            }
        }
    }
    //تغییر رنگ مهره ها در جهت مورب به سمت چپ پایین
    for (int i = r + 1; i < 8; i++) {
        for (int j = s - 1; j >= 0; j--) {
            if (i - r == s-j) {
                if (x[i][j] == mohre){
                    for (int k = 1; k < (i - r); k++) {
                        if (x[r + k][s - k] == reverse) {
                            x[r + k][s - k] = mohre;
                        }
                    }
                    break;
                    }
            }
        }
    }
}
//تابع کلی تر برای یررسی حرکات درست و مجاز
int correct(char mohre, char x[8][8], int r, int s){
    if(check_amoodi(mohre,x,r,s)||
    check_ofoghi(mohre,x,r,s)||
    check_movarab1(mohre,x,r,s)||
    check_movarab2(mohre,x,r,s)){
        return 1;
    } else {
        return 0;
    }
}
// تابع شمارش مهره ها
void count(char x[8][8], int *blackCount, int *whiteCount){
    *blackCount = 0;
    *whiteCount = 0;

    // پیمایش تمام خانه‌های جدول
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (x[i][j] == 'B') {
                (*blackCount)++;
            } else if (x[i][j] == 'W') {
                (*whiteCount)++;
            }
        }
    }
}
//تابع برای بررسی اتمام بازی
int finish(char x[8][8]){
        int B=0,W=0;

        // بررسی اینکه آیا بازیکن سیاه می‌تواند حرکت معتبری انجام دهد
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (x[i][j] == ' ') {
                    if (correct('B', x, i, j)) {  // بررسی حرکت برای مهره سیاه
                        B = 1;
                    }
                    if (correct('W', x, i, j)) {  // بررسی حرکت برای مهره سفید
                        W = 1;
                    }
                }
            }
        }

        // اگر هیچ‌یک از بازیکنان نتوانند حرکت کنند، بازی تمام میشه
        if (!B && !W) {
            return 1;
        }

        // اگر تمام خانه‌ها پر شوند، بازی نیز تمام می‌شه
        int full = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (x[i][j] == ' ') {  // اگر خانه‌ای خالی باشد
                    full = 0;  // صفحه هنوز پر نشده
                    break;
                }
            }
           if(!full)break;
        }

        if (full) {
            return 1;  // پایان بازی
        }

        return 0;  // بازی ادامه
    }
int main() {
    char x[8][8];

    // مقدار دهی اولیه
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            x[i][j] =' ';
        }
    }

    x[3][3] = 'W';
    x[3][4] = 'B';
    x[4][3] = 'B';
    x[4][4] = 'W';


    char player1[30], player2[30];
    printf("Enter name of Player 1 (Black): ");
    gets(player1);

    printf("Enter name of Player 2 (White): ");
    gets(player2);

    int blackCount = 2, whiteCount = 2;
    char mohre;
    int r, s ,TurnPlayer = 1;

    while (1) {
        // نمایش جدول و اطلاعات بازیکنان
        print(x, player1, player2, blackCount, whiteCount);

        // تغییر نوبت بازیکنان
        if (TurnPlayer == 1) {
            printf("turn black");
            mohre = 'B';
        } else {
            printf("turn white");
            mohre = 'W';
        }

        // دریافت حرکت
        scanf("%i %i", &r, &s);
        if (r < 0 || r >= 8 || s < 0 || s >= 8) {
            printf("Invalid move\n");
            system("pause");
            continue;
        }


        // بررسی حرکت درست و مجاز
        if (correct(mohre, x, r, s)) {
            change(mohre, x, r, s); // اعمال حرکت

            // شمارش مهره‌ها پس از هر حرکت
            count(x, &blackCount, &whiteCount);

            // تغییر نوبت بازیکن
            if (TurnPlayer == 1) {
                TurnPlayer = 2;
            } else {
                TurnPlayer = 1;
            }
        } else {

            printf("Try again\n");
           system("pause");
        }

        // بررسی پایان بازی
        if (finish(x)) {
            // نمایش نتایج نهایی
            print(x, player1, player2, blackCount, whiteCount);
            printf("The End!\n");

            if (blackCount > whiteCount) {
                printf("%s wins.\n", player1);
                printf("mohre  = %i", blackCount);
            } else if (whiteCount > blackCount) {
                printf("%s wins.\n", player2);
                printf("mohre count = %i", whiteCount);
            } else {
                printf("The game is Equal!\n");
            }
            system("pause");
            break;
        }
    }

    return 0;
}

