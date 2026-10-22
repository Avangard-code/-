
// Лабораторная работа №4
// Выполнил студент
// группы: ИС-126
// Саратовцев Г.А
// Вариант: 10;


/*ОБЩИЙ ИМПОРТ*/
#include <iostream>

/*ИМПОРТ ДЛЯ СИСТЕМЫ WINDOWS*/
#ifdef _WIN32

    #include <windows.h>

/*ИМПОРТ ДЛЯ СИСТЕМЫ UNIX*/
#else 

    #include <clocale>

#endif


/*ГЛОБАЛЬНЫЕ СТРУКТУРЫ*/
struct Price
{
    std::string 
    tovar,
    mag;
    int
    stoim;
};


/*ГЛОБАЛЬНЫЕ КОНСТАНТЫ*/ 
const int GLB_MAX_SIZE_ARR_SPISOK = 5;


/*ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ*/
Price SPISOK [GLB_MAX_SIZE_ARR_SPISOK];


/*ФУНКЦИИ*/
/*
```
КОНФИГУРАЦИЯ КОНСОЛИ
____________________________________
Для Windows - UTF-8
Для UNIX - установка локали системы;
____________________________________
```
*/
void console_config
    (
        void
    )
{
    /*НАСТРОЙКА КОНСОЛИ ДЛЯ WINDOWS*/ 
    #ifdef _WIN32
        SetConsoleCP(CP_UTF8);                                              // Установка ввода с консоли UTF-8
        SetConsoleOutputCP(CP_UTF8);                                        // Установка вывода с консоли UTF-8
        setlocale(LC_ALL,".UTF-8");                                         // Установка локали в UTF-8
    /*НАСТРОЙКА КОНСОЛИ ДЛЯ LINUX*/
    #else 
        setlocale(LC_ALL,".UTF-8");                                         // Установка локали системы
    #endif
}


/*
```
Описать структуру с именем Price, содержащую следующие 
поля: tovar-название товара, mag- название магазина, stoim-стоимость товара. 
Написать программу, выполняющую ввод с клавиатуры данных в массив 
Spisok, состоящий из 5 элементов типа Price. Записи должны быть 
упорядочены по товарам. Вывести на экран информацию о товаре, название 
которого введено с клавиатуры. Если такого нет, то вывести соответствующее 
сообщение. 
```
*/
int main(void)
{
    /*ЛОКАЛЬНЫЕ ПЕРЕМЕННЫЕ*/
    std::string 
    tmp_1;
    Price 
    tmp_price;

    /*НАСТРОЙКА ВВОДА ВЫВОДА КОНСОЛИ*/
    console_config();

    /*ЗАПОЛНЕНИЕ СПИСКА*/
    std :: cout << "\nВведите информацию о "<< GLB_MAX_SIZE_ARR_SPISOK <<" товарах: \n";
    for (int i = 0; i < GLB_MAX_SIZE_ARR_SPISOK; i++)
    {
        std :: cout << "\n";
        std :: cout << "\tНазвание товара "<< i+1 << ": ";
        std :: cin >> SPISOK[i].tovar;
        std :: cout << "\tНазвание магазина "<< i+1 <<": ";
        std :: cin >> SPISOK[i].mag;
        std :: cout << "\tСтоимость товара "<< i+1 << ": ";
        std :: cin >> SPISOK[i].stoim;
    }

    /*СОРТИРОВКА ПО ТОВАРУ*/
    for (int i = 0; i < GLB_MAX_SIZE_ARR_SPISOK - 1; i++) 
    {
        for (int j = i + 1; j < GLB_MAX_SIZE_ARR_SPISOK; j++) 
        {
            if (SPISOK[i].tovar > SPISOK[j].tovar) 
            {
                tmp_price = SPISOK[i];
                SPISOK[i] = SPISOK[j];
                SPISOK[j] = tmp_price;
            }
        }
    }
    
    /*ПОИСК ТОВАРА В СПИСКЕ*/
    tmp_1 = "0";
    std :: cout << "\n \"0\" - завершение программы\n";
    while (true)
    {

        std :: cout << "\nПоиск товара в списке: ";
        std :: cin >> tmp_1;

        if (tmp_1=="0")
        {
            exit(0);
        }
        else
        {
            for (size_t i = 0; i < GLB_MAX_SIZE_ARR_SPISOK; i++)
            {
                if (tmp_1 == SPISOK[i].tovar)
                {
                    std :: cout << "\nТовар: " << SPISOK[i].tovar 
                    << "\nМагазин: " << SPISOK[i].mag 
                    << "\nСтоимость: " << SPISOK[i].stoim 
                    << "\n";
                    
                    break; 
                }
                else if (i == GLB_MAX_SIZE_ARR_SPISOK-1)
                {
                    std :: cout << "\nТОВАР НЕ НАЙДЕН!!!\n";

                    break; 
                } 
            }
        }
    }
}



















































































































































































































































































//Fallen777Angel