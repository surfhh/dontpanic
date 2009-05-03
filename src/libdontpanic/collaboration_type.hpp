#ifndef DP_COLLABORATION_TYPE_HPP
#define DP_COLLABORATION_TYPE_HPP
//dp includes
#include "defines.hpp"
//Qt includes
// ---------------------------------------------------------------------------------
#include <QString>
#include <QDateTime>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class collaboration_type
  {
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( collaboration_type );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      collaboration_type();
      // ---------------------------------------------------------------------------------
    private:
      // ---------------------------------------------------------------------------------
      QString _M_id;
      // ---------------------------------------------------------------------------------
      bool _M_visible;
      // ---------------------------------------------------------------------------------
      QDateTime _M_creation_date;
      // ---------------------------------------------------------------------------------
      bool _M_solo_effort;
      // ---------------------------------------------------------------------------------
      bool _M_interrupting;
      // ---------------------------------------------------------------------------------
      //TODO ? modification date;
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
  DECLARE_SMARTPOINTERS ( collaboration_type );
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //DP_COLLABORATION_TYPE_HPP