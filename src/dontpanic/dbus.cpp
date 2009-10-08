#include "libdontpanic/dbus.hpp"
#include "applicationadaptor.h"
#include "timetrackeradaptor.h"
#include "projectmanageradaptor.h"
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  // implementions for the well known Adaptor types:
  // ---------------------------------------------------------------------------------
  template<>
  QDBusAbstractAdaptor* create_dbus_adaptor_for<Application> ( Application *obj )
  {
    return new ApplicationAdaptor ( obj );
  }
  // ---------------------------------------------------------------------------------
  template<>
  QDBusAbstractAdaptor* create_dbus_adaptor_for<dp::TimeTracker> ( dp::TimeTracker *obj )
  {
    return new TimeTrackerAdaptor ( obj );
  }
  // ---------------------------------------------------------------------------------
  template<>
  QDBusAbstractAdaptor* create_dbus_adaptor_for<dp::ProjectManager> ( dp::ProjectManager *obj )
  {
    return new ProjectManagerAdaptor ( obj );
  }
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
