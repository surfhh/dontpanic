#ifndef DONTPANICLIB_ACTION_HPP
#define DONTPANICLIB_ACTION_HPP
// ---------------------------------------------------------------------------------
#include "defines.hpp"

//Qt includes
#include <QString>
#include <QDateTime>
#include <QMetaType>
#include <QUuid>

class QDBusArgument;
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class DP_EXPORT Action
  {
      // ---------------------------------------------------------------------------------
      friend QDBusArgument const& operator >> ( QDBusArgument const&arg, Action & action );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( Action );
      // ---------------------------------------------------------------------------------
      Action();
      // ---------------------------------------------------------------------------------
      Action(QUuid const& id);
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      bool isValid() const;
      // ---------------------------------------------------------------------------------
      QUuid const& id() const;
      // ---------------------------------------------------------------------------------
      QUuid task() const;
      // ---------------------------------------------------------------------------------
      void setTask ( QUuid );
      // ---------------------------------------------------------------------------------
      QUuid project() const;
      // ---------------------------------------------------------------------------------
      void setProject ( QUuid );
      // ---------------------------------------------------------------------------------
      QUuid collaborationType() const;
      // ---------------------------------------------------------------------------------
      void setCollaborationType ( QUuid );
      // ---------------------------------------------------------------------------------
      QString name() const;
      // ---------------------------------------------------------------------------------
      void setName ( QString name );
      // ---------------------------------------------------------------------------------
      QString comment() const;
      // ---------------------------------------------------------------------------------
      void setComment ( QString comment );
      // ---------------------------------------------------------------------------------
      QDateTime startTime() const;
      // ---------------------------------------------------------------------------------
      void setStartTime ( QDateTime const& start );
      // ---------------------------------------------------------------------------------
      QDateTime endTime() const;
      // ---------------------------------------------------------------------------------
      void setEndTime ( QDateTime const& end );
      // ---------------------------------------------------------------------------------
      bool reviewed() const;
      // ---------------------------------------------------------------------------------
      void setReviewed ( bool r );
      // ---------------------------------------------------------------------------------
      bool billed() const;
      // ---------------------------------------------------------------------------------
      void setBilled ( bool b );
      // ---------------------------------------------------------------------------------
    private:
      // ---------------------------------------------------------------------------------
      QUuid _M_id;
      // ---------------------------------------------------------------------------------
      QUuid _M_task;
      // ---------------------------------------------------------------------------------
      QUuid _M_project;
      // ---------------------------------------------------------------------------------
      QUuid _M_teamwork;
      // ---------------------------------------------------------------------------------
      //TODO person list
      // ---------------------------------------------------------------------------------
      QString _M_name;
      // ---------------------------------------------------------------------------------
      QString _M_comment;
      // ---------------------------------------------------------------------------------
      QDateTime _M_start;
      // ---------------------------------------------------------------------------------
      QDateTime _M_end;
      // ---------------------------------------------------------------------------------
      bool _M_reviewed;
      // ---------------------------------------------------------------------------------
      bool _M_billed;
      // ---------------------------------------------------------------------------------
  };//Action
  // ---------------------------------------------------------------------------------
  class NullAction:public Action
  {
    // ---------------------------------------------------------------------------------
    public:
  // ---------------------------------------------------------------------------------
  NullAction() : Action ( QUuid() ) {}
  // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
  DECLARE_SMARTPOINTERS ( Action );
  // ---------------------------------------------------------------------------------
  typedef QList<Action> ActionList;
  // ---------------------------------------------------------------------------------
  bool DP_EXPORT operator == (dp::Action const& lhs, dp::Action const& rhs);
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //DONTPANICLIB_ACTION_HPP
