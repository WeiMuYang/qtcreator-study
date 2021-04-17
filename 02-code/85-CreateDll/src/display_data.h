#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include <QDebug>


class DisplayData
{
public:
    DisplayData();

    void display();

    void setResult(int r);

private:
    int m_n_result;
};

#endif // DISPLAYDATA_H
