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

#include "kdayview.h"
#include <ui_kdayview.h>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  namespace core
  {
    // ---------------------------------------------------------------------------------
    KDayView::KDayView ( QWidget *parent )
        : QWidget ( parent )
        , _M_ui ( new Ui::KDayView ( ) )
    {
      _M_ui->setupUi ( this );
      _M_ui->main_splitter->setSizes ( QList<int>() << 100 << 500 );
      setup_actions();
      on_selected_day_changed();
    }
    // ---------------------------------------------------------------------------------
    KDayView::~KDayView()
    {
      delete _M_ui;
    }
    // ---------------------------------------------------------------------------------
    void KDayView::setup_actions()
    {
      connect(_M_ui->today_button, SIGNAL(pressed()), this, SLOT(on_today_pressed()));
      connect(_M_ui->calendar, SIGNAL(selectionChanged()), this, SLOT(on_selected_day_changed()));
    }
    // ---------------------------------------------------------------------------------
    void KDayView::on_selected_day_changed()
    {
      _M_ui->action_table->load_actions_of(_M_ui->calendar->selectedDate());
    }
    // ---------------------------------------------------------------------------------
    void KDayView::on_today_pressed()
    {
      _M_ui->calendar->setSelectedDate(QDate::currentDate());
    }
    // ---------------------------------------------------------------------------------
  }//core
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
