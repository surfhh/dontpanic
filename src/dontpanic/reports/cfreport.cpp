#include "cfreport.h"
#include "persistencebackend.hpp"
#include <libdontpanic/action.hpp>
#include <libdontpanic/project.hpp>
#include <libdontpanic/task.hpp>
#include <libdontpanic/durationformatter.h>
namespace dp
{
  // ---------------------------------------------------------------------------------
  namespace reports
  {
    // ---------------------------------------------------------------------------------
    class group
    {
      public:
        group(QUuid const& p, QUuid const& t);
      public:
        Project project() const;
        Task task() const;
        int duration() const;      
        bool matches(Action const& a) const;
        group & add(Action const& a);
      
      private:
        QUuid _M_project;
        QUuid _M_task;
        ActionList _M_actions;
    };
    typedef QList<group> GroupList;
    // ---------------------------------------------------------------------------------
    class group_list
    {
      public:
        ~group_list(){}
      void sort(ActionList const& actions);
      QString toString();
      private:
        bool added_to_existing_group(Action const& a);
        void add_to_newly_created_group(Action const& a);
        int duration() const;        
        QString dump(group const& g, int dur);
      private:
        GroupList _M_groups;
    };
     // ---------------------------------------------------------------------------------
    class CFReport::CFReportPrivate
    {
      public:
      void setRange(TimeRange const& r);
      Report asDontPanicReport();
      private:
        QString evaluate(ActionList const& actions);
      private:
      TimeRange _M_range;
    };
    // ---------------------------------------------------------------------------------
    // group impl:
    // ---------------------------------------------------------------------------------
    group::group(QUuid const& p, QUuid const& t)
    :_M_project(p)
    , _M_task(t){}
    // ---------------------------------------------------------------------------------
    Project group::project() const
    {
      Project p(_M_project);
      if(persistence().load(p).was_successful())
      {
        return p;
      }
      return NullProject();
    }
    // ---------------------------------------------------------------------------------
    Task group::task() const
    {
      Task t(_M_task);
      if(persistence().load(t).was_successful())
      {
        return t;
      }
      return NullTask();
    }
    // ---------------------------------------------------------------------------------
    int group::duration() const
    {
      int result = 0;
      ActionList::const_iterator iter;
      for(iter = _M_actions.begin(); iter != _M_actions.end();++iter)
      {
        result+=(*iter).duration();
      }
      return result;
    }
    // ---------------------------------------------------------------------------------
    bool group::matches(Action const& a) const
    {
      return (a.task()==_M_task && a.project() == _M_project);
    }
    // ---------------------------------------------------------------------------------
    group & group::add(Action const& a)
    {
      _M_actions.append(a);
      return *this;
    }
    // ---------------------------------------------------------------------------------
    // group_list
    // ---------------------------------------------------------------------------------
    bool group_list::added_to_existing_group(Action const& a)
    {
      GroupList::iterator iter;
      for(iter=_M_groups.begin();iter!=_M_groups.end();++iter)
      {
        if((iter)->matches(a))
        {
          (iter)->add(a);
          return true;
        }
      }
      return false;
    }
    // ---------------------------------------------------------------------------------
    void group_list::add_to_newly_created_group(Action const& a)
    {
      group g(a.project(),a.task());
      g.add(a);
      _M_groups<<g;
    }
    // ---------------------------------------------------------------------------------
    void group_list::sort(ActionList const& actions)
    {
      ActionList::const_iterator action_iter;
      for(action_iter=actions.begin();action_iter != actions.end();++action_iter)
      {
        if(!added_to_existing_group(*action_iter))
        {
          add_to_newly_created_group(*action_iter);
        }
      }
    }
    
    int group_list::duration() const
    {
      GroupList::const_iterator iter;
      int result(0);
      for(iter = _M_groups.begin();iter != _M_groups.end();++iter)
      {
        result +=(iter)->duration();
      }
      return result;
    }
    
    QString group_list::dump(group const& g, int dur)
    {
      double percentage = 0.0;
      DurationFormatter formatter;
      if(dur!=0){percentage = 100.0*(double)g.duration()/(double)dur;}
      Project const& p = g.project();
      QString s = QString("%1;%2;%3;%4\%;%5")
      .arg(g.task().name())
      .arg(p.name())
      .arg(formatter.format(g.duration()))
      .arg(percentage, 0, 'f', 2)
      .arg(p.comment());
      return s;
      
    }
    
    
    QString group_list::toString()
    {
      QString result= "Typ;Projekt;Dauer (Tätigkeitsgruppe);Prozent (Tätigkeitsgruppe);Projektkommentar\n";
      int complete_duration = duration();
      GroupList::const_iterator i;
       for(i = _M_groups.begin();i!= _M_groups.end();++i)
       {
         result += dump(*i, complete_duration) + "\n";
       }
      return result;
    }
    // ---------------------------------------------------------------------------------
    // CFReportPrivate imp:
    // ---------------------------------------------------------------------------------
    void CFReport::CFReportPrivate::setRange(TimeRange const& r)
    {
      _M_range = r;
    }
    // ---------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------
    Report CFReport::CFReportPrivate::asDontPanicReport()
    {
      Report report;
      report.setReportType("comForte monthly report").setRange(_M_range);
      ActionList actions;
      if(persistence().findAll(actions, _M_range.from(), _M_range.to()).has_failed())
      {
        return report.setValid(false);
      }
      return report.setReportData(evaluate(actions));
    }
    // ---------------------------------------------------------------------------------
    QString CFReport::CFReportPrivate::evaluate(ActionList const& actions)
    {
      group_list gl;
      gl.sort(actions);
      return gl.toString();
    }    
    // ---------------------------------------------------------------------------------
    // CFReport:
    // ---------------------------------------------------------------------------------
    CFReport::CFReport()
    :d(new CFReportPrivate())
    {
    }
    // ---------------------------------------------------------------------------------
    CFReport::~CFReport(){
     delete d;
    }    
    // ---------------------------------------------------------------------------------
    CFReport & CFReport::setRange(TimeRange const& range)
    {
      d->setRange(range);
      return *this;
    }
    // ---------------------------------------------------------------------------------
    Report CFReport::asDontPanicReport()
    {
      return d->asDontPanicReport();
    }
  } // ---------------------------------------------------------------------------------
}
// ---------------------------------------------------------------------------------