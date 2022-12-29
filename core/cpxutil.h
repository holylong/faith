#ifndef CPXUTIL_H
#define CPXUTIL_H

#endif // CPXUTIL_H
#ifndef _COMMON_UTIL_H_
#define _COMMON_UTIL_H_

#include <powertoys/config.h>

#include <QScreen>
#include <QApplication>
#include <QWidget>
#include <QPoint>

namespace CMUtil{
    class POWERTOYS_EXPORT CpxUtil{
        public:
            static int GetDesktopWidth(){
                return qApp->primaryScreen()->size().width();
            }

            static int GetDesktopHeight(){
                return qApp->primaryScreen()->size().height();
            }

            static int GetWidgetWidth(QWidget *widget){
                return widget->width();
            }

            static int GetWidgetHeight(QWidget *widget){
                return widget->height();
            }

            static QPoint GetWidgetPos(QWidget *widget){
                return widget->pos();
            }

    };
}

#endif //_COMMON_UTIL_H_
