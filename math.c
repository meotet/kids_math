#include <stdio.h>
#include <cs50.h>
//#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


string vozrast(int year);
string konfeti(int candy);
string balli(int score);
string girl_name(int number);
string kukli(int dolls);
string girl_name2(int number);

int main(void)
{
    /* Intializes random number generator */
    srand(time(NULL));


    //greet and get name

    string name = get_string("Как тебя зовут?\n");

    printf("Привет, %s!\n\n", name);

    /*

    string agree = get_string("Будешь решать задачу?\n");

    if (strcmp(agree, "да") == 0 || strcmp(agree, "Да") == 0) //agree == "Да" || agree == "да")

       {
       printf("Давай!\n");
       }

    else
    {
       printf("Как хочешь\n");
       return 0;
    }

    */

    //question choice
    int score = 0;
    do
    {


        printf("\nТвой счет: %i %s.\n\n", score, balli(score));
        int choice =
            get_int("Выбери задачу:\n\n1. Маша и магазин\n2. Саша и магазин\n3. Примеры на сложение\n4. Примеры на вычитание\n5. Сколько лет Наташе?\n6. Про кошек\n7. Девочки и конфеты\n8. Девочки и куклы\n\n0.Выход\n");

        do
        {

            if (choice == 1) //first question

            {

         int spent;

         do
         {
         spent = get_int("Мама отправила Машу в магазин за покупками, дала 100 руб. и попросила принести не меньше 30 руб. сдачи. Сколько рублей потратила Маша?\n");
         }
         while (spent > 71 || spent < 0);

         int remaining = get_int("Cколько у нее осталось?\n");

            if ((remaining + spent) == 100)
            {
               sleep(1);
               printf("Правильно!\n\n");
               score = score + 1;
               sleep(1);
               break;
            }
            else
            {
               int correct = 100 - spent;
               sleep(1);
               printf("Неправильно. Маша потратила %i руб.\n", correct);
               score = score - 1;
               sleep(3);
               printf("Попробуй еще\n");
               sleep(1);
            }
         }

      //Second question
      if (choice == 2)

         {
            /* Intializes random number generator */
            //srand(time(NULL));

            int random_allowed = rand() % (100 - 50 + 1) + 50;
            //printf("%i\n", random_spent);
            printf("Папа отправил Сашу в магазин и дал %i руб.\n", random_allowed);

            int random_spent = random_allowed / (rand() % (8 - 2 + 1) + 2);
            //printf("%i\n", random_spent);

            sleep(1);
            printf("Саша потратил %i руб.\n", random_spent);

            sleep(1);
            int r_remaining = get_int("Сколько у Саши осталось?\n");

               if (r_remaining + random_spent == random_allowed)
               {
               sleep(1);
               printf("Правильно!\n");
               score = score + 10;
               sleep(1);
               break;
               }

               else
               {
               int r_correct = random_allowed - random_spent;
               sleep(1);
               printf("Неправильно. Саша потратил %i руб.\n", r_correct);
               score = score - 5;
               sleep(2);
               printf("Попробуй еще\n");
               sleep(1);
               }
         }
      if (choice == 3)

      {
         /*int k = get_int("Сколько примеров ты хочешь решить?\n");
         int i;
         for (i = 1; i < k; ++i)*/
         {
            int x = rand() % (10 - 0 + 1) + 1;
            int y = rand() % (10 - 0 + 1) + 1;
            printf("%i+%i=\n", x, y);
            sleep(1);
            int z = get_int("Ответ:\n");

            if (x + y == z)
               {
                  sleep(1);
                  printf("Правильно!\n");
                  score = score + 2;
                  sleep(1);
                  break;
               }
            else
               {
                  int z_correct = x + y;
                  sleep(1);
                  printf("Неправильно. Получилось %i\n", z_correct);
                  score = score - 1;
                  sleep(2);
                  printf("Попробуй еще\n");
                  sleep(1);
               }
         }
         //continue;
      }

      if (choice == 4)
      {
         int x = rand() % (10 - 1 + 1) + 1;
         int y = 0;
         do
         {
         y = rand() % (10 - 1 + 1) + 1;
         }
         while (y > x);

         printf("%i-%i=\n", x, y);
         //printf("%i\n", y);
         sleep(1);
         int z = get_int("Ответ:\n");
         if (x - y == z)
            {
               sleep(1);
               printf("Правильно!\n");
               score = score + 2;
               sleep(1);
               break;
            }
         else
            {
               int z_correct = x - y;
               sleep(1);
               printf("Неправильно. Получилось %i\n", z_correct);
               score = score - 1;
               sleep(2);
               printf("Попробуй еще\n");
               sleep(1);
            }
      }

      if (choice == 5) //Наташа
         {
            int age = rand() % (15 - 1 + 1) + 1;
            //int age_x = 0;
            //do
              // {
            int age_x = rand() % (5 - 1 + 1) + 1;
              // }
           // while (age_x < age);
            int age_x2 = 0;
            do
               {
               age_x2 = rand() % (10 - 1 + 1) + 1;
               }
            while (age_x2 <= age_x);

            printf("Наташе %i %s, сколько ей будет через %i %s? А через %i %s?\n", age, vozrast(age), age_x, vozrast(age_x), age_x2, vozrast(age_x2));

            int correct_age_x = age + age_x;
            int correct_age_x2 = age + age_x2;

            int answer_age_x = get_int ("Через %i %s: ", age_x, vozrast(age_x));
            int answer_age_x2 = get_int ("Через %i %s: ", age_x2, vozrast(age_x2));

            if ((answer_age_x == correct_age_x) && (answer_age_x2 == correct_age_x2))
               {
                  sleep(1);
                  printf("Правильно!\n");
                  score = score + 10;
                  sleep(1);
                  break;
               }
            else
               {
                  sleep(1);
                  printf("Неправильно. Получилось %i и %i\n", correct_age_x, correct_age_x2);
                  score = score - 5;
                  sleep(2);
                  printf("Попробуй еще\n");
                  sleep(1);
               }

         }

      if (choice == 6) //кошки
         {
            //На крыше сидело 10 кошек: 7 черных и 3 белых. На сколько черных кошек больше, чем серых?
            int cats_total = rand() % (19 - 11 + 1) + 11;
            int cats_black = 0;
            do
            {
            cats_black = rand() % (18 - 2 + 1) + 2;
            }
            while (cats_black > ((cats_total / 2) - 1));
            int cats_white = cats_total - cats_black;

            printf("На крыше сидело %i кошек: %i черных и %i белых.\n", cats_total, cats_black, cats_white);
            sleep(1);
            int cats_answer = get_int("Насколько белых кошек больше, чем черных?\nНа ");
            int cats_correct = cats_white - cats_black;
            if (cats_answer == cats_correct)
               {
                  sleep(1);
                  printf("Правильно!\n");
                  score = score + 5;
                  sleep(1);
                  break;
               }
            else
               {
                  sleep(1);
                  printf("Неправильно. Белых больше на %i\n", cats_correct);
                  score = score - 2;
                  sleep(2);
                  printf("Попробуй еще\n");
                  sleep(1);
               }

         }

      if (choice == 7) //Девочки и конфеты
         {
            //На столе в вазе лежало 25 ягод. Марина съела 4 ягоды, Алиса съела 6 ягод, Мила съела 3 ягоды, а остальные ягоды доела Катя. Сколько ягод съели Марина и Алиса? Мила и Катя? Сколько ягод съела Катя?
            int candy_total = rand() % (40 - 18 + 1) + 18;
            int candy_girl1 = rand() % (10 - 2 + 1) + 2;
            int candy_girl2 = rand() % (10 - 2 + 1) + 2;
            int candy_girl3 = candy_total - candy_girl1 - candy_girl2;
            string girl1 = girl_name(rand() % (12 - 0 + 1) + 0);
            string girl2;
            do
            {
               girl2 = girl_name(rand() % (12 - 0 + 1) + 0);
            }
            while (girl2 == girl1);
            string girl3;
            do
            {
               girl3 = girl_name(rand() % (12 - 0 + 1) + 0);
            }
            while (girl3 == girl1 || girl3 == girl2);

            //printf("%i, %i %s, %i %s, %i %s\n", candy_total, candy_girl1, girl1, candy_girl2, girl2, candy_girl3, girl3);
            printf("На столе в вазе лежало %i %s.\n", candy_total, konfeti(candy_total));
            sleep(1);
            printf("%s съела %i %s, %s съела %i %s, а остальные конфеты доела %s.\n", girl1, candy_girl1, konfeti(candy_girl1), girl2, candy_girl2, konfeti(candy_girl2), girl3);
            sleep(1);
            int candy_answer = get_int("Сколько конфет съели %s и %s?\n", girl1, girl3);
            int candy_correct = candy_girl1 + candy_girl3;
            if (candy_answer == candy_correct)
               {
                  sleep(1);
                  printf("Правильно!\n");
                  score = score + 5;
                  sleep(1);
                  break;
               }
            else
               {
                  sleep(1);
                  printf("Неправильно. Они съели %i %s.\n", candy_correct, konfeti(candy_correct));
                  score = score - 2;
                  sleep(2);
                  printf("Попробуй еще\n");
                  sleep(1);
               }

         }

      if (choice == 8) //У Тани 3 куклы, а у Дины – на 4 больше. Сколько кукол у Дины? На сколько кукол у Тани меньше?
         {
            int dolls_girl1 = rand() % (10 - 2 + 1) + 2;
            int dolls_girl2 = rand() % (20 - 10 + 1) + 10;
            int dolls_total = dolls_girl1 + dolls_girl2;
            int dolls_difference = dolls_girl2 - dolls_girl1;
            string girl1 = girl_name2(rand() % (12 - 0 + 1) + 0);
            string girl2;
            do
            {
               girl2 = girl_name2(rand() % (12 - 0 + 1) + 0);
            }
            while (girl2 == girl1);
            printf("У %s %i %s, а у %s – на %i больше.\n", girl1, dolls_girl1, kukli(dolls_girl1), girl2, dolls_difference);
            sleep(1);
            int dolls_answer = get_int("Сколько %s у %s?\n", kukli(dolls_girl2), girl2);
            sleep(1);
            int dolls_answer2 = get_int("Сколько %s у девочек вместе?\n", kukli(dolls_total));

            if ((dolls_answer == dolls_girl2) && (dolls_answer2 == dolls_total))
               {
                  sleep(1);
                  printf("Правильно!\n");
                  score = score + 10;
                  sleep(1);
                  break;
               }
            else
               {
                  sleep(1);
                  printf("Неправильно. Получилось %i и %i\n", dolls_answer, dolls_answer2);
                  score = score - 5;
                  sleep(2);
                  printf("Попробуй еще\n");
                  sleep(1);
               }


         }

      if (choice == 0) //exit

      {
         sleep(1);
         printf("До встречи!\n");
         sleep(1);
         return 0;
      }

   }

   while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8);
}
while (true);
   }



//отображение возраста
//needs checking but works for now

string vozrast(int year)
   {
      if(year % 10 == 1 && year != 11 && year != 111)
         {
         return "год"; //printf("Вам %d год", x);
         }
      else
         {
         if(year % 10 > 1 && year % 10 < 5 && year != 12 && year != 13 && year != 14)
            {
            return "года"; //printf("Вам %d года", x);
            }
         else
            {
            if(year % 10 > 4 || (year % 100 == 0 && year >= 11 && year <= 20 && year >= 111 && year >=120))
            ;
            {
            return "лет"; //printf("Вам %d лет", x);
            }

            }

         }
   }
   //getch();}

string konfeti(int candy)
   {
      if(candy % 10 == 1 && candy != 11 && candy != 111)
         {
         return "конфета"; //printf("Вам %d год", x);
         }
      else
         {
         if(candy % 10 > 1 && candy % 10 < 5 && candy != 12 && candy != 13 && candy != 14)
            {
            return "конфеты"; //printf("Вам %d года", x);
            }
         else
            {
            if(candy % 10 > 4 || (candy % 100 == 0 && candy >= 11 && candy <= 20 && candy >= 111 && candy >=120))
            ;
            {
            return "конфет"; //printf("Вам %d лет", x);
            }

            }

         }
   }

string balli(int score)
   {
      if(score % 10 == 1 && score != 11 && score != 111)
         {
         return "балл"; //printf("Вам %d год", x);
         }
      else
         {
         if(score % 10 > 1 && score % 10 < 5 && score != 12 && score != 13 && score != 14)
            {
            return "балла"; //printf("Вам %d года", x);
            }
         else
            {
            if(score % 10 > 4 || (score % 100 == 0 && score >= 11 && score <= 20 && score >= 111 && score >=120))
            ;
            {
            return "баллов"; //printf("Вам %d лет", x);
            }

            }

         }
   }

string kukli(int dolls)
   {
      if(dolls % 10 == 1 && dolls != 11 && dolls != 111)
         {
         return "кукла"; //printf("Вам %d год", x);
         }
      else
         {
         if(dolls % 10 > 1 && dolls % 10 < 5 && dolls != 12 && dolls != 13 && dolls != 14)
            {
            return "куклы"; //printf("Вам %d года", x);
            }
         else
            {
            if(dolls % 10 > 4 || (dolls % 100 == 0 && dolls >= 11 && dolls <= 20 && dolls >= 111 && dolls >=120))
            ;
            {
            return "кукол"; //printf("Вам %d лет", x);
            }

            }

         }
   }

string girl_name(int number)
{
   string names[] = {"Мила", "Настя", "Соня", "Ксюша", "Леся", "Маша", "Варвара", "Оля", "Катя", "Лося", "Даша", "Глаша", "Кристина"};
   return names[number];
}

string girl_name2(int number)
{
   string names[] = {"Милы", "Насти", "Сони", "Ксюши", "Леси", "Машы", "Варвары", "Оли", "Кати", "Лоси", "Даши", "Глаши", "Кристины"};
   return names[number];
}