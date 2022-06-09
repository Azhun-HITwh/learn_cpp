#include <iostream>

using namespace std;

class Line
{
    public:
        int getlength(void);
        Line(int len);
        Line(const Line &obj);
        ~Line();

    private:
        int *ptr;
};

Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

int Line::getlength()
{
    return *ptr;
}

Line::~Line()
{
    cout << "释放内存" << endl;
    delete ptr;
}

void display(Line obj)
{
    cout << "line 大小 : " << obj.getlength() << endl;
}

int main(int argc, char const *argv[])
{
    Line line1(10);
    Line line2 = line1;

    display(line1);
    display(line2);
    
    return 0;
}
