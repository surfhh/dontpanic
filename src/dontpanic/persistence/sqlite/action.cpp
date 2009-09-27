#include <persistence/sqlite/action.hpp>
#include "persistence/execute_query.hpp"
#include <libdontpanic/action.hpp>

#include <persistence/sqlite/task.hpp>
#include <persistence/sqlite/project.hpp>
#include <QVariant>
#include <QSqlQuery>
namespace dp
{
  // ---------------------------------------------------------------------------------
  namespace _persistence
  {
    // ---------------------------------------------------------------------------------
    namespace _sqlite
    {
      const QString INSERT_ACTION =
        "INSERT INTO a_action(a_t_task , a_p_project,a_ct_collaboration_type,\
        a_name, a_comment, a_start, a_end, a_reviewed, a_billed)VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)";
      // ---------------------------------------------------------------------------------
      const QString SELECT_ALL_ACTIONS =
        "SELECT a_id, a_t_task , a_p_project,a_ct_collaboration_type,\
        a_name, a_comment, a_start, a_end, a_reviewed, a_billed FROM a_action";
      // ---------------------------------------------------------------------------------
      const QString SELECT_DISTINCT_ACTION =
        "SELECT DISTINCT a_id, a_t_task , a_p_project,a_ct_collaboration_type,\
        a_name, a_comment, a_start, a_end, a_reviewed, a_billed FROM a_action WHERE (a_id=?)";
      // ---------------------------------------------------------------------------------
      const QString UPDATE_ACTION =
        "UPDATE a_action set(a_t_task=?, a_p_project=?,a_ct_collaboration_type=?,\
        a_name=?, a_comment=?, a_start=?, a_end=?, a_reviewed=?, a_billed=?) WHERE (a_id=?)";
      // ---------------------------------------------------------------------------------
      success Action::persist ( dp::Action &_a ) const
      {
        if ( exists ( _a ) )
        {
          return update ( _a );
        }
        return insert ( _a );
      }
      // ---------------------------------------------------------------------------------
      success Action::load ( dp::Action &a ) const
      {
        if ( a.id() == 0 )
        {
          return error();
        }
        QSqlQuery query;
        query.prepare ( SELECT_DISTINCT_ACTION );
        query.addBindValue ( a.id() );
        if ( execute ( query ).has_failed() )
        {
          return error();
        }
        if ( !query.first() )
        {
          return error();
        }
        return assign_query_values_to_entity ( query, a );
      }
      // ---------------------------------------------------------------------------------
      //private stuff:
      // ---------------------------------------------------------------------------------
      bool Action::exists ( dp::Action const& _a ) const
      {
        if ( _a.id() == 0 )
        {
          return false;
        }
        QSqlQuery query;
        query.prepare ( SELECT_DISTINCT_ACTION );
        query.addBindValue ( _a.id() );
        if ( execute ( query ).has_failed() )
        {
          return false;
        }
        return query.first();
      }
      // ---------------------------------------------------------------------------------
      success Action::insert ( dp::Action &_a ) const
      {
        {
        QSqlQuery query;
        query.prepare ( INSERT_ACTION );
        query.addBindValue ( _a.task()->id() );
        query.addBindValue ( _a.project()->id() );
        query.addBindValue ( _a.collaborationType()->id() );
        query.addBindValue ( _a.name() );
        query.addBindValue ( _a.comment() );
        query.addBindValue ( _a.startTime() );
        query.addBindValue ( _a.endTime() );
        query.addBindValue ( _a.reviewed() );
        query.addBindValue ( _a.billed() );
        if ( execute ( query ).has_failed() )
        {
          return error();
        }
        _a.setId ( query.lastInsertId().toULongLong() );
        return successful();
      }
      }
      // ---------------------------------------------------------------------------------
      success Action::update ( dp::Action const& _a ) const
      {
      QSqlQuery query;
        query.prepare ( UPDATE_ACTION );
        query.addBindValue ( _a.task()->id() );
        query.addBindValue ( _a.project()->id() );
        query.addBindValue ( _a.collaborationType()->id() );
        query.addBindValue ( _a.name() );
        query.addBindValue ( _a.comment() );
        query.addBindValue ( _a.startTime() );
        query.addBindValue ( _a.endTime() );
        query.addBindValue ( _a.reviewed() );
        query.addBindValue ( _a.billed() );
        query.addBindValue ( _a.id() );
        return execute ( query );
      }
      // ---------------------------------------------------------------------------------
      success Action::assign_query_values_to_entity ( QSqlQuery &query, dp::Action &a ) const
      {
        a.setId ( query.value ( 0 ).toULongLong() );
        uint64_t task_id = query.value ( 1 ).toULongLong();
        dp::Task::ptr _task(new dp::Task(task_id));
        task().load(*_task);
        a.setTask(_task);
        uint64_t project_id = query.value ( 2 ).toULongLong();
        dp::Project::ptr _project(new dp::Project(project_id));
        project().load(*_project);
        a.setProject(_project);
        uint64_t collaboration_id = query.value ( 3 ).toULongLong();
        //TODO load collaboration type!!!
        a.setName ( query.value ( 5 ).toString() );
        a.setComment ( query.value ( 6 ).toString() );
        a.setStartTime ( query.value ( 7 ).toDateTime() );
        a.setEndTime ( query.value ( 7 ).toDateTime() );
        a.setReviewed(query.value(8).toBool());
        a.setBilled(query.value(9).toBool());
        return successful();
      }
      // ---------------------------------------------------------------------------------
    }
    // ---------------------------------------------------------------------------------
  }
  // ---------------------------------------------------------------------------------
}
// ---------------------------------------------------------------------------------