#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    int comprobar_alfabeto(char *cadena);
    int comprobar_iniciales(char *cadena_entrada );
    int comprobar_matricula(char *cadena_entrada );
    int comprobar_intermedio_1(char *cadena  );
    int comprobar_intermedio_2(char *cadena );
    int comprobar_final(char *cadena_entrada );

    void setInicioMatricula(int inicio_matricula){ this->inicio_matricula = inicio_matricula; }
    void setFinalMatricula(int final_matricula){ this->final_matricula = final_matricula; }
    void setPosicionPunto(int posicion_punto){ this->posicion_punto = posicion_punto;}
    int getInicioMatricula(){return inicio_matricula;}
    int getFinalMatricula(){return final_matricula;}
    int getPosicionPunto(){return posicion_punto; }

    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    int inicio_matricula;
    int final_matricula;
    int posicion_punto;

};

#endif // MAINWINDOW_H
