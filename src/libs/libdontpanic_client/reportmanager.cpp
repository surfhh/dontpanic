/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "libdontpanic_client/reportmanager.h"
#include <QDBusConnection>
#include <remote_reportmanager.h>
namespace dp
{
  // ---------------------------------------------------------------------------------
  namespace client
  {
    // ---------------------------------------------------------------------------------
    ReportManager::ReportManager ( QObject *parent )
        : QObject ( parent )
        ,_M_remote(0)
    {
      
    }
    // ---------------------------------------------------------------------------------
    ReportManager::~ReportManager ( ){}
    // ---------------------------------------------------------------------------------
    org::dontpanic::ReportManager* ReportManager::remote()
    {
      if(_M_remote == 0)
      {
        _M_remote = new org::dontpanic::ReportManager
        ( "org.dontpanic", "/ReportManager", QDBusConnection::sessionBus(), this );
        if(!_M_remote->isValid())
        {
          kWarning()<<_M_remote->lastError();
        }
//         connect(_M_remote, SIGNAL( stored ( dp::Task ) ), this, SLOT( on_stored ( dp::Task ) ));
//         connect(_M_remote, SIGNAL(removed(dp::Task)), this, SLOT(on_removed(dp::Task)));
//         connect(_M_remote, SIGNAL(error(QString const&)), this, SIGNAL(error(QString)));
      }
      return _M_remote;
    }
    // ---------------------------------------------------------------------------------
  }//client
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------

