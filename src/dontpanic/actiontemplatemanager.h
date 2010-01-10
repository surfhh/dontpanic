#ifndef DP_TEMPLATEMANAGER_H
#define DP_TEMPLATEMANAGER_H
#include <libdontpanic/defines.hpp>
#include <libdontpanic/actiontemplate.hpp>
#include <QObject>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class ActionTemplateManager
        : public QObject
  {
      // ---------------------------------------------------------------------------------
      Q_OBJECT
      Q_CLASSINFO ( "D-Bus Interface", "org.dontpanic.TemplateManager" )
      // ---------------------------------------------------------------------------------
      signals: 
    void removed(dp::ActionTemplate);
    void stored(dp::ActionTemplate);
    // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      ActionTemplateManager ( QObject *parent = 0 );
      // ---------------------------------------------------------------------------------
    public slots:
      // ---------------------------------------------------------------------------------
      void store ( ActionTemplate const& p );
      // ---------------------------------------------------------------------------------
      void remove(ActionTemplate const& p);
      // ---------------------------------------------------------------------------------
      TemplateList allTemplates();
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
}
// ---------------------------------------------------------------------------------
#endif // DP_TEMPLATEMANAGER_H
