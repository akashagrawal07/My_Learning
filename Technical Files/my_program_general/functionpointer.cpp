#include <stdio.h> 
// A normal function with an int parameter 
// and void return type 
void fun(int a) 
{ 
    printf("Value of a is %d\n", a); 
} 
void fun1()
{
	printf("I'm in fun()1\n'");
}
void *fun2(void(fun1)(),void(*fun)(int))
{
	printf("Im in fun 2");
}
void *fun3(void(*fun12)())
{
	printf("Im in fun 2");
}
int main() 
{  
    void (*fun_ptr)(int) = fun;  // & removed 
  
   // fun_ptr(10);  // * removed 

  	//fun2(fun1,fun(11));
  	void (*t)() ;//= fun1();
  	t = fun1;
  	printf("%lu\n",t);
  	t = &fun1;
  	printf("%lu\n",t);  	
  	fun3(t);
    return 0; 
}
