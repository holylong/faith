#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QMouseEvent>
#include <QPoint>

class SettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsWidget(QWidget *parent = nullptr);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

private:
    void InitGeneralSettings();
    void InitTransportSettings();
    void InitSystemSettings();
    void InitRemoteSettings();
    void InitIMSettings();

signals:

private:
    QFormLayout  *_layout;
    QPoint    _lastPos;

};

#endif // SETTINGSWIDGET_H
