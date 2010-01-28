#ifndef DP_PROJECTMANAGER_H
#define DP_PROJECTMANAGER_H
#include <libdontpanic/defines.hpp>
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
      Q_CLASSINFO ( "D-Bus Interface", "org.dontpanic.ProjectManager" )
      // ---------------------------------------------------------------------------------
      signals: 
    void removed(dp::Project);
    void stored(dp::Project);
    // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      ProjectManager ( QObject *parent = 0 );
      // ---------------------------------------------------------------------------------
    public slots:
      // ---------------------------------------------------------------------------------
      void store ( Project const& p );
      // ---------------------------------------------------------------------------------
      void remove(Project const& p);
      // ---------------------------------------------------------------------------------
      Project load(QUuid const& p);
      // ---------------------------------------------------------------------------------
      ProjectList findAll();
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
}
// ---------------------------------------------------------------------------------
#endif // DP_PROJECTMANAGER_H
