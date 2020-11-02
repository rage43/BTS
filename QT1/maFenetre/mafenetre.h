#ifndef MAFENETRE_H
#define MAFENETRE_H
#include <QtWidgets>
#include <QWidget>

class maFenetre : public QWidget
{
    Q_OBJECT

private :
    QLabel * message;
    QLineEdit * saisir;
    QPushButton * valider;
public slots:
 void f_valider();
public:
    maFenetre(QWidget *parent = nullptr);
    ~maFenetre();

};
#endif // MAFENETRE_H
