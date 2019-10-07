#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QtDesigner/QDesignerExportWidget>
#include <QTime>
#include <QTimer>

namespace Ui {
class AnalogClock;
}

class QDESIGNER_WIDGET_EXPORT AnalogClock : public QWidget
{
    Q_OBJECT
    //自定义属性
    Q_PROPERTY(QColor hourColor READ getHourColor WRITE setHourColor
               NOTIFY hourColorChanged DESIGNABLE true)
    Q_PROPERTY(QColor minuteColor READ getMinuteColor WRITE setMinuteColor
               NOTIFY minuteColorChanged DESIGNABLE true)
    Q_PROPERTY(QColor secondColor READ getSecondColor WRITE setSecondColor
               NOTIFY secondColorChanged DESIGNABLE true)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor
               NOTIFY textColorChanged DESIGNABLE true)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth
               NOTIFY borderWidthChanged DESIGNABLE true)
    Q_PROPERTY(int hourWidth READ getHourWidth WRITE setHourWidth
               NOTIFY hourWidthChanged DESIGNABLE true)
    Q_PROPERTY(int minuteWidth READ getMinuteWidth WRITE setMinuteWidth
               NOTIFY minuteWidthChanged DESIGNABLE true)
private:
    //钟表三个指针的颜色及各线宽
    QColor hourColor = QColor("#7F007F");
    QColor minuteColor = QColor(0,127,127,196);
    QColor secondColor = QColor(127,127,0,180);
    QColor textColor = QColor("#7F007F");
    int borderWidth = 5;
    int hourWidth = 3;
    int minuteWidth = 2;
public:
    QColor getHourColor() const;
    QColor getMinuteColor() const;
    QColor getSecondColor() const;
    QColor getTextColor() const;
    int getBorderWidth() const;
    int getHourWidth() const;
    int getMinuteWidth() const;
    void setHourColor(QColor);
    void setMinuteColor(QColor);
    void setSecondColor(QColor);
    void setTextColor(QColor);
    void setBorderWidth(int);
    void setHourWidth(int);
    void setMinuteWidth(int);
signals:
    void hourColorChanged(QColor);
    void minuteColorChanged(QColor);
    void secondColorChanged(QColor);
    void textColorChanged(QColor);
    void borderWidthChanged(int);
    void minuteWidthChanged(int);
    void hourWidthChanged(int);
public:
    explicit AnalogClock(QWidget *parent = nullptr);
    ~AnalogClock();
protected:
    void paintEvent(QPaintEvent*);
private:
    Ui::AnalogClock *ui;
};

#endif // ANALOGCLOCK_H
