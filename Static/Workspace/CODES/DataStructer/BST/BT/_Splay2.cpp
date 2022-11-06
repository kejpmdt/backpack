#include <cstdio>
#include <iostream>
using namespace std;
template <class T>
class Splay
{
public:
   void show(void)
   {
      if (root == nullptr)
      {
         return;
      }
      root->show(0);
   }
   class node;
   T *fronter(T *x)
   {
      findbynum(x);
      findbyrank(rank() - 1);
      return root->data;
   }
   T *nexter(T *x)
   {
      findbynum(x);
      findbyrank(rank() + root->num);
      return root->data;
   }
   Splay *split(node *x)
   {
      Splay *newsplay = new Splay<T>;
      newsplay->root = x;
      if (x->fa)
      {
         x->fa->ch[x->relation()] = nullptr;
      }
      x->fa = nullptr;
      return newsplay;
   }
   void add(T *x, int num)
   {
      if (root == nullptr)
      {
         root = new node(x, num);
         return;
      }
      us = root;
      while (us)
      {
         if (*us->data == *x)
         {
            us->add(num);
            break;
         }
         if (*us->data < *x)
         {
            if (us->ch[1] == nullptr)
            {
               us->ch[1] = new node(x, num);
               us->ch[1]->fa = us;
               us = us->ch[1];
               break;
            }
            us = us->ch[1];
            continue;
         }
         else
         {
            if (us->ch[0] == nullptr)
            {
               us->ch[0] = new node(x, num);
               us->ch[0]->fa = us;
               us = us->ch[0];
               break;
            }
            us = us->ch[0];
            continue;
         }
      }
      us->splay();
      return;
   }
   node *merge(Splay *a, Splay *b)
   {
      if (!a->root)
      {
         return b->root;
      }
      if (!b->root)
      {
         return a->root;
      }
      us = a->root;
      while (us->ch[1])
      {
         us = us->ch[1];
      }
      us->splay();
      us = b->root;
      while (us->ch[1])
      {
         us = us->ch[1];
      }
      us->splay();
      if (*a->root->data > *b->root->data)
      {
         b->root->ch[1] = a->root;
         a->root->fa = b->root;
         us = a->root;
      }
      else
      {
         a->root->ch[1] = b->root;
         b->root->fa = a->root;
         us = b->root;
      }
      return us;
   }

   void rem(T *x, int num)
   {
      if (root == nullptr)
      {
         return;
      }
      findbynum(x);
      if (*root->data != *x)
      {
         return;
      }
      root->num -= num;
      if (root->num <= 0)
      {
         if (!root->ch[0] || !root->ch[1])
         {
            if (root->ch[0])
            {
               root = root->ch[0];
            }
            else
            {
               root = root->ch[1];
            }
            if (root)
            {
               root->fa = nullptr;
            }
         }
         else
         {
            Splay *a, *b;
            a = split(root->ch[0]);
            b = split(root->ch[1]);
            root = merge(a, b);
         }
      }
   }
   void findbynum(T *x)
   {
      if (root == nullptr)
      {
         return;
      }
      us = root;
      while (us)
      {
         if (*us->data == *x)
         {
            break;
         }
         if (*x < *us->data)
         {
            us = us->ch[0];
         }
         else
         {
            us = us->ch[1];
         }
      }
      if (us)
      {
         us->splay();
      }
      return;
   }
   void findbyrank(int x)
   {
      if (root == nullptr)
      {
         return;
      }
      us = root;
      while (1)
      {
         if (us->ch[0] && x <= us->ch[0]->sum)
         {
            us = us->ch[0];
            continue;
         }
         if (us->ch[0])
         {
            x -= us->ch[0]->sum;
         }
         if (x <= us->num)
         {
            us->splay();
            return;
         }
         x -= us->num;
         us = us->ch[1];
      }
   }
   int rank(void)
   {
      if (!root)
         return 0;
      if (!root->ch[0])
         return 1;
      return root->ch[0]->sum + 1;
   }
   Splay(void)
   {
      root = nullptr;
   }
   class node
   {
   public:
      void show(int x)
      {
         for (int i = 1; i <= x; ++i)
         {
            printf("|  ");
         }
         printf("%10d %3d %3d %1d %1d\n", *data, num, sum, ch[0] != nullptr, ch[1] != nullptr);
         if (ch[0])
         {
            ch[0]->show(x + 1);
         }
         if (ch[1])
         {
            ch[1]->show(x + 1);
         }
      }
      T *data;
      int num;
      inline void add(int x)
      {
         num += x;
         maintain();
      }
      inline void rotate(void)
      {
         if (fa == nullptr)
            return;
         static int r;
         r = relation();
         if (ch[r ^ 1])
         {
            ch[r ^ 1]->fa = fa;
            fa->ch[r] = ch[r ^ 1];
         }
         ch[r ^ 1] = fa;
         fa = fa->fa;
         fa->ch[ch[r ^ 1]->relation()] = this;
         ch[r ^ 1]->fa = this;
         maintain();
         ch[r ^ 1]->maintain();
      }
      void splay(node *to = nullptr)
      {
         while (fa != to)
         {
            if (fa->fa == to)
            {
               rotate();
            }
            else
            {
               if (relation() == fa->relation())
               {
                  fa->rotate();
                  rotate();
               }
               else
               {
                  rotate();
                  rotate();
               }
            }
         }
      }
      node(T *dat, int nm) : data(dat), num(nm)
      {
         ch[0] = ch[1] = fa = nullptr;
         sum = num;
      }
      node *ch[2];
      node *fa;
      int sum;

      int relation(void)
      {
         if (fa == nullptr)
         {
            cerr << "No Father\n";
            return 0;
         }
         else
            return fa->ch[1] == this;
      }

   private:
      void maintain(void)
      {
         sum = num;
         if (ch[0])
         {
            sum += ch[0]->sum;
         }
         if (ch[1])
         {
            sum += ch[1]->sum;
         }
      }
   } * root;

private:
   node *us;
};
Splay<int> *ST;
int main()
{
   ST = new Splay<int>();
   int n, opt, x;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i)
   {
      scanf("%d%d", &opt, &x);
      switch (opt)
      {
      case 1:
      {
         ST->add(&x, 1);
         break;
      }
      case 2:
      {
         ST->rem(&x, 1);
         break;
      }
      case 3:
      {
         ST->findbynum(&x);
         printf("%d\n", ST->rank());
         break;
      }
      case 4:
      {
         ST->findbyrank(x);
         printf("%d\n", *ST->root->data);
         break;
      }
      case 5:
      {
         printf("%d\n", *ST->fronter(&x));
         break;
      }
      case 6:
      {
         printf("%d\n", *ST->nexter(&x));
         break;
      }
      }
   }

   return 0;
}