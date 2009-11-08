#ifndef DP_PROJECTMANAGER_H
#define DP_PROJECTMANAGER_H
#include <defines.hpp>
#include <libdontpanic/project.hpp>
#include <QObject>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class ProjectManager
        : public QObject
  {
      // ---------------------------------------------------------------------------------
      Q_OBJECT
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      ProjectManager ( QObject *parent = 0 );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      void store ( Project const& p );
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
}
// ---------------------------------------------------------------------------------
#endif // DP_PROJECTMANAGER_H
