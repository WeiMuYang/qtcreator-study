#include "display_data.h"

DisplayData::DisplayData()
{

}

void DisplayData::display()
{
    qDebug() << m_n_result;
}

void DisplayData::setResult(int r)
{
    m_n_result = r;
}
