/*
 * dontpanic.cpp
 *
 * Copyright (C) 2009 Frank Habel <frank@bugplasma.de>
 */
#include "dontpanik.hpp"
#include "dontpanik.moc"

#include <kaction.h>
#include <kactioncollection.h>
#include <kconfig.h>
#include <kedittoolbar.h>
#include <kfiledialog.h>
#include <kshortcutsdialog.h>
#include <klibloader.h>
#include <kmessagebox.h>
#include <kstandardaction.h>
#include <kstatusbar.h>
#include <kurl.h>
#include <klocale.h>

#include <QApplication>
#include <QString>

DontPanik::DontPanik()
    : KParts::MainWindow( )
{
  // set the shell's ui resource file
  setXMLFile ( "dontpanik_shell.rc" );

  // then, setup our actions
  setupActions();

  // this routine will find and load our Part.  it finds the Part by
  // name which is a bad idea usually.. but it's alright in this
  // case since our Part is made for this Shell
  KLibFactory *factory = KLibLoader::self()->factory ( "dontpanikpart" );
  if ( factory )
  {
    // now that the Part is loaded, we cast it to a Part to get
    // our hands on it
    _M_part = static_cast<KParts::ReadOnlyPart *> ( factory->create ( this,
              "DontPanikPart" ) );

    if ( _M_part )
    {
      // tell the KParts::MainWindow that this is indeed the main widget
      setCentralWidget ( _M_part->widget() );

      // and integrate the part's GUI with the shell's
      createGUI ( _M_part );
    }
  }
  else
  {
    // if we couldn't find our Part, we exit since the Shell by
    // itself can't do anything useful
    KMessageBox::error ( this, i18n ( "Could not find our Part!" ) );
    qApp->quit();
    // we return here, cause qApp->quit() only means "exit the
    // next time we enter the event loop...
    return;
  }

  // apply the saved mainwindow settings, if any, and ask the mainwindow
  // to automatically save settings if changed: window size, toolbar
  // position, icon size, etc.
  setAutoSaveSettings();
}

DontPanik::~DontPanik()
{
}

void DontPanik::setupActions()
{
  KStandardAction::quit ( qApp, SLOT ( closeAllWindows() ), actionCollection() );

  createStandardStatusBarAction();
  setStandardToolBarMenuEnabled ( true );

  KStandardAction::keyBindings ( this, SLOT ( optionsConfigureKeys() ), actionCollection() );
  KStandardAction::configureToolbars ( this, SLOT ( optionsConfigureToolbars() ), actionCollection() );
}

void DontPanik::saveProperties ( KConfigGroup & /*config*/ )
{
  // the 'config' object points to the session managed
  // config file.  anything you write here will be available
  // later when this app is restored
}

void DontPanik::readProperties ( const KConfigGroup & /*config*/ )
{
  // the 'config' object points to the session managed
  // config file.  this function is automatically called whenever
  // the app is being restored.  read in here whatever you wrote
  // in 'saveProperties'
}

void DontPanik::optionsConfigureKeys()
{
  KShortcutsDialog dlg ( KShortcutsEditor::AllActions, KShortcutsEditor::LetterShortcutsDisallowed, this );
  dlg.addCollection ( actionCollection() );
  dlg.addCollection ( _M_part->actionCollection());
  ( void ) dlg.configure ( true );
}

void DontPanik::optionsConfigureToolbars()
{
  // use the standard toolbar editor
  KEditToolBar dlg ( factory() );
  dlg.exec();
}

