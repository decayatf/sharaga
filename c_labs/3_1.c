#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    char str[81];
    printf("Введите строку символов (до 80 символов): ");
    fgets(str, 81, stdin); // считываем строку с консоли
    
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'b') { // если символ маленький 'a' или 'b'
            str[i] = toupper(str[i]); // меняем на заглавный символ 
        }
    }
    
    printf("Результат: %s", str);
}//