#ifndef LIBDONTPANICPROJECT_HPP
#define LIBDONTPANICPROJECT_HPP
// ---------------------------------------------------------------------------------
#include "defines.hpp"
#include <QString>
#include <QDateTime>
#include <QMetaType>
#include <QUuid>
class QDBusArgument;
// ---------------------------------------------------------------------------------
namespace dp
{
// ---------------------------------------------------------------------------------
  class DP_EXPORT Project
  {
      // ---------------------------------------------------------------------------------
      friend QDBusArgument const& operator >> ( QDBusArgument const&arg, Project & project );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( Project );
      // ---------------------------------------------------------------------------------
      ///ctor
      Project();
      // ---------------------------------------------------------------------------------
      Project(QString const& name);
      // ---------------------------------------------------------------------------------
      Project ( QUuid const& id );
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      QUuid const& id() const;
      // ---------------------------------------------------------------------------------
      QString name() const;
      // ---------------------------------------------------------------------------------
      Project& setName ( QString name );
      // ---------------------------------------------------------------------------------
      QDateTime const& creationDate() const;
      // ---------------------------------------------------------------------------------
      Project& setCreationDate ( QDateTime date );
      // ---------------------------------------------------------------------------------
      QString const& comment() const;
      // ---------------------------------------------------------------------------------
      Project & setComment(QString comment);
      // ---------------------------------------------------------------------------------
    private:
      // ---------------------------------------------------------------------------------
      QUuid _M_id;
      // ---------------------------------------------------------------------------------
      QString _M_name;
      // ---------------------------------------------------------------------------------
      QDateTime _M_creation_date;
      // ---------------------------------------------------------------------------------
      QString _M_comment;
      // ---------------------------------------------------------------------------------
      //TODO ? modification date
  };
  // ---------------------------------------------------------------------------------
  typedef QList<Project> ProjectList;
  // ---------------------------------------------------------------------------------
  DECLARE_SMARTPOINTERS ( Project );
  // ---------------------------------------------------------------------------------
  class DP_EXPORT NullProject: public Project
  {
    public:
      // ---------------------------------------------------------------------------------
      NullProject() : Project ( QUuid() ) {}
      // ---------------------------------------------------------------------------------
  };
  // ---------------------------------------------------------------------------------
  bool DP_EXPORT operator == (dp::Project const& lhs, dp::Project const& rhs);
  // ---------------------------------------------------------------------------------
  template<typename ostream>
  ostream & operator<<(ostream &out, dp::Project const& p)
  {
    out<<"Project: "<<p.id().toString()<<", name: "<<p.name();
    return out;
  }
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //LIBDONTPANICPROJECT_HPP
