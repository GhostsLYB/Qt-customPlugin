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
    //钟表三个指针的颜色
    QColor hourColor = QColor("#7F007F");
    QColor minuteColor = QColor(0,127,127,196);
    QColor secondColor = QColor(127,127,0,180);

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
    pen.setWidth(3);
    pen.setColor(hourColor);
    painter.setPen(pen);
    for(int i = 1; i <= 12; i++)
    {
        painter.rotate(30);
        painter.drawLine(0,-92,0,-86);
        painter.drawText(QRect(-4,-84,12,12),QString("%1").arg(i));

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
    pen.setWidth(2);
    pen.setColor(minuteColor);
    painter.setPen(pen);
    painter.save();
    for(int i = 0; i < 60; i++)
    {
        if(i%5 != 0)
            painter.drawLine(0,91,0,88);
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
    painter.drawEllipse(QPoint(0,0),5,5);
    //画表盘
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.setBrush(QBrush());
    painter.drawEllipse(QPoint(0,0),97,97);
}

AnalogClock::~AnalogClock()
{
    delete ui;
}
