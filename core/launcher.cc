#include "launcher.h"
#include "ui/mainwindow.h"
#include "ui/mainwidget.h"
#include "idleservice.h"

namespace faith{

  namespace core{
      Launcher::Launcher(QObject *parent):QObject(parent)
      { 

      }

      //加载config
      //启动后台service
      //加载plugin
      //启动界面
      void Launcher::Init()
      {
          InitConfig();
          InitService();
          InitPlugin();
          InitGui();
      }

      void Launcher::InitPlugin()
      {

      }

      void Launcher::InitService()
      {
          _service = new IdleService();
          _service->SendBroadcast();
      }

      void Launcher::InitGui()
      {
//          _win = new MainWindow();
//          _win->show();

          _win = new MainWidget();
          _win->show();
      }

      void Launcher::InitConfig()
      {

      }

      void Launcher::exec()
      {
        Init();
        return;
      }

  }
}
