#include <ihm/MainWindow.h>

MainWindow::MainWindow(QWidget * pParent, Qt::WindowFlags f) : 
	QMainWindow(pParent,f)
	, vm(Variable(QString("jesuisunevariable")))
{
	ui.setupUi(this);
	ui.tableView->setModel(&vm);
	ui.entityView->setModel(&entitesTreeModel);  // Associez EntitesTreeModel à QTreeView
	///ATTENTION chui pas sur du truc hein
}

MainWindow::~MainWindow()
{
}
