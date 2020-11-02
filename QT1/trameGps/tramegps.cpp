#include "tramegps.h"


trameGps::trameGps(QWidget *parent)
    : QWidget(parent)
{
    trameLabel= new QLabel(this) ;
    trameLabel->setText("trame brut:");
    titleLabel= new QLabel(this);
    titleLabel->setText("Analyse de trame GPS");
    QFont fontTitre( "Arial", 20, QFont::Bold);
    QPalette pal(0x80ffff); // définition d'une couleur
    titleLabel->setAutoFillBackground(true);
    titleLabel->setPalette(pal); // affecte la couleur de font au Label
    titleLabel->setFont(fontTitre);
    titleLabel->setAlignment(Qt::AlignHCenter);
    trameLine = new QLineEdit(this);
    getPushButton = new QPushButton(this);
    getPushButton->setText("GetData");
    logitudeLabel = new QLabel(this);
    logitudeLabel->setText("Longitude:");
    altitudeLabel= new QLabel(this);
    altitudeLabel->setText("Altitude:");
    latitudeLabel= new QLabel(this);
    latitudeLabel->setText("Latitude:");
    nbrSateliteLabel= new QLabel(this);
    nbrSateliteLabel->setText("nbr satelite");
    logitudeLine = new QLineEdit(this);
    altitudeLine = new QLineEdit(this);
    latitudeLine = new QLineEdit(this);
    nbrSateliteLine = new QLineEdit(this);
    save= new QPushButton(this);
    save->setText("Sauvegarde");
    // Définir un layout, sous forme d'une grille
    layGeneral=new QGridLayout(this);
    layGeneral->addWidget(titleLabel,1,1,1,4);
    layGeneral->addWidget(trameLabel,2,1);
    layGeneral->addWidget(trameLine,2,2,1,3);
    layGeneral->addWidget(getPushButton,3,1);
    layGeneral->addWidget(logitudeLabel,4,1);
    layGeneral->addWidget(logitudeLine,4,2);
    layGeneral->addWidget(altitudeLabel,4,3);
    layGeneral->addWidget(altitudeLine,4,4);
    layGeneral->addWidget(latitudeLabel,5,1);
    layGeneral->addWidget(latitudeLine,5,2);
    layGeneral->addWidget(nbrSateliteLabel,5,3);
    layGeneral->addWidget(nbrSateliteLine,5,4);
    layGeneral->addWidget(save,6,4);
    //desactivation des champs

    logitudeLine->setEnabled(false);
    latitudeLine->setEnabled(false);
    altitudeLine->setEnabled(false);
    nbrSateliteLine->setEnabled(false);

    //signal
    connect(trameLine,SIGNAL(editingFinished()),this,SLOT(getTrameLine()));
    connect(getPushButton,SIGNAL(clicked()),this,SLOT(getData()));
    connect(save,SIGNAL(clicked()),this,SLOT(saveData()));

}
//partie 1
void trameGps::getTrameLine(){
    QString trame = trameLine->text();
    traiterTrame(trame);
}
//partie 3
void trameGps::getData(){
    QFileDialog dialog(this);
    QString nomFichier="";
    QString trame;

    dialog.setNameFilter(tr("Text files (*.txt)"));
    if( dialog.exec()== QDialog::Accepted){
        nomFichier=dialog.selectedFiles().first();



        QFile file(nomFichier);
        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::information(0,"error","imposible de trouver le fichier");
        }

        QTextStream in(&file);

        trame = in.readLine();}

    trameLine->setText(trame);
    traiterTrame(trame);



}

//partie 4
void trameGps::saveData(){
    QFile file("/home/venom/Bureau/DataTrame.csv");
    file.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream Cout(&file);
    QString trame= logitudeLine->text()+";"+latitudeLine->text()+";"+altitudeLine->text()+";"+nbrSateliteLine->text();
    Cout<<trame<<endl;

    file.close();

}


//traite la trame
void trameGps::traiterTrame(QString trame){
    QString trame2;
    int degree;
    double rest;
    QStringList trameArray= trame.split(","),ptSplit;;
    int taille=trameArray.size();
    //initialization
    latitudeLine->setText("");
    logitudeLine->setText("");
    altitudeLine->setText("");
    nbrSateliteLine->setText("");
    //Boucle
    for(int i=0;i<taille;i++){
        if(trameArray[i]=='N'){
            ptSplit=trameArray[i-1].split(".");
            degree=ptSplit[0].toInt()/100;
            rest=ptSplit[0].toInt()%100;
            trame2=QString::number(degree)+"° "+QString::number(rest)+"."+ptSplit[1];
            latitudeLine->setText(trame2);


        }
        if(trameArray[i]=='E'||trameArray[i]=='W'){
            ptSplit=trameArray[i-1].split(".");
            degree=ptSplit[0].toInt()/100;
            rest=ptSplit[0].toInt()%100;
            trame2=QString::number(degree)+"° "+QString::number(rest)+"."+ptSplit[1];
            logitudeLine->setText(trame2);


        }
        if(trameArray[i]=='M'){
            altitudeLine->setText(trameArray[i-1]);
            nbrSateliteLine->setText(trameArray[i-3]);
            //sort de la boucle
            i=taille;


        }
    }



}

trameGps::~trameGps()
{
    delete trameLabel;
    delete titleLabel;
    delete trameLine;
    delete getPushButton;
    delete logitudeLabel;
    delete altitudeLabel;
    delete latitudeLabel;
    delete nbrSateliteLabel;
    delete logitudeLine;
    delete altitudeLine;
    delete latitudeLine;
    delete nbrSateliteLine;
    delete layGeneral;
    delete save;
}

