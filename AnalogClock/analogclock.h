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

public:
    explicit AnalogClock(QWidget *parent = nullptr);
    ~AnalogClock();
protected:
    void paintEvent(QPaintEvent*);
private:
    Ui::AnalogClock *ui;
};

#endif // ANALOGCLOCK_H
