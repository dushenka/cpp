 #include <iostream> 
  
 using namespace std; 
  
 void consoleClear() { 
         system("cls"); 
 } 
  
 void consoleBackground() { 
         system("color 30"); 
 } 
  
 void consoleFont() { 
         system("color 03"); 
 } 
  
 void getSizeInt() { 
         cout << sizeof(int); 
  
 } 
  
 void  getSizeDouble() { 
         cout << sizeof(double); 
 } 
  
 void  getSizeChar() { 
         cout << sizeof(char); 
 } 
  
 void  getSizeFloat() { 
         cout << sizeof(float); 
 } 
  
 void  getSizeBool() { 
         cout << sizeof(bool); 
 } 
  
 string greetings() { 
         string text = "Привет, пользователь, добро пожаловать в мою функцию!"; 
         cout << text; 
         return text; 
 } 
  
 void makeKvadrat() { 
         string arr[5][5]{ 
                 {"# ", "# ", "# ", "# ", "# "}, 
                 {"# ", "# ", "# ", "# ", "# "}, 
                 {"# ", "# ", "# ", "# ", "# "}, 
                 {"# ", "# ", "# ", "# ", "# "}, 
                 {"# ", "# ", "# ", "# ", "# "}, 
         }; 
         for (int i = 0; i < 5; i++) { 
                 for (int j = 0; j < 5; j++) { 
                         cout << arr[i][j]; 
                 } 
                 cout << endl; 
         } 
 } 
  
  
  
  
  
 int main() 
 { 
         setlocale(0, ""); 
  
  
         cout << "[+]Программа, которая выводит действия\n\n"; 
         cout << "[+]Выберите действие по номеру:\n"; 
         cout << "[1]Очищение консоли\n"; 
         cout << "[2]Изменение цвета фона консоли\n"; 
         cout << "[3]Изменения цвета текста консоли\n"; 
         cout << "[4]Вывод размера типа данных INT\n"; 
         cout << "[5]Вывод размера типа данных DOUBLE\n"; 
         cout << "[6]Вывод размера типа данных CHAR\n"; 
         cout << "[7]Вывод размера типа данных FLOAT\n"; 
         cout << "[8]Вывод размера типа данных BOOL\n"; 
         cout << "[9]Вывод сообщения\n"; 
         cout << "[10]Вывод квадрата 5*5\n"; 
  
         int choice; 
         cin >> choice; 
  
         switch (choice) 
         { 
  
         case 1: 
                 consoleClear(); 
                 break; 
         case 2: 
                 consoleBackground(); 
                 break; 
         case 3: 
                 consoleFont(); 
                 break; 
         case 4: 
                 cout << "Размер выбранного типа данных: " << sizeof(int) << endl; 
                 break; 
         case 5: 
                 cout << "Размер выбранного типа данных: " << sizeof(double) << endl; 
                 break; 
         case 6: 
                 cout << "Размер выбранного типа данных: " << sizeof(char) << endl; 
                 break; 
         case 7: 
                 cout << "Размер выбранного типа данных: " << sizeof(float) << endl; 
                 break; 
         case 8: 
                 cout << "Размер выбранного типа данных: " << sizeof(bool) << endl; 
                 break; 
         case 9: 
                 greetings(); 
                 break; 
         case 10: 
                 makeKvadrat(); 
                 break; 
         default: 
                 break; 
         } 
  
  
         int _; cin >> _; 
         return 777; 
 }
