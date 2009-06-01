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
  class CollaborationType
  {
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( CollaborationType );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      CollaborationType();
      // ---------------------------------------------------------------------------------
    private:
      // ---------------------------------------------------------------------------------
      uint64_t _M_id;
      // ---------------------------------------------------------------------------------
      QString _M_name;
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
  DECLARE_SMARTPOINTERS ( CollaborationType );
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //DP_COLLABORATION_TYPE_HPP