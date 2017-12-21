#include <iostream>
#include <stdlib.h>
#include <time.h>
 
struct Treap
{
    Treap(int x_, int y_, Treap* left_ = 0, Treap* right_ = 0) : x(x_), y(y_), left(left_), right(right_){}
 
    static Treap* Merge(Treap* p1, Treap* p2)
    {
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->x > p2->x) std::swap(p1, p2);
        if(p1->y > p2->y)
        {
            Treap* pRight = Merge(p1->right, p2);
            return new Treap(p1->x, p1->y, p1->left, pRight);
        }
        else
        {
            Treap* pLeft = Merge(p1, p2->left);
            return new Treap(p2->x, p2->y, pLeft, p2->right);
        }
    }
 
    void Split(int key, Treap*& l, Treap*& r)
    {
        Treap* newTreap = 0;
        if(x <= key)
        {
            if(!right) r = 0;
            else right->Split(key, newTreap, r);
            l = new Treap(x, y, left, newTreap);
        }
        else
        {
            if(!left) l = 0;
            else left->Split(key, l, newTreap);
            r = new Treap(x, y, newTreap, right);
        }
    }
 
    Treap* Add(int key)
    {
        Treap* l, *r;
        Split(key, l, r);
        Treap* m = new Treap(key, rand() % int(1e6));
        return Merge(Merge(l, m), r);
    }
 
    int x, y;
    Treap* left, *right;
};
 
int main()
{
    Treap* p1 = new Treap(8,2), *p2 = new Treap(1,9), *p3 = 0, *p4 = 0;
    Treap* pn = Treap::Merge(p1, p2);
    Treap* pn1 = pn->Add(12);
    std::cout << pn1->left->right->x;
    return 0;
}
