#ifndef DONTPANICLIB_ACTIONTEMPLATE_HPP
#define DONTPANICLIB_ACTIONTEMPLATE_HPP
// ---------------------------------------------------------------------------------
#include "defines.hpp"
#include "task.hpp"
#include "project.hpp"
#include <QUuid>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class ActionTemplate
  {
      // ---------------------------------------------------------------------------------
      friend QDBusArgument const& operator >> ( QDBusArgument const&arg, ActionTemplate & at );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( ActionTemplate );
      // ---------------------------------------------------------------------------------
      ///ctor:
      // ---------------------------------------------------------------------------------
      ActionTemplate();
      // ---------------------------------------------------------------------------------
      ActionTemplate(QString const& name);
      // ---------------------------------------------------------------------------------
      ActionTemplate(QUuid const& id);
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      bool isValid() const;
      // ---------------------------------------------------------------------------------
      QUuid id() const;
      // ---------------------------------------------------------------------------------
      QUuid task() const;
      // ---------------------------------------------------------------------------------
      ActionTemplate& setTask ( QUuid );
      // ---------------------------------------------------------------------------------
      QUuid project() const;
      // ---------------------------------------------------------------------------------
      ActionTemplate& setProject ( QUuid );
      // ---------------------------------------------------------------------------------
      QUuid collaborationType() const;
      // ---------------------------------------------------------------------------------
      ActionTemplate& setCollaborationType ( QUuid );
      // ---------------------------------------------------------------------------------
      QString name() const;
      // ---------------------------------------------------------------------------------
      ActionTemplate& setName ( QString name );
      // ---------------------------------------------------------------------------------
      QString comment() const;
      // ---------------------------------------------------------------------------------
      ActionTemplate& setComment ( QString comment );
      // ---------------------------------------------------------------------------------
      QString icon() const;
      // ---------------------------------------------------------------------------------
      ActionTemplate& setIcon ( QString icon );
      // ---------------------------------------------------------------------------------
    private:
      // ---------------------------------------------------------------------------------
      QUuid _M_id;
      // ---------------------------------------------------------------------------------
      QUuid _M_task;
      // ---------------------------------------------------------------------------------
      QUuid _M_project;
      // ---------------------------------------------------------------------------------
      QString _M_teamwork;
      // ---------------------------------------------------------------------------------
      //TODO person list
      // ---------------------------------------------------------------------------------
      QString _M_name;
      // ---------------------------------------------------------------------------------
      QString _M_comment;
      // ---------------------------------------------------------------------------------
      QString _M_icon;
      // ---------------------------------------------------------------------------------
      //TODO shortcut
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
  typedef QList<ActionTemplate> TemplateList;
  // ---------------------------------------------------------------------------------
  DECLARE_SMARTPOINTERS ( ActionTemplate );
  // ---------------------------------------------------------------------------------
  class DP_EXPORT NullActionTemplate: public ActionTemplate
  {
    public:
      // ---------------------------------------------------------------------------------
      NullActionTemplate() : ActionTemplate ( QUuid() ) {}
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
  bool DP_EXPORT operator == (dp::ActionTemplate const& lhs, dp::ActionTemplate const& rhs);
  // ---------------------------------------------------------------------------------
  template<typename ostream>
  ostream & operator<<(ostream &out, dp::ActionTemplate const& t)
  {
    out<<"Template: "<<t.id().toString()<<", name: "<<t.name();
    return out;
  }
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //DONTPANICLIB_ACTIONTEMPLATE_HPP
