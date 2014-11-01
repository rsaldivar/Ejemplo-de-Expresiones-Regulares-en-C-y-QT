#include "mainwindow.h"
#include "ui_mainwindow.h"

char enie=164;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{   //HABILITAMOS TODO DENUEVO, Y LES QUITAMOS PALOMITAS,
    ui->checkBox_alfa->setDisabled(FALSE);
    ui->checkBox_extr->setDisabled(FALSE);
    ui->checkBox_inic->setDisabled(FALSE);
    ui->checkBox_matr->setDisabled(FALSE);
    ui->checkBox_ptof->setDisabled(FALSE);

    ui->checkBox_alfa->setChecked(FALSE);
    ui->checkBox_extr->setChecked(FALSE);
    ui->checkBox_inic->setChecked(FALSE);
    ui->checkBox_matr->setChecked(FALSE);
    ui->checkBox_ptof->setChecked(FALSE);

    QString cadena_lineEdit = ui->lineEdit->text();
    QString valido;
    valido="        INVALIDO";

    QImage valida("/home/artser/Downloads/Correcto.png");
    QImage invalida("/home/artser/Downloads/incorrecto.png");

    QByteArray axiliar = cadena_lineEdit.toLatin1();
    char *cadena_entrada = axiliar.data();  //GUARDAMOS STRING EN PUNTERO


    char cadena[200];
    for(int i = 0; i < 200 ; i++)cadena[i] ='\0';
    for(int i = 0; i < 200 ; i++){                   //PASAMOS DE PUNTERO A ARREGLO sin NULL
        if( cadena_entrada[i] == 0 )break;
        else cadena[i]=cadena_entrada[i];
    }



    if( 1 == comprobar_alfabeto    ( cadena )){
      ui->checkBox_alfa->setChecked(TRUE);
      ui->label->setPixmap(QPixmap::fromImage(invalida));
      ui->label_2->setScaledContents(true);
    }else//ESTADO A
        if( 1 == comprobar_iniciales   ( cadena )){
            ui->checkBox_inic->setChecked(TRUE);
            ui->label->setPixmap(QPixmap::fromImage(invalida));
            ui->label_2->setScaledContents(true);
        }else//ESTADO B
            if( 1 == comprobar_matricula   ( cadena )){
                ui->checkBox_matr->setChecked(TRUE);
                ui->label->setPixmap(QPixmap::fromImage(invalida));
                ui->label_2->setScaledContents(true);
            }else//ESTADO C
                if( 1 == comprobar_intermedio_1( cadena )){
                    ui->checkBox_extr->setChecked(TRUE);
                    ui->label->setPixmap(QPixmap::fromImage(invalida));
                    ui->label_2->setScaledContents(true);
                }else//ESTADO D
                 if( 1 == comprobar_final       ( cadena )){
                     ui->checkBox_ptof->setChecked(TRUE);
                     ui->label->setPixmap(QPixmap::fromImage(invalida));
                     ui->label_2->setScaledContents(true);
                 }else//ESTADO E
                    if( 1 == comprobar_intermedio_2( cadena )){
                        ui->checkBox_extr->setChecked(TRUE);
                        ui->label->setPixmap(QPixmap::fromImage(invalida));
                        ui->label_2->setScaledContents(true);
                    } else{//ESTADO FINAL
                        valido = "        VALIDO";
                        ui->label->setPixmap(QPixmap::fromImage(valida));
                        ui->label_2->setScaledContents(true);
                   }


    ui->statusBar->showMessage( cadena + valido );

}

int MainWindow::comprobar_alfabeto(char *cadena){
    int bandera_intermedio = 1;
    int i = 0;
      for( i = 0 ; i < 200 ; i++){
        if( cadena[i]== 'a' || cadena[i]== 'b' || cadena[i]== 'c' || cadena[i]== 'd' || cadena[i]== 'e' || cadena[i]== 'f' || cadena[i]== 'g' || cadena[i]== 'h' || cadena[i]== 'i' || cadena[i]== 'j' || cadena[i]== 'k' || cadena[i]== 'l' || cadena[i]== 'm' || cadena[i]== 'n' || cadena[i]==enie || cadena[i]== 'o' || cadena[i]== 'p' || cadena[i]== 'q' || cadena[i]== 'r' || cadena[i]== 's' || cadena[i]== 't' || cadena[i]== 'u' || cadena[i]== 'v' || cadena[i]== 'w' || cadena[i]== 'x' || cadena[i]== 'y' || cadena[i]== 'z' || cadena[i]== '0' || cadena[i]== '1' || cadena[i]== '2' || cadena[i]== '3' ||  cadena[i] == '4' || cadena[i]== '5' || cadena[i]== '6' || cadena[i]== '7' || cadena[i]== '8' || cadena[i]== '9' || cadena[i] == ' ' || cadena[i]=='\n' || cadena[i]=='.'|| cadena[i]=='\0' )
            bandera_intermedio = 0;
        else
        {
            bandera_intermedio = 1;
            break;
        }
      }
 return bandera_intermedio;
}

int MainWindow::comprobar_iniciales(char *cadena_entrada){
    int bandera_iniciales = 1;
      for(int i = 0 ; i < 4 ; i++){
       if( cadena_entrada[i] == 'r' && cadena_entrada[i+1] == 'c' && cadena_entrada[i+2] == 's' && cadena_entrada[i+3] == 'a' )
       bandera_iniciales = 0;
      }
      return bandera_iniciales;
}

int MainWindow::comprobar_matricula(char *cadena_entrada ){
    int bandera_matricula = 1;
    for( int  i = 0 ; i < 200 ; i++){
           if(  cadena_entrada[i] == '1' && cadena_entrada[i+1]=='3' && cadena_entrada[i+2]=='9'&& cadena_entrada[i+3]=='5' && cadena_entrada[i+4]=='0' && cadena_entrada[i+5]=='0'&& cadena_entrada[i+6]=='2' )
           {bandera_matricula = 0;
             setInicioMatricula(i);
             setFinalMatricula(i+6);
            }
      }
      return bandera_matricula;
}

int MainWindow::comprobar_intermedio_1(char *cadena ){
    int bandera_intermedio = 1;
    //Comparamos desde inicio hasta el que inicie la matricula
    for( int i = 0 ; i < getInicioMatricula() ; i++){
    if( cadena[i]== 'a' || cadena[i]== 'b' || cadena[i]== 'c' || cadena[i]== 'd' || cadena[i]== 'e' || cadena[i]== 'f' || cadena[i]== 'g' || cadena[i]== 'h' || cadena[i]== 'i' || cadena[i]== 'j' || cadena[i]== 'k' || cadena[i]== 'l' || cadena[i]== 'm' || cadena[i]== 'n' || cadena[i]==enie || cadena[i]== 'o' || cadena[i]== 'p' || cadena[i]== 'q' || cadena[i]== 'r' || cadena[i]== 's' || cadena[i]== 't' || cadena[i]== 'u' || cadena[i]== 'v' || cadena[i]== 'w' || cadena[i]== 'x' || cadena[i]== 'y' || cadena[i]== 'z' || cadena[i]== '0' || cadena[i]== '1' || cadena[i]== '2' || cadena[i]== '3' ||  cadena[i] == '4' || cadena[i]== '5' || cadena[i]== '6' || cadena[i]== '7' || cadena[i]== '8' || cadena[i]== '9' || cadena[i] == ' ' || cadena[i]=='\n' || cadena[i]=='\0' )
         bandera_intermedio = 0;
         else{
              bandera_intermedio = 1;
              break;
             }
    }
    return bandera_intermedio;
}

int MainWindow::comprobar_final(char *cadena_entrada ){
    int bandera_final = 1;
      int i = 0, posicion_final = 0 ;

      for( i = 0 ; i < 200 ; i++){
        if( cadena_entrada[i]== '.' && cadena_entrada[i+1] == '\0')posicion_final = i;
      }
      if( cadena_entrada[posicion_final] == '.'){
          bandera_final = 0;
          setPosicionPunto( posicion_final); //Le colocamos la posicion final
      }
      return bandera_final;
}

int MainWindow::comprobar_intermedio_2(char *cadena ){

    int bandera_intermedio = 1;
      for( int i = 0 ; i < getPosicionPunto() ; i++){
      if( cadena[i]== 'a' || cadena[i]== 'b' || cadena[i]== 'c' || cadena[i]== 'd' || cadena[i]== 'e' || cadena[i]== 'f' || cadena[i]== 'g' || cadena[i]== 'h' || cadena[i]== 'i' || cadena[i]== 'j' || cadena[i]== 'k' || cadena[i]== 'l' || cadena[i]== 'm' || cadena[i]== 'n' || cadena[i]==enie || cadena[i]== 'o' || cadena[i]== 'p' || cadena[i]== 'q' || cadena[i]== 'r' || cadena[i]== 's' || cadena[i]== 't' || cadena[i]== 'u' || cadena[i]== 'v' || cadena[i]== 'w' || cadena[i]== 'x' || cadena[i]== 'y' || cadena[i]== 'z' || cadena[i]== '0' || cadena[i]== '1' || cadena[i]== '2' || cadena[i]== '3' ||  cadena[i] == '4' || cadena[i]== '5' || cadena[i]== '6' || cadena[i]== '7' || cadena[i]== '8' || cadena[i]== '9' || cadena[i] == ' ' || cadena[i]=='\n' || cadena[i]=='\0' )
           bandera_intermedio = 0;
           else{
                bandera_intermedio = 1;
                break;
               }
      }
      return bandera_intermedio;
}

