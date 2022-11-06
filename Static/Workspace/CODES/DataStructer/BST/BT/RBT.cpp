#include <cstdio>
using namespace std;
template <class T>
class RedBlackTree
{
public:
   RedBlackTree(void)
   {
      root = nullptr;
   }
   void insert(T x, long long num = 1)
   {
      if (root == nullptr)
      {
         root = new node(x, nullptr, num, BLACK);
         return;
      }
      node *nw = root;
      while (1)
      {
         if (x == nw->data)
         {
            nw->num += num;
            nw->weight += num;
            while (nw)
            {
               nw = nw->fa;
               nw->weight += num;
            }
            return;
         }
         if (x < nw->data)
         {
            if (nw->son[0] == nullptr)
            {
               nw->son[0] = new node(x, nw, num);
               InsertFixup(nw->son[0]);
               return;
            }
            nw = nw->son[0];
         }
         else
         {
            if (nw->son[1] == nullptr)
            {
               nw->son[0] = new node(x, nw, num);
               InsertFixup(nw->son[0]);
               return;
            }
            nw = nw->son[1];
         }
      }
   }
   bool remove(T x, bool state, long long num = 1)
   {
      node *nw = root;
      while (nw)
      {
         if (nw->data == x)
         {
            if (state == REMOVE)
            {
               nw->num -= num;
               if (nw->num < 0)
               {
                  removeit(nw);
                  return UNSUCCESS;
               }
               else
               {
                  removeit(nw);
                  return SUCCESS;
               }
            }
            else
            {
               removeit(nw);
               return SUCCESS;
            }
         }
         if (x < nw->data)
         {
            nw = nw->son[0];
            continue;
         }
         else
         {
            nw = nw->son[1];
            continue;
         }
      }
      return UNSUCCESS;
   }

protected:
   struct node;
   struct node
   {
      node(T dat, node *f = nullptr, long long n = 1, bool color = RED) : data(dat), fa(f), num(n), colour(color) { son[0] = son[1] = nullptr; }
      T data;
      node *fa;
      long long num;
      bool colour;
      long long weight;
      node *son[2];
      void show(int x)
      {
         for (int i = 1; i <= x; ++i)
         {
            printf("|----");
         }
         printf("%3d %3lld %1d\n", data, num, colour ? 1 : 0);
         if (son[0] != nullptr)
         {
            son[0]->show(x + 1);
         }
         if (son[1] != nullptr)
         {
            son[1]->show(x + 1);
         }
      }
      bool get(void)
      {
         if (!fa)
         {
            return LEFT;
         }
         if (this == fa->son[LEFT])
         {
            return LEFT;
         }
         else
         {
            return RIGHT;
         }
      }
   };

private:
   node *precursor(node *nw)
   {
      if (nw->son[LEFT])
      {
         nw = nw->son[LEFT];
         while (nw->son[RIGHT])
         {
            nw = nw->son[RIGHT];
         }
         return nw;
      }
      else
      {
         while (nw->fa && nw->get() == LEFT)
         {
            nw = nw->fa;
         }
         return nw->fa;
      }
   }
   node *successor(node *nw)
   {
      if (nw->son[RIGHT])
      {
         nw = nw->son[RIGHT];
         while (nw->son[LEFT])
         {
            nw = nw->son[LEFT];
         }
         return nw;
      }
      else
      {
         while (nw->fa && nw->get() == RIGHT)
         {
            nw = nw->fa;
         }
         return nw->fa;
      }
   }
   void removeit(node *nw)
   {
      bool colour, leaf;
      if (nw == root)
      {
         root = nullptr;
         return;
      }
      if (!nw->son[LEFT] || !nw->son[RIGHT])
      {
         if (nw->son[LEFT])
         {
            nw->fa->son[nw->get()] = nw->son[LEFT];
            colour = nw->colour;
            nw->son[LEFT]->fa = nw->fa;
            nw = nw->son[LEFT];
            leaf = false;
         }
         else if (nw->son[RIGHT])
         {
            nw->fa->son[nw->get()] = nw->son[RIGHT];
            colour = nw->colour;
            nw->son[RIGHT]->fa = nw->fa;
            nw = nw->son[RIGHT];
            leaf = false;
         }
         else
         {
            colour = nw->colour;
            nw->fa->son[nw->get()] = nullptr;
            nw = nw->fa;
            leaf = true;
         }
         if (colour == RED)
         {
            return;
         }
         else
         {
            DeleteFixup(nw, leaf);
         }
      }
      else
      {
         nw->data = successor(nw)->data;
         nw = successor(nw);
         colour = nw->colour;
         nw->fa->son[nw->get()] = nw->son[RIGHT];
         if (nw->son[RIGHT] != nullptr)
         {
            nw->son[RIGHT]->fa = nw->fa;
            leaf = false;
         }
         else
         {
            leaf = true;
         }
         if (colour == RED)
         {
            return;
         }
         else
         {
            DeleteFixup(nw, leaf);
         }
      }
   }
   void DeleteFixup(node *nw, bool leaf)
   {
      while (1)
      {
         if (nw == root)
         {
            return;
         }
         if (nw->colour == RED && leaf == false)
         {
            nw->colour = BLACK;
            return;
         }
         if (leaf)
         {
            if (nw->colour == BLACK)
            {
               leaf = false;
            }
            else
            {
            }
         }
      }
   }
   void pushup(node *nw)
   {
      nw->weight = nw->num;
      if (nw->son[0] != nullptr)
      {
         nw->weight += nw->son[0]->weight;
      }
      if (nw->son[1] != nullptr)
      {
         nw->weight += nw->son[1]->weight;
      }
   }
   void rotate(node *nw, bool state)
   {
      node *u = nw->son[state ^ 1];
      nw->son[state ^ 1] = u->son[state];
      u->son[state] = nw;
      pushup(nw);
      pushup(u);
      nw = u;
   }
   void InsertFixup(node *nw)
   {
      while (1)
      {
         if (nw == root || nw->colour == BLACK || nw->fa->colour == BLACK)
         {
            return;
         }
         if (nw->fa->fa->son[nw->fa->get() ^ 1]->colour == RED)
         {
            nw->fa->fa->son[nw->fa->get() ^ 1]->colour = BLACK;
            nw->fa->colour = BLACK;
            if (nw->fa->fa == root)
            {
               return;
            }
            else
            {
               nw->fa->fa->colour = RED;
               nw = nw->fa->fa;
               continue;
            }
         }
         else
         {
            if (nw->get() != nw->fa->get())
            {
               nw = nw->fa;
               rotate(nw, nw->get());
               continue;
            }
            else
            {
               nw->fa->colour = BLACK;
               nw->fa->fa->colour = BLACK;
               rotate(nw->fa->fa, nw->get() ^ 1);
               return;
            }
         }
      }
   }

protected:
   const static bool RED = true;
   const static bool BLACK = false;
   const static bool REMOVE = true;
   const static bool ERASE = false;
   const static bool SUCCESS = true;
   const static bool UNSUCCESS = false;
   const static bool LEFT = false;
   const static bool RIGHT = true;

protected:
   node *root;
};
template <class T>
class RBT : public RedBlackTree<T>
{
public:
   void show(void)
   {
      this->root->show(0);
   }
};
int main()
{
   RBT<int> tree;
   int n;
   scanf("%d", &n);
   int x;
   while (n--)
   {
      scanf("%d", &x);
      tree.insert(x, 1ll);
   }
   tree.show();
   return 0;
}