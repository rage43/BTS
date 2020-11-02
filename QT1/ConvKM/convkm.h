#ifndef CONVKM_H
#define CONVKM_H
#include <QtWidgets>
#include <QWidget>

class ConvKM : public QWidget
{
    Q_OBJECT

public slots:
    void convertirKmMilles();
    void convertirMillesKm();
    void desactiverMilles();
    void desactiverKm();
private :
    QLineEdit * lineEditKm1;
    QLineEdit * lineEditKm2;
    QLineEdit * lineEditMilles1;
    QLineEdit * lineEditMilles2;
    QLabel * labelTitre;
    QLabel * labelKm;
    QLabel * labelMilles;
    QLabel * labelConv1;
    QLabel * labelConv2;
    QRadioButton * radioKmM;
    QRadioButton * radioMKM;
    QGridLayout* layGeneral;
public:
    ConvKM(QWidget *parent = nullptr);
    ~ConvKM();
};
#endif // CONVKM_H
