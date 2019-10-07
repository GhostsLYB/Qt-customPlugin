#include "analogclock.h"
#include "analogclockplugin.h"

#include <QtPlugin>

AnalogClockPlugin::AnalogClockPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void AnalogClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool AnalogClockPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *AnalogClockPlugin::createWidget(QWidget *parent)
{
    return new AnalogClock(parent);
}

QString AnalogClockPlugin::name() const
{
    return QLatin1String("AnalogClock");
}

QString AnalogClockPlugin::group() const
{
    return QLatin1String("My Widget");
}

QIcon AnalogClockPlugin::icon() const
{
    return QIcon();
}

QString AnalogClockPlugin::toolTip() const
{
    return QLatin1String("");
}

QString AnalogClockPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool AnalogClockPlugin::isContainer() const
{
    return false;
}

QString AnalogClockPlugin::domXml() const
{
    return QLatin1String("<widget class=\"AnalogClock\" name=\"analogClock\">\n</widget>\n");
}

QString AnalogClockPlugin::includeFile() const
{
    return QLatin1String("analogclock.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(analogclockplugin, AnalogClockPlugin)
#endif // QT_VERSION < 0x050000
