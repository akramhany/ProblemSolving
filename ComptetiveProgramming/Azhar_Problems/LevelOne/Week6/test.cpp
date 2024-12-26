#include <iostream> 

using namespace std;

class student
{
    int marks;
    public:
        student() {}  
        student(int i)  
        {
            marks = i;
        }
};

int main()
{
    student s1(100);   
    student s2();     
    student s3 = 100; 
    return 0;
}