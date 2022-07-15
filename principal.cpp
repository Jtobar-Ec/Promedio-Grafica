#include "principal.h"
#include "ui_principal.h"


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);

}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    QPen pincel2;
    pincel2.setWidth(5);
    pincel2.setColor(Qt::red);
    pincel2.setJoinStyle(Qt::MiterJoin);

    QPen pincel3;
    pincel3.setWidth(5);
    pincel3.setColor(Qt::red);
    pincel3.setJoinStyle(Qt::MiterJoin);

    QPen pinceleje;
    pinceleje.setWidth(5);
    pinceleje.setColor(Qt::black);
    pinceleje.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setPen(pincel2);
    painter.setPen(pincel3);

    //Obtener datos para la primera barra
        int nota1= ui->intNota1->value();
        int altoN1= this->getAlto(nota1);
        int incYN1= this->incY(altoN1);

    //Obtener datos para la segunda barra

        int nota2= ui->intNota2->value();
        int altoN2= this->getAlto(nota2);
        int incYN2= this->incY(altoN2);

     //Obtener datos para la tercera barra

        int nota3= ui->intNota3->value();
        int altoN3= this->getAlto(nota3);
        int incYN3= this->incY(altoN3);



    // Dibujar primera barra
    painter.drawRect(x+50, y+50+incYN1,100,altoN1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(219, 120, 47);
    // Crear otro objeto color para el borde
    QColor colorBorde(0, 0, 0);

    pincel.setColor(colorBorde);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno);
    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Crear un objeto color para el relleno
    QColor colorRelleno2(51, 82, 208);
    // Crear otro objeto color para el borde
    QColor colorBorde2(0, 0, 0);

    pincel2.setColor(colorBorde2);
    painter.setPen(pincel2);
    painter.setBrush(colorRelleno2);
    // Cambiar el color del pincel 2
    pincel2.setColor(colorBorde2);
    // Dibujar segunda barra
    painter.drawRect(x+170, y+50+incYN2, 100, altoN2);


    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(255, 250, 205);
    QColor cBordeBarra3(0, 0, 0);

    // Estableciendo colores al puncel y al painter
    pincel3.setColor(cBordeBarra3);
    painter.setPen(pincel3);
    painter.setBrush(cRellenoBarra3);
    // Cambiar el color del pincel

    // Dibujar tercera barra
    painter.drawRect(x+290,y+50+incYN3,100,altoN3);


//--------------------------------------------------------------------------
    //Dibujar Eje
    //Y
    painter.setPen(pinceleje);
    painter.drawLine(x+25,y+25,25,550);
    //X
    painter.drawLine(x+30,y+460,450,460);
    pinceleje.setColor(Qt::black);

    //Calcular promedio

   int N1= ui->intNota1->value();
   int N2= ui->intNota2->value();
   int N3= ui->intNota3->value();

   double prom= (N1+N2+N3)/3;

    ui->outCantidad->setNum(prom);


    int pars=500;
    int pers=0;

    for (int i = 0; i <=10; i++) {
        pars=pars-40;
        qDebug()<<pers<<""<<pars;
        painter.drawText(5,pars,QString::number(pers));
        pers=pers+10;
    }
    painter.drawText(100,480,"N1");
    painter.drawText(220,480,"N2");
    painter.drawText(330,480,"N3");




    painter.drawLine(800,450-prom*4,0,450-prom*4);

}

int Principal::getAlto(int valor)
{
    return 4 * valor;
}

int Principal::incY(int alto)
{
    return 400 - alto;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}
void Principal::on_pushButton_clicked(bool checked)
{

}

void Principal::on_intNota1_valueChanged(int arg1)
{
    dibujar();
}


void Principal::on_intNota2_valueChanged(int arg2)
{
    dibujar();
}

void Principal::on_intNota3_valueChanged(int arg3)
{
    dibujar();
}

void Principal::on_Prome_clicked()
{
}
void Principal::on_Cantidad_linkActivated(const QString &link)
{
}
