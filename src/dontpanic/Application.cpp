#include "Application.hpp"
#include "Application.moc"

#include "libdontpanic/DBus.hpp"
#include "Sqlite.hpp"

//Qt includes
#include <QDebug>
#include <QDBusConnection>
// ---------------------------------------------------------------------------------
// declaration of ApplicationPrivate:
// ---------------------------------------------------------------------------------
class Application::ApplicationPrivate
{
    // ---------------------------------------------------------------------------------
  public:
    // ---------------------------------------------------------------------------------
    ApplicationPrivate ( Application* self );
    // ---------------------------------------------------------------------------------
  public:
    // ---------------------------------------------------------------------------------
    QString hello();
    // ---------------------------------------------------------------------------------
    void exit();
    // ---------------------------------------------------------------------------------
  private:
    // ---------------------------------------------------------------------------------
    void init();
    // ---------------------------------------------------------------------------------
    bool init_storage_backend();
    // ---------------------------------------------------------------------------------
    void register_with_session_bus();
    // ---------------------------------------------------------------------------------
  private:
    // ---------------------------------------------------------------------------------
    Application * _M_self;
    // ---------------------------------------------------------------------------------
};
// ---------------------------------------------------------------------------------
// implementation Application:
// ---------------------------------------------------------------------------------
Application::Application ( int &argc, char** argv )
    : QCoreApplication ( argc, argv )
    , d ( new ApplicationPrivate ( this ) ) {}
// ---------------------------------------------------------------------------------
QString Application::hello()
{
  return d->hello();
}
// ---------------------------------------------------------------------------------
void Application::exit()
{
  d->exit();
}
// ---------------------------------------------------------------------------------
// implementation ApplicationPrivate:
// ---------------------------------------------------------------------------------
Application::ApplicationPrivate::ApplicationPrivate ( Application *self )
    : _M_self ( self )
{
  init();
}
// ---------------------------------------------------------------------------------
QString Application::ApplicationPrivate::hello()
{
  return "dontpanic says 'hello'";
}
// ---------------------------------------------------------------------------------
void Application::ApplicationPrivate::exit()
{
  qDebug() << "exiting now!";
  QCoreApplication::exit ( 0 );
}
// ---------------------------------------------------------------------------------
//private stuff:
// ---------------------------------------------------------------------------------
void Application::ApplicationPrivate::init()
{
  init_storage_backend();
  register_with_session_bus();
}
// ---------------------------------------------------------------------------------
bool Application::ApplicationPrivate::init_storage_backend()
{
  if(dp::sqlite().open_database_connection().has_failed())
  {
    qWarning()<<"unable to initialize persistance backend. exiting now";
    ::exit(1);
  }
  if(dp::sqlite().update_database_schema_if_necessary().has_failed())
  {
    qWarning()<<"unable to initialize the required database schema. exiting now";
    ::exit(1);
  }
  return true;
}
// ---------------------------------------------------------------------------------
void Application::ApplicationPrivate::register_with_session_bus()
{
  qDebug() << "registering at the session bus now...";
  dp::dbus().register_object ( _M_self ).at_session_bus().as ( "/Application" );
}

// ---------------------------------------------------------------------------------
