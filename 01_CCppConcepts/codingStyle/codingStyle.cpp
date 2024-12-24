#include <iostream>

using namespace std;

struct rectangle
{
    int l;
    int b;
};

void init(struct rectangle *r, int l, int b)
{
    r->l = l;
    r->b = b;
}

int area(struct rectangle *r)
{
    return r->l * r->b;
}

void changeLength(struct rectangle *r, int newlen)
{
    r->l = newlen;
}

int main()
{
    struct rectangle r;

    init(&r, 10, 20);
    int opt = area(&r);

    cout << "Area of Rectangle: " << opt << endl;

    changeLength(&r, 30);

    int opt2 = area(&r);
    cout << "New Area of Rectangle: " << opt2 << endl;

    return 0;
}