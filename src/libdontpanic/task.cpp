#include "task.hpp"

// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  ///ctor
  task::task()
      : _M_id ( "0" )
      , _M_name ( "" )
      , _M_visible ( true )
      , _M_solo_effort ( true )
      , _M_chargeable ( true )
      , _M_creation_date ( QDateTime::currentDateTime() ) {}
  // ---------------------------------------------------------------------------------
  QString const& task::id() const
  {
    return _M_id;
  }
  // ---------------------------------------------------------------------------------
  QString const& task::name() const
  {
    return _M_name;
  }
  // ---------------------------------------------------------------------------------
  bool task::visible() const
  {
    return _M_visible;
  }
  // ---------------------------------------------------------------------------------
  bool task::solo_effort() const
  {
    return _M_solo_effort;
  }
  // ---------------------------------------------------------------------------------
  bool task::chargeable() const
  {
    return _M_chargeable;
  }
  // ---------------------------------------------------------------------------------
  QDateTime const& task::creation_date() const
  {
    return _M_creation_date;
  }
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
