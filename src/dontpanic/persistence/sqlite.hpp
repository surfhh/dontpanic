#ifndef DP_SQLITE_HPP
#define DP_SQLITE_HPP
//dp includes
#include "libdontpanic/defines.hpp"
#include <libdontpanic/action.hpp>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  //forward decl:
  class Project;
  typedef QList<Project> ProjectList;
  class Task;
  typedef QList<Task> TaskList;
  class ActionTemplate;
  typedef QList<ActionTemplate> TemplateList;
  // ---------------------------------------------------------------------------------
  namespace _persistence
  {
    // ---------------------------------------------------------------------------------
    class Sqlite
    {
        // ---------------------------------------------------------------------------------
      public:
        // ---------------------------------------------------------------------------------
        Sqlite();
        // ---------------------------------------------------------------------------------
      public:
        // ---------------------------------------------------------------------------------
        success open_database_connection() const;
        // ---------------------------------------------------------------------------------
        success update_database_schema_if_necessary() const;
        // ---------------------------------------------------------------------------------
      public:
        // ---------------------------------------------------------------------------------
        success persist ( Project const&_project ) const;
        // ---------------------------------------------------------------------------------
        success load (Project & _project)const;
        // ---------------------------------------------------------------------------------
        success remove (Project const& _project)const;
        // ---------------------------------------------------------------------------------
        success findAll(ProjectList &_pl)const;
        // ---------------------------------------------------------------------------------
        success persist ( Task const&_t )const;	
        // ---------------------------------------------------------------------------------
        success load (Task & _t)const;
        // ---------------------------------------------------------------------------------
        success remove (Task const& _t)const;
        // ---------------------------------------------------------------------------------
        success findAll(TaskList &_tl)const;
        // ---------------------------------------------------------------------------------
        success persist ( ActionTemplate const&_t )const;	
        // ---------------------------------------------------------------------------------
        success remove (ActionTemplate const& _t)const;
        // ---------------------------------------------------------------------------------
        success findAll(TemplateList &_tl)const;
        // ---------------------------------------------------------------------------------
        success persist ( Action const&_a )const;
        // ---------------------------------------------------------------------------------
        success remove ( Action const&_a )const;
        // ---------------------------------------------------------------------------------
        success findAll(ActionList &_tl, QDateTime const& from,  QDateTime const& to)const;
        // ---------------------------------------------------------------------------------
        Action lastAction()const;
        // ---------------------------------------------------------------------------------
    };
    // ---------------------------------------------------------------------------------
    inline Sqlite sqlite()
    {
      return Sqlite();
    }
    // ---------------------------------------------------------------------------------
  }//_persistance
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //DP_SQLITE_HPP
