#ifndef WIDGETUTIL_H
#define WIDGETUTIL_H

#include <QObject>
#include <QWidget>

class WidgetUtil : public QObject
{
    Q_OBJECT
public:
    explicit WidgetUtil(QObject *parent = nullptr);


    static void Resize(QWidget *widget, int width, int height){
        widget->setFixedSize(width, height);
    }

    static void ResizeWidth(QWidget *widget, int width){
        widget->setFixedWidth(width);
    }

    static void ResizeHeight(QWidget *widget, int height){
        widget->setFixedWidth(height);
    }

signals:

};

#endif // WIDGETUTIL_H
