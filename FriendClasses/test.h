#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

class Test
{
    public:
        int x;
        int y;
        int *p;
        Test(const Test &);
        Test(int, int, int);
        ~Test();
};
#endif // TEST_H_INCLUDED
