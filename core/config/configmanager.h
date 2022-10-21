#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include <QObject>
#include <nlohmann/json.hpp>

namespace faith{
  namespace {
    class ConfigManager : public QObject{
      Q_OBJECT

      public:
        explicit ConfigManager(){

        }

        void LoadConfig(const QString &path)
        {
          nlohmann::json jobj = nlohmann::json::load(path.to_std);
        }

        void SaveConfig()
        {

        }

      public:
        uint32_t    w(){return _w;}
        uint32_t    h(){return _h;}

      private:
        uint32_t     _w;
        uint32_t     _h;
    }
  }
}

#endif //_CONFIG_MANAGER_H_
