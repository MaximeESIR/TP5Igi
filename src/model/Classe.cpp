#include <model/Classe.h>
#include <model/Entite.h>

#define NB_ENTITES 3

Classe::Classe(QObject * pParent) : QObject(pParent)
{
	int i;
	for (i=0; i<NB_ENTITES; ++i)
	{
		m_entites << new Entite(QString("Entite %1").arg(i),this) ;
	}
}

Classe::~Classe()
{
}

QList<Entite*> Classe::entites() const
{
	return m_entites;
}
