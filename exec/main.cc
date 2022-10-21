#include <QtWidgets>
#include <QApplication>
#include <launcher.h>

using namespace faith::core;

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setApplicationVersion("0.0.1");
  app.setApplicationDisplayName("faith app");
  app.setApplicationName("faith app");
  app.setWindowIcon(QIcon(":/resources/app.png"));
  Launcher *launcher = Launcher::Instance();
  launcher->exec();
  return app.exec();
}

