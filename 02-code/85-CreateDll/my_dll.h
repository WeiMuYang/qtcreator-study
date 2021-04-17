#ifndef MY_DLL_H
#define MY_DLL_H


#include "display_data.h"
#include "function.h"



class MyDll
{

public:
    MyDll();

    Function *m_pfun_function;
    DisplayData *m_pdisplay_display;

};

#endif // MY_DLL_H
