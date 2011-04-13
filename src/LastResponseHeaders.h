#include "Command.h"

class WebPage;

class LastResponseHeaders : public Command {
  Q_OBJECT

  public:
    LastResponseHeaders(WebPage *page, QObject *parent = 0);
    virtual void start(QStringList &arguments);
};

