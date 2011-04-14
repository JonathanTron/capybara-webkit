#include "Command.h"

class WebPage;

class StatusCode : public Command {
  Q_OBJECT

  public:
    StatusCode(WebPage *page, QObject *parent = 0);
    virtual void start(QStringList &arguments);
};

