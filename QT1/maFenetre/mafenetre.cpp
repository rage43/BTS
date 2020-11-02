#include "mafenetre.h"

maFenetre::maFenetre(QWidget *parent)
    : QWidget(parent)
{
    message = new QLabel;
    saisir= new QLineEdit;
    valider= new QPushButton;
    message->setText("message a modifier");
    saisir->setText("Entrez du texte !");
    valider->setText("VALIDER");
    // Définir un layout vertical permettant de positionner des objets
    QVBoxLayout * vertical = new QVBoxLayout(this);
    vertical->addWidget(message);
    vertical->addWidget(saisir);
    vertical->addWidget(valider);
    // associe l'action de clicker sur un bouton à l'appel de fonction f_valider
    connect(valider, SIGNAL(clicked()), this, SLOT(f_valider()));
}

void maFenetre::f_valider()
{
    QString m;
    // Fenêtre Message
    QMessageBox::information(0, "Qtv1", "Modification du Label");
    // Récupérer le mot saisie dans le QLineEdit
    m=saisir->text();
    // Modifier le label
    message->setText(m);
}

maFenetre::~maFenetre()
{
    delete message;
    delete saisir;
    delete valider;
}

