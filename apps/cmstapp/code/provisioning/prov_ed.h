/**************************** prov_ed.h ***************************

Code to manage the Provisioning Editor dialog.

Copyright (C) 2013-2014
by: Andrew J. Bibb
License: MIT 

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"),to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions: 

The above copyright notice and this permission notice shall be included 
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
***********************************************************************/ 

# ifndef PROVISIONING_EDITOR_H
# define PROVISIONING_EDITOR_H

# include <QDialog>
# include <QWhatsThis>
# include <QMenuBar>
# include <QMenu>
# include <QStatusBar>
# include <QActionGroup>
# include <QButtonGroup>
# include <QLabel>
# include <QLineEdit>
# include <QDialogButtonBox>
# include <QString>
# include <QStringList>

# include "ui_provisioning_editor.h"
# include "./code/control_box/controlbox.h"
//
// Class for an QInputDialog knockoff with validator
class ValidatingDialog : public QDialog
{
  Q_OBJECT
  
  public:
    ValidatingDialog(QWidget*);
    inline void setLabel(const QString& s) {label->setText(s);}
    inline QString getText() {return lineedit->text();}
    inline void clear() {lineedit->clear();}
    void setValidator(const int&, bool plural = false);
    inline bool isPlural() {return plural;}
  
  private:
    // members
    QLabel* label;
    QLineEdit* lineedit;
    QDialogButtonBox* buttonbox;
    bool plural;
};


//  The class to control the properties editor UI based on a QDialog
class ProvisioningEditor : public QDialog
{
  Q_OBJECT

  public:
    ProvisioningEditor(QWidget*);
    
  private:  
  // members
    Ui::Provisioning ui;
    int i_sel;
    QMenuBar* menubar;
    QMenu* menu_global;
    QMenu* menu_service;
    QMenu* menu_wifi;
    QMenu* menu_template;
    QActionGroup* group_template;
    QActionGroup* group_freeform;
    QActionGroup* group_combobox;
    QActionGroup* group_validated;
    QActionGroup* group_selectfile;
    QActionGroup* group_ipv4;
    QActionGroup* group_ipv6;
    QButtonGroup* bg01;
    QStatusBar* statusbar;
    int statustimeout;
    
  private slots:
    void inputSelectFile(QAction*);
    void inputValidated(QAction*);
    void inputComboBox(QAction*);
    void inputFreeForm(QAction*);
    void ipv4Triggered(QAction*);
    void ipv6Triggered(QAction*);
    void templateTriggered(QAction*);
    void showWhatsThis();
    void resetPage();
    void requestFileList(QAbstractButton*);
    void processFileList(const QStringList&);
    void seedTextEdit(const QString&);
    void deleteCompleted(bool);
    void writeCompleted(quint64);
    void callbackErrorHandler(QDBusError);
        
  public:
    inline void setWhatsThisIcon(QIcon icon) {ui.toolButton_whatsthis->setIcon(icon);}
};


#endif
