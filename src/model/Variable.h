#ifndef VARIABLE_H
#define VARIABLE_H

#include <QMetaType>
#include <QObject>

class Variable : public QObject
{
	Q_OBJECT
public:

	Variable(QString nom, QObject * pParent = NULL);
	virtual ~Variable();
	QString nom() const;
	QList<double> pasDeTemps() const;
	QList<double> temperature() const;
	QList<double> pression() const;
	void setPasDeTemps(int i, double val);
	void setTemperature(int i, double val);
	void setPression(int i, double val);

private:

	QList<double> m_pasDeTemps;
	QList<double> m_temperature;
	QList<double> m_pression;
	QString m_nom;
};

Q_DECLARE_METATYPE(Variable*)

#endif
