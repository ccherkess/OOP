#ifndef COMMON_H
#define COMMON_H

#include <QString>

enum messages
{
    CALCULATE_DETERMINANT = 1,
    TRANSPORE_MATRIX,
    CALCULATE_RANG,
    OUTPUT_MATRIX,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

#endif // COMMON_H
