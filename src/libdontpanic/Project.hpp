#ifndef LIBDONTPANICPROJECT_HPP
#define LIBDONTPANICPROJECT_HPP
// ---------------------------------------------------------------------------------
#include "defines.hpp"
#include <QString>
#include <QDateTime>
// ---------------------------------------------------------------------------------
namespace dp
{
// ---------------------------------------------------------------------------------
  class DP_EXPORT Project
  {
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( Project );
      // ---------------------------------------------------------------------------------
      ///ctor
      Project();
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      uint64_t id() const;
      // ---------------------------------------------------------------------------------
      void set_id(uint64_t id);
      // ---------------------------------------------------------------------------------
      QString name() const;
      // ---------------------------------------------------------------------------------
      bool is_visible() const;
      // ---------------------------------------------------------------------------------
      QDateTime const& creation_date() const;
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
      //TODO ? modification date
  };
  // ---------------------------------------------------------------------------------
  DECLARE_SMARTPOINTERS ( Project );
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //LIBDONTPANICPROJECT_HPP