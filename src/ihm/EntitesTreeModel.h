#ifndef ENTITESTREEMODEL_H
#define ENTITESTREEMODEL_H
#ifdef _MSC_VER
	#pragma once
#endif

class Entite;
class Variable;

#include <QStandardItemModel>

/**
 * @brief Modele fournissant les donnees aux arbres affichant les moyens de com et les stations
 */
class EntitesTreeModel : public QStandardItemModel
{
	Q_OBJECT

public:

	/**
	 * @brief Constructeur
	 * @param pParent Pointeur sur l'objet parent
	 */
	EntitesTreeModel(QList<Entite*> entites, QObject * pParent = 0);
	/**
	 * @brief Destructeur
	 */ 
	virtual ~EntitesTreeModel();

public slots:

	/**
	 * @brief Slot permettant de remettre a jour le modele
	 */
	void refresh();

protected:

	/**
	 * @brief Cree si besoin l'item associe a l'entite ainsi qu'a ses variables (et les items parents si besoin).
	 * Ne fait rien si l'item existe deja.
	 * @param pEntite Entite pour laquelle on veut creer un item
	 */
	virtual void creerItems(Entite * pEntite);

	QList<Entite*> m_entites;//!<La liste des entites manipulees par le modele
};

#endif

