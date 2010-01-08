#include "persistencebackend.hpp"

//Qt includes
#include <QDebug>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  bool PersistenceBackend::init()
  {
    if ( dp::_persistence::sqlite().open_database_connection().has_failed() )
    {
      qWarning() << "unable to initialize persistance backend. exiting now";
      ::exit ( 1 );
    }
    if ( dp::_persistence::sqlite().update_database_schema_if_necessary().has_failed() )
    {
      qWarning() << "unable to initialize the required database schema. exiting now";
      ::exit ( 1 );
    }
    return true;
  }
  // ---------------------------------------------------------------------------------
  Action_ptr PersistenceBackend::activeAction()
  {
    return _persistence::sqlite().activeAction();
  }
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
