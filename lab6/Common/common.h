#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QByteArray>

enum messages
{
    CALCULATE_DETERMINANT = 1,
    TRANSPORE_MATRIX,
    CALCULATE_RANG,
    OUTPUT_MATRIX,
};

enum type {
    DOUBLE = 0,
    COMPLEX,
    RATIONAL,
};

extern const QChar separator;
QString& operator<< (QString&,const QString&);

QString& operator<< (QString&, const double&);

QByteArray& operator>> (QByteArray&, double&);

#endif // COMMON_H
