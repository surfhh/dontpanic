#ifndef DONTPANIC_APP_HPP
#define DONTPANIC_APP_HPP
//dp includes
#include "defines.hpp"
//Qt includes
#include <QCoreApplication>
// ---------------------------------------------------------------------------------
class Application
      : public QCoreApplication
{
    // ---------------------------------------------------------------------------------
    Q_OBJECT
    Q_CLASSINFO ( "D-Bus Interface", "org.dontpanic.Application" )
    // ---------------------------------------------------------------------------------
  public:
    // ---------------------------------------------------------------------------------
    Application ( int &argc, char **argv );
    // ---------------------------------------------------------------------------------
  public Q_SLOTS:
    // ---------------------------------------------------------------------------------
    //override QCoreApplication::exit() in order to expose this method
    //to the DBUS interface:
    void exit();
    // ---------------------------------------------------------------------------------
    /**
     * \brief this method is just intended to serve for DBUS testing...
     */
    QString hello();
    // ---------------------------------------------------------------------------------
  private:
    // ---------------------------------------------------------------------------------
    FORWARD_DECL(ApplicationPrivate);
    ApplicationPrivate_ptr d;
    // ---------------------------------------------------------------------------------
};
// ---------------------------------------------------------------------------------
#endif //DONTPANIC_APP_HPP