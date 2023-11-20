#include "common.h"

const QChar separator(';');

QString& operator<< (QString& m, const QString& s)
{
    m += s;
    m.append(separator);
    return m;
}

QString& operator<<(QString& os, const double& number)
{
    os << QString().setNum(number);

    return os;
}

QByteArray& operator>>(QByteArray& arr, double& number)
{
	int p = arr.indexOf(separator);

	if (p > 0)
	{
		int index = arr.left(p).indexOf("-");
		number = arr.left(p).left(index).toDouble();
		arr = arr.right(arr.length() - p - 1);
	}

	return arr;
}

