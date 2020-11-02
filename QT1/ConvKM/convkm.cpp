#include "convkm.h"

ConvKM::ConvKM(QWidget *parent)
    : QWidget(parent)
{
    // QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    lineEditKm1=new QLineEdit(this);
    lineEditKm2=new QLineEdit(this);
    lineEditMilles1=new QLineEdit(this);
    lineEditMilles2=new QLineEdit(this);
    labelTitre= new QLabel(this);
    labelTitre->setText("Convertisseur Kilomètres en Milles");
    QFont fontTitre( "Arial", 20, QFont::Bold);
    QPalette pal(0x80ffff); // définition d'une couleur
    labelTitre->setAutoFillBackground(true);
    labelTitre->setPalette(pal); // affecte la couleur de font au Label
    labelTitre->setFont(fontTitre);
    labelTitre->setAlignment(Qt::AlignHCenter);
    labelKm=new QLabel(this);
    labelKm->setText("Kilomètres");
    labelMilles=new QLabel(this);
    labelMilles->setText("Milles");
    labelConv1=new QLabel(this);
    labelConv1->setText("Km->Milles");
    labelConv2=new QLabel(this);
    labelConv2->setText("Km<-Milles");
    radioKmM=new QRadioButton(this);
    radioKmM->setText("Km->Milles");
    radioMKM=new QRadioButton(this);
    radioMKM->setText("Km<-Milles");
    QValidator* validator = new QDoubleValidator();
    lineEditKm1->setValidator(validator);
    lineEditKm2->setEnabled(false);
    QValidator* validator2 = new QDoubleValidator();
    lineEditMilles2->setValidator(validator2);
    lineEditMilles1->setEnabled(false);
    lineEditMilles2->setEnabled(false);
    radioKmM->setChecked(true);
    this->setWindowTitle("Convertisseur Milles Kilometres");

    // Définir un layout, sous forme d'une grille
    layGeneral = new QGridLayout(this);
    layGeneral->addWidget(labelTitre,1,1,1,4);
    layGeneral->addWidget(lineEditKm1,3,1);
    layGeneral->addWidget(lineEditKm2,4,1);
    layGeneral->addWidget(lineEditMilles1,3,3);
    layGeneral->addWidget(lineEditMilles2,4,3);
    layGeneral->addWidget(labelKm,2,1);
    layGeneral->addWidget(labelMilles,2,3);
    layGeneral->addWidget(labelConv1,3,2);
    layGeneral->addWidget(labelConv2,4,2);
    layGeneral->addWidget(radioKmM,3,4);
    layGeneral->addWidget(radioMKM,4,4);

    connect(lineEditKm1,SIGNAL(editingFinished()),this,SLOT(convertirKmMilles()));
    connect(lineEditMilles2,SIGNAL(editingFinished()),this,SLOT(convertirMillesKm()
    ));
    connect(radioKmM,SIGNAL(clicked()),this,SLOT(desactiverMilles()));
    connect(radioMKM,SIGNAL(clicked()),this,SLOT(desactiverKm()));


}

void ConvKM::convertirKmMilles()
{
QString txt =lineEditKm1->text();
double val = txt.toDouble();
val*= 0.621371;
lineEditMilles1->setText(QString::number(val));
}
void ConvKM::convertirMillesKm()
{
//compléter le code en vous inspirant de convertirKmMilles()
    QString txt =lineEditMilles2->text();
    double var = txt.toDouble();
    var/= 0.621371;
    lineEditKm2->setText(QString::number(var));

}
void ConvKM::desactiverMilles()
{

    lineEditKm1->setText("");
    lineEditMilles1->setText("");
    lineEditKm1->setEnabled(true);
    lineEditMilles2->setEnabled(false);
}
    void ConvKM::desactiverKm()
    {
    //compléter le code en vous inspirant de desactiverMilles()
        lineEditKm2->setText("");
        lineEditMilles2->setText("");
        lineEditKm2->setEnabled(false);
        lineEditKm1->setEnabled(false);
        lineEditMilles2->setEnabled(true);

    }

ConvKM::~ConvKM()
{
    delete lineEditKm1;
    delete lineEditKm2;
    delete lineEditMilles1;
    delete lineEditMilles2;
    delete labelTitre;
    delete labelKm;
    delete labelMilles;
    delete labelConv1;
    delete labelConv2;
    delete radioKmM;
    delete radioMKM;
    delete layGeneral;
}

