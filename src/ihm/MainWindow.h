#include "ui_MainWindow.h"

#include <model/Classe.h>
#include "ihm/VariableModel.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget * pParent = NULL, Qt::WindowFlags f = 0);
	virtual ~MainWindow();
private:
	Classe m_classe;
	Ui::MainWindow ui;
	VariableModel vm;
	EntitesTreeModel entitesTreeModel;
};
