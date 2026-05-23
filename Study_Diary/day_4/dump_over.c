#include <stdio.h>

void test_stack()
{
    // 单个数组4MB
    int big_buf[1024 * 1024];
    test_stack(); // 递归叠加栈消耗
}

int main()
{
    test_stack();
    return 0;
}
