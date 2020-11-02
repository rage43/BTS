#ifndef TRAMEGPS_H
#define TRAMEGPS_H
#include <QtWidgets>
#include <QWidget>

class trameGps : public QWidget
{
    Q_OBJECT
private:
    QLabel *trameLabel;
    QLabel *titleLabel;
    QLineEdit *trameLine;
    QPushButton *getPushButton;
    QLabel *logitudeLabel;
    QLabel *altitudeLabel;
    QLabel *latitudeLabel;
    QLabel * nbrSateliteLabel;
    QLineEdit *logitudeLine;
    QLineEdit *altitudeLine;
    QLineEdit *latitudeLine;
    QLineEdit * nbrSateliteLine;
    QGridLayout* layGeneral;
    QPushButton *save;


public slots:
    void getTrameLine();
    void getData();
    void saveData();

public:
    trameGps(QWidget *parent = nullptr);
    void traiterTrame(QString trame);
    ~trameGps();
};
#endif // TRAMEGPS_H
