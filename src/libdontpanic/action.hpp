#ifndef DONTPANICLIB_ACTION_HPP
#define DONTPANICLIB_ACTION_HPP
// ---------------------------------------------------------------------------------
#include "defines.hpp"
#include "task.hpp"
#include "project.hpp"
#include "collaboration_type.hpp"

//Qt includes
#include <QString>
#include <QTime>
// ---------------------------------------------------------------------------------
namespace dp
{
  // ---------------------------------------------------------------------------------
  class action
  {
      // ---------------------------------------------------------------------------------
    public:
      // ---------------------------------------------------------------------------------
      TYPE ( action );
      // ---------------------------------------------------------------------------------
    private:
      // ---------------------------------------------------------------------------------
      uint64_t _M_id;
      // ---------------------------------------------------------------------------------
      task::ptr _M_task;
      // ---------------------------------------------------------------------------------
      project::ptr _M_project;
      // ---------------------------------------------------------------------------------
      collaboration_type::ptr _M_teamwork;
      // ---------------------------------------------------------------------------------
      //TODO person list
      // ---------------------------------------------------------------------------------
      QString _M_name;
      // ---------------------------------------------------------------------------------
      QString _M_comment;
      // ---------------------------------------------------------------------------------
      QTime _M_start;
      // ---------------------------------------------------------------------------------
      QTime _M_end;
      // ---------------------------------------------------------------------------------
      bool _M_reviewed;
      // ---------------------------------------------------------------------------------
      bool _M_billed;
      // ---------------------------------------------------------------------------------
  };//action
  // ---------------------------------------------------------------------------------
  DECLARE_SMARTPOINTERS ( action );
  // ---------------------------------------------------------------------------------
}//dp
// ---------------------------------------------------------------------------------
#endif //DONTPANICLIB_ACTION_HPP
