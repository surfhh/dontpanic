#include "taskmanager.h"
#include "persistencebackend.hpp"

#include <KDebug>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  TaskManager::TaskManager ( QObject *parent )
      : QObject ( parent ){}
  // ---------------------------------------------------------------------------------
  void TaskManager::store ( Task const& t )
  {
    if(persistence().persist(t).was_successful())
       {
        emit stored(t);
       }
  }
  // ---------------------------------------------------------------------------------
  void TaskManager::remove(Task const& t)
  {
    if(persistence().remove(t).was_successful())
    {
      emit removed(t);
    }
  }
  // ---------------------------------------------------------------------------------
  TaskList TaskManager::allTasks()
  {
    TaskList list;
    persistence().findAll(list);
    return list;
  }
  // ---------------------------------------------------------------------------------
}//
// ---------------------------------------------------------------------------------

