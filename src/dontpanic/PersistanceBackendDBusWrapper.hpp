#ifndef DP_PERSISTANCE_BACKEND_DBUS_WRAPPER_HPP
#define DP_PERSISTANCE_BACKEND_DBUS_WRAPPER_HPP
//dp includes
#include "defines.hpp"
//Qt includes
#include <QObject>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class Project;
  // ---------------------------------------------------------------------------------
  class PersistanceBackendDBusWrapper: public QObject
  {
    // ---------------------------------------------------------------------------------
    Q_OBJECT
    Q_CLASSINFO ( "D-Bus Interface", "org.dontpanic.Persistance" )
    // ---------------------------------------------------------------------------------
    public Q_SLOTS:
    // ---------------------------------------------------------------------------------
    bool persist(Project & p);
    // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif // DP_PERSISTANCE_BACKEND_DBUS_WRAPPER_HPP
