#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    /* Intializes random number generator */
   srand(time(NULL));


   //greet and get name

   string name = get_string("Как тебя зовут?\n");

   printf("Привет, %s!\n", name);

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

   do
   {

   int choice = get_int("Выбери задачу:\n\n1.Маша пошла в магазин\n2.Саша пошел в магазин\n3.Примеры на сложение\n4.Примеры на вычитание\n\n0.Выход\n");

   do
      {

      //first question

      if (choice == 1)
      {

         int spent;

         do
         {
         spent = get_int("Мама отправила Машу в магазин за покупками, дала 100 руб. и попросила принести не меньше 30 руб. сдачи. Сколько рублей потратила Маша?\n");
         }
         while (spent > 71 || spent < 0);

         int remaining = get_int("Cколько у нее осталось?\n");

            if ((remaining+spent) == 100)
            {
               sleep(1);
               printf("Правильно!\n");
               sleep(1);
               break;
            }
            else
            {
               int correct = 100 - spent;
               sleep(1);
               printf("Неправильно. Маша потратила %i руб.\n", correct);
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
               sleep(1);
               break;
               }

               else
               {
               int r_correct = random_allowed - random_spent;
               sleep(1);
               printf("Неправильно. Саша потратил %i руб.\n", r_correct);
               sleep(3);
               printf("Попробуй еще\n");
               sleep(1);
               }
         }
      if (choice == 3)
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
               sleep(1);
               break;
            }
         else
            {
               int z_correct = x + y;
               sleep(1);
               printf("Неправильно. Получилось %i\n", z_correct);
               sleep(3);
               printf("Попробуй еще\n");
               sleep(1);
            }
      }

      if (choice == 4)
      {
         int x = rand() % (10 - 0 + 1) + 1;
         int y = x - (rand() % (9 - 0 + 1) + 1);
         printf("%i-%i=\n", x, y);
         sleep(1);
         int z = get_int("Ответ:\n");

         if (x + y == z)
            {
               sleep(1);
               printf("Правильно!\n");
               sleep(1);
               break;
            }
         else
            {
               int z_correct = x - y;
               sleep(1);
               printf("Неправильно. Получилось %i\n", z_correct);
               sleep(3);
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
      /*if (choice != 1 && choice != 2)
      {
         break;
      }*/
      }

   while (choice == 1 || choice == 2 || choice == 3 || choice == 4);
}
while (true);

}