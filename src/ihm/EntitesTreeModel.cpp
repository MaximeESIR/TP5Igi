#include <ihm/EntitesTreeModel.h>
//#include <ihm/EntiteItem.h>
//#include <ihm/VariableItem.h>

#include <model/Entite.h>
#include <model/Variable.h>

#include <QMimeData>
#include <QSet>

EntitesTreeModel::EntitesTreeModel(QList<Entite*> entites, QObject * pParent) : QStandardItemModel(pParent)
{
	m_entites = entites;
	refresh();
}

EntitesTreeModel::~EntitesTreeModel()
{
}

void EntitesTreeModel::refresh()
{
	QList<Entite*>::const_iterator it;

	//parcours des entites
	for (it=m_entites.begin(); it!=m_entites.end(); ++it)
	{
		//on cree (si besoin) l'item pour l'entite
		creerItems(*it);
	}
}

void EntitesTreeModel::creerItems(Entite * pEntite)
{
	QStandardItem * pItemParent, * pItemEntite, * pItemVariable;
	QList<Variable*> variables;
	QList<Variable*>::const_iterator itV;
	int i;

	//recup de l'item racine
	pItemParent = invisibleRootItem();

	//TODO recherche item ayant le nom de l'entite a ajouter
	//=> parcours de pItemParent->child(...) afin de trouver pItemEntite ayant le même texte que l'entité en paramètre
	QModelIndex entiteIndex = indexFromItem(pItemParent);
    for (int row = 0; row < pItemParent->rowCount(entiteIndex); ++row) {
        QModelIndex childIndex = entiteIndex.child(row, 0);
        if (data(childIndex, Qt::DisplayRole).toString() == pEntite->nom()) {
            pItemEntite = itemFromIndex(childIndex);
            break;
        }
    } //ajout
	//creation item pour l'entite (si besoin)
	if (pItemEntite == NULL)
	{
		pItemEntite = new QStandardItem(pEntite->nom());
        pItemParent->appendRow(pItemEntite);	}

	//pas d'items sous l'item associe a l'entite ?
	if (pItemEntite->rowCount() == 0)
    {
        // création pour chaque variable de l'entité d'un VariableItem
        variables = pEntite->getVariables(); // Assurez-vous d'avoir une méthode getVariables() dans la classe Entite

        for (itV = variables.begin(), i = 0; itV != variables.end(); ++itV, ++i)
        {
            // Créez un VariableItem (ou QStandardItem) pour chaque variable
            pItemVariable = new QStandardItem((*itV)->nom()); // Assurez-vous d'avoir une méthode nom() dans la classe Variable
            pItemEntite->appendRow(pItemVariable);
        }
    }
}
