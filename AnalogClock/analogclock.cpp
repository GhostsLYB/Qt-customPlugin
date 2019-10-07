#include "analogclock.h"
#include "ui_analogclock.h"

AnalogClock::AnalogClock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalogClock)
{
    ui->setupUi(this);
    this->resize(200,200);
    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){this->update();});
    timer->start(1000);
}

void AnalogClock::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    //钟表的三个指针
    static QPoint hourHand[3] = {QPoint(-5,10),
                                 QPoint(5,10),
                                 QPoint(0,-40)};
    static QPoint minuteHand[3] = {QPoint(-5,10),
                                   QPoint(5,10),
                                   QPoint(0,-55)};
    static QPoint secondHand[3] = {QPoint(-5,10),
                                   QPoint(5,10),
                                   QPoint(0,-70)};
    QTime currTime = QTime::currentTime();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int side = qMin(this->width(),this->height());
    painter.translate(side/2,side/2);
    painter.scale(side/200.0,side/200.0);

    //画时针
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(hourColor));
    painter.rotate(30.0*(currTime.hour()+ currTime.minute()/60.0));
    painter.drawConvexPolygon(hourHand,3);
    painter.restore();

    //画小时刻度
    painter.save();
    QPen pen;
    pen.setWidth(hourWidth);
    pen.setColor(hourColor);
    painter.setPen(pen);
    for(int i = 1; i <= 12; i++)
    {
        painter.rotate(30);
        painter.drawLine(0,-90,0,-84);
        painter.drawText(QRect(-4,-82,12,12),QString("%1").arg(i));

    }
    painter.restore();


    //画分针
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(minuteColor));
    painter.rotate(6*(currTime.minute()+currTime.second()/60.0));
    painter.drawConvexPolygon(minuteHand,3);
    painter.restore();
    //画分钟刻度
    pen.setWidth(minuteWidth);
    pen.setColor(minuteColor);
    painter.setPen(pen);
    painter.save();
    for(int i = 0; i < 60; i++)
    {
        if(i%5 != 0)
            painter.drawLine(0,89,0,86);
        painter.rotate(6);
    }
    painter.restore();

    //画秒针
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(secondColor));
    painter.rotate(6*currTime.second());
    painter.drawConvexPolygon(secondHand,3);
    painter.restore();

    //画表盘中心转轴
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(QPoint(0,0),7,7);
    //画表盘
    pen.setColor(Qt::black);
    pen.setWidth(borderWidth);
    painter.setPen(pen);
    painter.setBrush(QBrush());
    painter.drawEllipse(QPoint(0,0),95,95);
}

QColor AnalogClock::getHourColor()const{return hourColor;}
QColor AnalogClock::getMinuteColor()const{return minuteColor;}
QColor AnalogClock::getSecondColor()const{return secondColor;}
QColor AnalogClock::getTextColor()const{return textColor;}
int AnalogClock::getBorderWidth()const{return borderWidth;}
int AnalogClock::getHourWidth()const{return hourWidth;}
int AnalogClock::getMinuteWidth()const{return minuteWidth;}

void AnalogClock::setHourColor(QColor c){hourColor = c;}
void AnalogClock::setMinuteColor(QColor c){minuteColor = c;};
void AnalogClock::setSecondColor(QColor c){secondColor = c;}
void AnalogClock::setTextColor(QColor c){textColor = c;}
void AnalogClock::setBorderWidth(int i){borderWidth = i;}
void AnalogClock::setHourWidth(int i){hourWidth = i;}
void AnalogClock::setMinuteWidth(int i){minuteWidth = i;}

AnalogClock::~AnalogClock()
{
    delete ui;
}
