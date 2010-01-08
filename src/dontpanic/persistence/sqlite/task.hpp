#ifndef DP_PERSISTANCE_SQLITE_TASK_HPP
#define DP_PERSISTANCE_SQLITE_TASK_HPP
// ---------------------------------------------------------------------------------
//dp includes
#include "libdontpanic/defines.hpp"
#include "libdontpanic/success.hpp"
//Forward decl
class QSqlQuery;
// ---------------------------------------------------------------------------------
namespace dp
{
  class Task;
  typedef QList<Task> TaskList;
  // ---------------------------------------------------------------------------------
  namespace _persistence
  {
    // ---------------------------------------------------------------------------------
    namespace _sqlite
    {
      // ---------------------------------------------------------------------------------
      class Task
      {
          // ---------------------------------------------------------------------------------
        public:
          // ---------------------------------------------------------------------------------
          success persist ( dp::Task const&p ) const;
	  // ---------------------------------------------------------------------------------
	  success remove ( dp::Task const&t ) const;	  
          // ---------------------------------------------------------------------------------
          success load ( dp::Task &p ) const;
          // ---------------------------------------------------------------------------------
	  success findAll(dp::TaskList &list) const;
          // ---------------------------------------------------------------------------------
        private:
          // ---------------------------------------------------------------------------------
          bool exists ( dp::Task const& _project ) const;
          // ---------------------------------------------------------------------------------
          success insert ( dp::Task const&_p ) const;
          // ---------------------------------------------------------------------------------
          success update ( dp::Task const& _p ) const;
          // ---------------------------------------------------------------------------------
          success assign_query_values_to_entity(QSqlQuery &query, dp::Task &p) const;
          // ---------------------------------------------------------------------------------
      };//Project
      // ---------------------------------------------------------------------------------
      inline Task task()
      {
        return Task();
      }
      // ---------------------------------------------------------------------------------
    }//_sqlite
    // ---------------------------------------------------------------------------------
  }//_persistance
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //!DP_PERSISTANCE_SQLITE_TASK_HPP
