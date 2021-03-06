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

#include "kactiontemplateslistmodel.h"
#include "context.h"
#include <KLocalizedString>
#include <KDebug>
#include <KIconLoader>
#include <QPixmap>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  namespace core
  {
    // ---------------------------------------------------------------------------------
    namespace detail
    {
      // ---------------------------------------------------------------------------------
      enum{NAME, DATE};
      // ---------------------------------------------------------------------------------
      KActionTemplatesListModel::KActionTemplatesListModel ( QObject *parent )
          : QAbstractListModel ( parent )
          , _M_icon_loader(new KIconLoader("", 0, this))
      {
        init_header_data();
        subscribe_to_action_template_manager_signals();
        init_action_templates_list();	
      }
      // ---------------------------------------------------------------------------------
      QVariant KActionTemplatesListModel::data ( const QModelIndex& index, int role ) const
      {
        if(!index.isValid())return QVariant();
        ActionTemplate const& p = _M_action_templates.at(index.row());
        switch(role)
        {
          case Qt::DisplayRole: return p.name();
          case Qt::DecorationRole: return _M_icon_loader->loadIcon(p.icon(), KIconLoader::NoGroup);
          default: return QVariant();
        }
        
      }
      // ---------------------------------------------------------------------------------
      QVariant KActionTemplatesListModel::headerData ( int section, Qt::Orientation orientation, int role ) const
      {
        if ( role != Qt::DisplayRole )
        {          
          return QVariant();
        }
        if ( orientation != Qt::Horizontal )
        {
          return QVariant();
        }
        return _M_headers.at ( section );
      }
      // ---------------------------------------------------------------------------------
      int KActionTemplatesListModel::rowCount ( const QModelIndex& parent ) const
      {
        return _M_action_templates.size();
      }
      // ---------------------------------------------------------------------------------
      ActionTemplate KActionTemplatesListModel::at(QModelIndex const& index)
      {
        if(!index.isValid())
        {
          return NullActionTemplate();          
        }
        return _M_action_templates.at(index.row());
      }
      // ---------------------------------------------------------------------------------
      // private stuff:
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::init_header_data()
      {
        _M_headers << i18n ( "Name" )
        << i18n ( "Creation Date" );
      }
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::init_action_templates_list()
      {
        _M_action_templates = context()->actionTemplateManager()->allActionTemplates();
      }
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::subscribe_to_action_template_manager_signals()
      {
	client::ActionTemplateManager * pm = context()->actionTemplateManager();
        connect(pm, SIGNAL(stored(dp::ActionTemplate)), this, SLOT(stored(dp::ActionTemplate const&)));
        connect(pm, SIGNAL(removed(dp::ActionTemplate)), this, SLOT(removed(dp::ActionTemplate const&)));
      }
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::stored(dp::ActionTemplate const&p)
      {
        qWarning()<<__FUNCTION__;
        if(is_already_known(p))
        {
          updated(p);
        }
        else
        {
          added(p);
        }
      }
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::removed(dp::ActionTemplate const&p)
      {
        int i = _M_action_templates.indexOf(p);
        beginRemoveRows(QModelIndex(), i, i);
        _M_action_templates.removeAt(i);
        endRemoveRows();
      }
      // ---------------------------------------------------------------------------------
      bool KActionTemplatesListModel::is_already_known(dp::ActionTemplate const&p) const
      {
        return (_M_action_templates.indexOf(p)!=-1);
      }	  
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::added(dp::ActionTemplate const&p)
      {
        int index = _M_action_templates.size();
        beginInsertRows(QModelIndex(), index, index);
        _M_action_templates.append(p);
        endInsertRows();
      }	  
      // ---------------------------------------------------------------------------------
      void KActionTemplatesListModel::updated(dp::ActionTemplate const&p)
      {
        int row = _M_action_templates.indexOf(p);
        kDebug()<<"updating action template ["<<row<<"]";
        QModelIndex const& i = index(row);
        _M_action_templates.replace(row, p);
        emit dataChanged(i, i);
      }	  
      // ---------------------------------------------------------------------------------
    }//detail
    // ---------------------------------------------------------------------------------
  }//core
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
