#ifndef _IDLE_SERVICE_H_
#define _IDLE_SERVICE_H_

#include <QObject>

#include <faith/config.h>


class MainWindow;
class MainWidget;


namespace faith{
  namespace core {
    class FAITH_EXPORT Launcher : public QObject{
      Q_OBJECT

      public:
        static Launcher* Instance(){
          static Launcher instance;
          return &instance;
        }

        void exec();

        void Init();

        void InitPlugin();
        void InitService();
        void InitGui();
        void InitConfig();

      private:
        explicit Launcher(QObject *parent = nullptr);

      private:
//        MainWindow *_win;
        MainWidget *_win;
    };
  }
}

#endif //_IDLE_SERVICE_H_
