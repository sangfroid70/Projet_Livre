#ifndef DES_H
#define DES_H

#include <QLCDNumber>
class QTimer;

class Des : public QLCDNumber
{
    Q_OBJECT
public:
    Des(uint numDigits , QWidget *parent = 0);
    ~Des();
    void stopper();

signals:

public slots:
    void refresh ();    // Lanc� par le timer pour le d�filement des chiffres al�atoires

private:
    QTimer *timer;
};

#endif // DES_H
